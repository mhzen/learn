#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

// Mencari path file atau directory secara rekursif
// type 1 untuk file, type 2 untuk directory
// base_path adalah path awal
// target_name adalah nama file atau directory yang dicari
string find_recursive(const string& base_path, const string& target_name, int type) {
    DIR* dir = opendir(base_path.c_str());
    if (!dir) return "";

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        string name = entry->d_name;
        if (name == "." || name == "..") continue;

        string full_path = base_path + "/" + name;
        struct stat st;
        lstat(full_path.c_str(), &st);

        if ((type == 1 && S_ISREG(st.st_mode) && name == target_name) ||
            (type == 2 && S_ISDIR(st.st_mode) && name == target_name)) {
            closedir(dir);
            return full_path;
        }

        if (S_ISDIR(st.st_mode)) {
            string found = find_recursive(full_path, target_name, type);
            if (!found.empty()) {
                closedir(dir);
                return found;
            }
        }
    }
    closedir(dir);
    return "";
}

// Hapus directory kosong secara rekursif
void delete_empty_dirs(const string& path) {
    DIR* dir = opendir(path.c_str());
    if (!dir) return;

    struct dirent* entry;
    bool has_content = false;
    while ((entry = readdir(dir)) != nullptr) {
        string name = entry->d_name;
        if (name == "." || name == "..") continue;

        has_content = true;
        string full_path = path + "/" + name;
        struct stat st;
        lstat(full_path.c_str(), &st);

        if (S_ISDIR(st.st_mode)) {
            delete_empty_dirs(full_path);
        }
    }
    closedir(dir);

    // Jika bukan root dan tidak ditemukan (atau dihapus semua)
    if (path != ".") rmdir(path.c_str());
}

int main() {
    // 1. unzip sisop.zip
    system("unzip -q sisop.zip"); 
    chdir("sisop");

    // 2. I11GVOQQ8Y=$(find . -type f -name I11GVOQQ8Y)
    string i11_path = find_recursive(".", "I11GVOQQ8Y", 1);
    cout << i11_path << endl;

    // 3. ln $I11GVOQQ8Y ./I11GVOQQ8Y && rm $I11GVOQQ8Y
    if (!i11_path.empty()) {
        link(i11_path.c_str(), "./I11GVOQQ8Y"); // Hard link
        unlink(i11_path.c_str());               // Remove original
    }

    // 4. JPI040GPV8=$(find . -name "JPI040GPV8" -type d)
    string jpi_path = find_recursive(".", "JPI040GPV8", 2);
    cout << jpi_path << endl;

    // 5. mkdir -p "My Collection"
    mkdir("My Collection", 0755);

    // 6. for item in $JPI040GPV8/*; do ln -s ...
    if (!jpi_path.empty()) {
        DIR* dir = opendir(jpi_path.c_str());
        struct dirent* entry;
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));

        while ((entry = readdir(dir)) != nullptr) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            
            string src = string(cwd) + "/" + jpi_path + "/" + entry->d_name;
            string dest = string(cwd) + "/My Collection/" + entry->d_name;
            symlink(src.c_str(), dest.c_str());
        }
        closedir(dir);
    }

    // 7. find . -type d -empty -delete
    delete_empty_dirs(".");

    // 8. L3TB91=$(find . -type d -name L3TB91) && ln -s $L3TB91 ./sys
    string l3t_path = find_recursive(".", "L3TB91", 2);
    if (!l3t_path.empty()) {
        symlink(l3t_path.c_str(), "./sys");
    }

    // 9. ls -p | grep -v / | sort | tail -n 1
    vector<string> files;
    DIR* dr = opendir(".");
    struct dirent* en;
    while ((en = readdir(dr)) != nullptr) {
        struct stat st;
        lstat(en->d_name, &st);
        if (S_ISREG(st.st_mode)) {
            files.push_back(en->d_name);
        }
    }
    closedir(dr);
    sort(files.begin(), files.end());
    string last_file = files.back();

    // 10. ls -Rl . > $LASTFILE
    string cmd = "ls -Rl . > " + last_file;
    system(cmd.c_str());

    return 0;
}