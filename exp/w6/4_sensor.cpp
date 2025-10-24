#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct sensor
{
    int time;    // format HHMMSS, contoh: 153010 untuk 15:30:10
    int lab;     // 1, 2, dsb -> ditampilkan sebagai "lab 1/2/3"
    double temp; // suhu (C)
    double hum;  // kelembapan (%RH)
    double co2;  // ppm
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    int max = n;
    sensor sns[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> sns[i].lab >> sns[i].time >> sns[i].temp >> sns[i].hum >> sns[i].co2;
    }
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; ++i)
    {
        string nyaman = ((sns[i].temp >= 24 && sns[i].temp <= 30) && (sns[i].hum >= 40 && sns[i].hum <= 60)) ? "Nyaman" : "Tidak";
        cout << sns[i].time << " | lab " << sns[i].lab << " | " << sns[i].temp << " | " << sns[i].hum << " | " << nyaman << endl;
    }
    for (int i = 0; i < n; ++i)
    {
        if (sns[i].co2 > 1000)
        {
            int h = sns[i].time / 10000;
            int m = (sns[i].time / 100) % 100;
            int s = sns[i].time % 100;
            cout << h << ":" << m << ":" << s << " di lab " << sns[i].lab << " bahaya, kadar CO2 melebihi ambang batas aman " << endl;
        }
    }
}