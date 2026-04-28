#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

// Recursively find a regular file with the given name starting from 'dir'.
// Returns the relative path without a leading "./" (e.g., "115YL/6EFBDMWOKL/I11GVOQQ8Y").
string find_file(const string& dir, const string& target) {
    DIR* d = opendir(dir.c_str());
    if (!d) return "";
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;
        string full = dir + "/" + ent->d_name;
        struct stat st;
        if (lstat(full.c_str(), &st) == -1) continue;
        if (S_ISDIR(st.st_mode)) {
            string res = find_file(full, target);
            if (!res.empty()) {
                closedir(d);
                return res;
            }
        } else if (S_ISREG(st.st_mode) && ent->d_name == target) {
            closedir(d);
            return full;
        }
    }
    closedir(d);
    return "";
}

// Recursively find a directory with the given name.
string find_dir(const string& dir, const string& target) {
    DIR* d = opendir(dir.c_str());
    if (!d) return "";
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;
        string full = dir + "/" + ent->d_name;
        struct stat st;
        if (lstat(full.c_str(), &st) == -1) continue;
        if (S_ISDIR(st.st_mode)) {
            if (ent->d_name == target) {
                closedir(d);
                return full;  // relative path like "something/JPI040GPV8"
            }
            string res = find_dir(full, target);
            if (!res.empty()) {
                closedir(d);
                return res;
            }
        }
    }
    closedir(d);
    return "";
}

// Delete empty directories recursively, excluding any whose path starts with
// "./My Collection/". Paths are relative to the original working directory.
void delete_empty_dirs(const string& dirpath, const string& relpath) {
    DIR* d = opendir(dirpath.c_str());
    if (!d) return;
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;
        string sub_full = dirpath + "/" + ent->d_name;
        string sub_rel = relpath + "/" + ent->d_name;
        struct stat st;
        if (lstat(sub_full.c_str(), &st) == -1) continue;
        if (S_ISDIR(st.st_mode)) {
            delete_empty_dirs(sub_full, sub_rel);
        }
    }
    closedir(d);

    // Re-open to check if now empty
    d = opendir(dirpath.c_str());
    if (!d) return;
    bool empty = true;
    while ((ent = readdir(d)) != NULL) {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            empty = false;
            break;
        }
    }
    closedir(d);

    // Delete if empty and not inside "My Collection/" subtree
    // (the pattern "./My Collection/*" means path starts with "./My Collection/")
    if (empty) {
        if (relpath.rfind("./My Collection/", 0) != 0) { // does NOT start with that prefix
            rmdir(dirpath.c_str());
        }
    }
}

int main() {
    // 1. Unzip sisop.zip
    pid_t pid = fork();
    if (pid == 0) {
        execlp("unzip", "unzip", "sisop.zip", (char*)NULL);
        perror("unzip failed");
        _exit(1);
    } else {
        wait(NULL);
    }

    // 2. Enter the extracted sisop directory
    chdir("sisop");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));   // absolute path to sisop

    // 3. Find I11GVOQQ8Y, create hard link, remove original
    string file_path = find_file(".", "I11GVOQQ8Y");
    cout << file_path << endl;
    link(file_path.c_str(), "I11GVOQQ8Y");
    unlink(file_path.c_str());

    // 4. Find JPI040GPV8 directory
    string jpi_path = find_dir(".", "JPI040GPV8");
    cout << jpi_path << endl;

    // 5. Create "My Collection"
    mkdir("My Collection", 0755);

    // 6. Create symbolic links for every item inside JPI040GPV8
    DIR* jpi_dir = opendir(jpi_path.c_str());
    if (jpi_dir) {
        struct dirent* entry;
        // jpi_path is something like "some/path/JPI040GPV8" (no leading ./)
        while ((entry = readdir(jpi_dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            // absolute path of the source item
            string src = string(cwd) + "/" + jpi_path + "/" + entry->d_name;
            // absolute path of the symlink in My Collection
            string link = string(cwd) + "/My Collection/" + entry->d_name;
            symlink(src.c_str(), link.c_str());
        }
        closedir(jpi_dir);
    }

    // 7. Delete all empty directories except those under "My Collection"
    delete_empty_dirs(".", ".");

    // 8. Find L3TB91 directory and symlink as "sys"
    string l3_path = find_dir(".", "L3TB91");
    if (!l3_path.empty()) {
        symlink(l3_path.c_str(), "sys");
    }

    // 9. Determine the last file alphabetically (ignoring directories)
    vector<string> files;
    DIR* cur = opendir(".");
    if (cur) {
        struct dirent* e;
        while ((e = readdir(cur)) != NULL) {
            if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)
                continue;
            struct stat st;
            if (stat(e->d_name, &st) == -1) continue; // follow symlinks
            if (!S_ISDIR(st.st_mode)) {  // not a directory (symlinks to dirs are excluded)
                files.push_back(e->d_name);
            }
        }
        closedir(cur);
    }
    sort(files.begin(), files.end());
    string lastfile = files.back();  // the last one alphabetically

    // 10. Save recursive listing into that file (overwriting)
    pid = fork();
    if (pid == 0) {
        int fd = open(lastfile.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) _exit(1);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        execlp("ls", "ls", "-Rl", ".", (char*)NULL);
        perror("ls failed");
        _exit(1);
    } else {
        wait(NULL);
    }

    return 0;
}
