#include <iostream>

using namespace std;

main() {
    double first, second, third, final;

    cout << "Masukkan Bilangan Pertama: ";
    cin >> first;
    cout << "Masukkan Bilangan Kedua: ";
    cin >> second;
    cout << "Masukkan Bilangan Ketiga: ";
    cin >> third;

    final = (first + second + third) / 3;
    cout << "Rata-rata: ";
    printf("%.2f\n", final);
}