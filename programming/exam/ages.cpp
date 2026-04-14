//     int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};
//
//     float avg, sum = 0;
//     int i;
//
//     int length1 = sizeof(ages) / sizeof(ages[0]);
//     for (int age : ages){
//         sum += age;
//     }
//
//     avg = sum / length
//
//     cout << "The results is: " << avg << "\n";
// a. Ubah fungsi loop for diatas menjadi while
// b. Program diatas tidak akan berjalan, sebutkan 2 perubahan yang harus dilakukan agar program dapat berjalan.
// c. Tuliskan hasil dari program diatas setelah berjalan.
#include<iostream>
#include<cstring>
using namespace std;
main(){
    int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};

    float avg, sum = 0;
    int i = 0;

    int length1 = sizeof(ages) / sizeof(ages[0]);
    while (i<length1){
        sum += ages[i];
        i++;
    }


    avg = sum / length1; // b. 1. no semicolon on closing 2. length => length1

    cout << "The results is: " << avg << "\n"; // avg = 40.75
}