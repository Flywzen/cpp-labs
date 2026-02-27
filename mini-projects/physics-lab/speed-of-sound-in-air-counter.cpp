#include <iostream>
#include <cmath>
#include <cstdlib>

// Pengaman library untuk Windows
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void intro() {
    // Pengaman warna khusus Windows
#ifdef _WIN32
    system("COLOR 0E"); // Warna Light Yellow (E) biar lebih cerah dari Kuning biasa (6)
#endif
    cout << "==========================================================================" << endl;
    cout << " PROGRAM KECEPATAN BUNYI DI UDARA (RESONANSI) By @rafly.ryy" << endl;
    cout << "==========================================================================" << endl;
    cout << "\n[!] INFO: Pastikan panjang kolom udara (L) menggunakan satuan METER (m)." << endl;
    cout << "__________________________________________________________________________\n" << endl;
}

void hitungBunyi() {
    double f, L, lambda, v_p;
    const double v_t = 340.0; // Kecepatan bunyi standar pada suhu ruang (m/s)
    int n;
    
    cout << "[#] INPUT DATA PENGAMATAN" << endl;
    cout << "Frekuensi Garpu Tala (Hz)      : "; cin >> f;
    cout << "Resonansi ke- (1, 2, atau 3)   : "; cin >> n;
    cout << "Panjang kolom udara L (m)      : "; cin >> L;

    // Validasi input resonansi
    if (n < 1 || n > 3) {
        cout << "\n[!] ERROR: Program ini hanya mendukung hitungan resonansi ke-1, 2, atau 3." << endl;
        return; // Menghentikan fungsi dan kembali ke loop utama
    }

    // Menghitung Lambda berdasarkan titik resonansi
    if (n == 1) lambda = 4.0 * L;
    else if (n == 2) lambda = (4.0 / 3.0) * L;
    else lambda = (4.0 / 5.0) * L;

    // Menghitung kecepatan bunyi percobaan (v = lambda * f)
    v_p = f * lambda;

    cout << "\n[#] HASIL PERHITUNGAN" << endl;
    cout << ">> Panjang Gelombang (lambda)  : " << lambda << " m" << endl;
    cout << ">> Cepat Rambat Bunyi (v_perc) : " << v_p << " m/s" << endl;
    cout << ">> Cepat Rambat Bunyi (v_teori): " << v_t << " m/s" << endl;
    cout << ">> Kesalahan Relatif (Deviasi) : " << abs((v_t - v_p) / v_t) * 100.0 << " %" << endl;
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
        hitungBunyi(); 

        // Pertanyaan Looping
        cout << "\n==========================================================================" << endl;
        cout << "Ingin menghitung ulang data resonansi lain? (y/n): ";
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