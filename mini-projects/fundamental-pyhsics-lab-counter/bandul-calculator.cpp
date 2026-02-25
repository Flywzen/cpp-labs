#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

void intro() {
    system("COLOR B");
    cout << "========================================================================================" << endl;
    cout << " PROGRAM PERHITUNGAN BANDUL MATEMATIS (MODUL 4) By @flywzen" << endl;
    cout << "========================================================================================" << endl;
    cout << "\n[!] INFO: Gunakan satuan METER untuk panjang tali dan DETIK untuk waktu." << endl;
    cout << "________________________________________________________________________________________\n" << endl;
}

void hitungGravitasi() {
    double n = 10.0; // Jumlah ayunan tetap
    double t_total, L, T, T2, g_p, ksr;
    const double g_t = 9.80665; // Gravitasi teori standar

    cout << "[#] STEP 1: Mencari Periode (T)" << endl;
    cout << "Masukkan total waktu (s) untuk " << n << " ayunan: "; cin >> t_total;
    T = t_total / n;
    T2 = T * T;
    cout << ">> Nilai T  : " << T << " s" << endl;
    cout << ">> Nilai T^2: " << T2 << " s^2" << endl;

    cout << "\n[#] STEP 2: Mencari Gravitasi Percobaan (g)" << endl;
    cout << "Masukkan Panjang Tali (m): "; cin >> L;
    
    // Rumus: g = (4 * pi^2 * L) / T^2
    g_p = (4 * M_PI * M_PI * L) / T2;
    cout << ">> Nilai g Percobaan: " << g_p << " m/s^2" << endl;

    cout << "\n[#] STEP 3: Analisis KSR" << endl;
    ksr = abs((g_t - g_p) / g_t) * 100;
    cout << ">> Nilai KSR       : " << ksr << " %" << endl;
    cout << ">> Tingkat Presisi : " << 100 - ksr << " %" << endl;
}

int main() {
    intro();
    hitungGravitasi();
    
    cout << "\n________________________________________________________________________________________" << endl;
    cout << "Perhitungan selesai. Jangan lupa catat di logbook praktikum!" << endl;
    system("pause");
    return 0;
}