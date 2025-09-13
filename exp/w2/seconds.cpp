#include <iostream>

using namespace std;

main(){
    int totalSeconds, hours, minutesRemainder, minutes, seconds;

    cout << "Masukkan Total Detik: ";
    cin >> totalSeconds;

    hours = totalSeconds / 3600;
    minutesRemainder = totalSeconds % 3600;
    minutes = minutesRemainder / 60;
    seconds = minutesRemainder % 60;

    cout << "Waktu: " << hours << " jam, " << minutes << " menit, " << seconds << " detik" << endl;
}