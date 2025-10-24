#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct sensor
{
    int time;    // HHMMSS
    int lab;     // 1/2/3/...
    double temp; // °C
    double hum;  // %RH
    double co2;  // ppm
};

int main()
{
    ios::sync_with_stdio(false); // https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
    cin.tie(nullptr);

    // Ambang batas (semua lokal, bukan global)
    const double TMIN = 24.0;
    const double TMAX = 30.0;
    const double HMIN = 40.0;
    const double HMAX = 60.0;
    const double CO2_TH = 1000.0;

    int N;
    if (!(cin >> N))
        return 0;

    for (int i = 0; i < N; ++i)
    {
        sensor s{};
        cin >> s.lab >> s.time >> s.temp >> s.hum >> s.co2;

        // Klasifikasi kenyamanan
        bool nyaman = (s.temp >= TMIN && s.temp <= TMAX) &&
                      (s.hum >= HMIN && s.hum <= HMAX);

        // Cetak: HHMMSS | lab X | temp | hum | status
        // HHMMSS 6 digit dengan leading zero bila perlu
        cout << setfill('0') << setw(6) << s.time;
        cout << " | lab " << s.lab
             << " | " << fixed << setprecision(2) << s.temp
             << " | " << fixed << setprecision(2) << s.hum
             << " | " << (nyaman ? "Nyaman" : "Tidak") << "\n";

        // Deteksi bahaya CO2
        if (s.co2 > CO2_TH)
        {
            int hh = s.time / 10000;
            int mm = (s.time / 100) % 100;
            int ss = s.time % 100;

            cout << setfill('0') << setw(2) << hh << ":"
                 << setw(2) << mm << ":"
                 << setw(2) << ss
                 << " di lab " << s.lab
                 << " bahaya, kadar CO2 melebihi ambang batas aman\n";
        }
    }
    return 0;
}
