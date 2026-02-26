#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

// Pengaman library untuk OS Windows
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void intro() {
    // Pengaman warna khusus Windows
#ifdef _WIN32
    system("COLOR 0D"); // Warna Light Magenta (D) biar ada efek "Laser"
#endif
    cout << "==========================================================================" << endl;
    cout << " PROGRAM PERHITUNGAN DIFRAKSI CAHAYA (He-Ne Laser) By @rafly.ryy" << endl;
    cout << "==========================================================================" << endl;
    cout << "\n[!] INFO: Pastikan semua input jarak menggunakan satuan METER (m)." << endl;
    cout << "__________________________________________________________________________\n" << endl;
}

void difraksi() {
    double d, y, L, lambda_perc;
    const double lambda_teori = 632e-9; // Wavelength Laser He-Ne standar
    int n;

    cout << "[#] INPUT DATA PENGAMATAN" << endl;
    cout << "Orde terang ke (n)             : "; cin >> n;
    cout << "Jarak antar celah d (m)        : "; cin >> d;
    cout << "Jarak layar L (m)              : "; cin >> L;
    cout << "Jarak terang pusat ke-n y (m)  : "; cin >> y;

    // Rumus: lambda = (d * y) / (n * L)
    // Pengaman jika n atau L diinput 0
    if (n == 0 || L == 0) {
        cout << "\n[!] ERROR: Orde (n) dan Jarak Layar (L) tidak boleh nol!" << endl;
        return;
    }

    lambda_perc = (d * y) / (n * L);

    // Menampilkan hasil dalam notasi ilmiah (scientific) secara otomatis
    cout << "\n[#] HASIL PERHITUNGAN" << endl;
    cout << ">> Panjang Gelombang (Teori)   : " << lambda_teori << " m" << endl;
    cout << ">> Panjang Gelombang Percobaan : " << lambda_perc << " m" << endl;
    
    // Hitung KSR
    cout << ">> Kesalahan Relatif (KSR)     : " << abs((lambda_perc - lambda_teori) / lambda_teori) * 100 << " %" << endl;
}

int main() {
    char ulang;

    // MASTER LOOP
    do {
        // Auto-Clear Screen
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        intro();
        difraksi();

        // Pertanyaan Looping
        cout << "\n==========================================================================" << endl;
        cout << "Ingin menghitung ulang data orde terang lain? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram selesai. Data siap dipindahkan ke laporan!" << endl;

    // Pengaman pause cross-platform
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan Enter untuk keluar...";
    cin.ignore(); cin.ignore(); // Panggil 2x untuk menangkap sisa 'Enter' dari cin sebelumnya
#endif
    return 0;
}