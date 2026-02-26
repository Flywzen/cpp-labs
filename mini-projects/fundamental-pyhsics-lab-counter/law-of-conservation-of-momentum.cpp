#include <iostream>
#include <cmath>   // Ditambahkan untuk fungsi abs()
#include <cstdlib> // Ditambahkan untuk fungsi system()

// Pengaman library untuk Windows
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void intro() {
    // Pengaman: Perintah COLOR hanya dieksekusi jika dijalankan di Windows
#ifdef _WIN32
    system("COLOR 09"); // 09 itu Light Blue biar lebih terang dan jelas dibaca
#endif
    cout << "==========================================================================" << endl;
    cout << " PROGRAM HUKUM KEKEKALAN MOMENTUM By @rafly.ryy" << endl;
    cout << "==========================================================================" << endl;
}

void momentum() {
    double ma, mb, va, vb, vaksen, vbaksen;
    int pilihan;

    cout << "1. Tumbukan Lenting Sempurna\n2. Tumbukan Tidak Lenting Sama Sekali\nPilih Kasus: "; cin >> pilihan;
    cout << "Massa benda A (kg): "; cin >> ma;
    cout << "Massa benda B (kg): "; cin >> mb;
    cout << "Kecepatan A awal (m/s): "; cin >> va;
    cout << "Kecepatan B awal (m/s): "; cin >> vb;

    if (pilihan == 2) {
        // Rumus: v' = (ma*va + mb*vb) / (ma + mb)
        vaksen = (ma * va + mb * vb) / (ma + mb);
        cout << "\n>> Kecepatan gabungan setelah tumbukan (v'): " << vaksen << " m/s" << endl;
    } else {
        cout << "Input va' (hasil pengamatan): "; cin >> vaksen;
        cout << "Input vb' (hasil pengamatan): "; cin >> vbaksen;
        
        double pAwal = (ma * va) + (mb * vb);
        double pAkhir = (ma * vaksen) + (mb * vbaksen);
        
        cout << "\n>> Momentum Awal  : " << pAwal << " kg.m/s" << endl;
        cout << ">> Momentum Akhir : " << pAkhir << " kg.m/s" << endl;
        
        // Pengaman pembagian dengan nol (mencegah error NaN)
        if (pAwal != 0) {
            cout << ">> Persen Error   : " << abs((pAwal - pAkhir) / pAwal) * 100 << " %" << endl;
        } else {
            cout << ">> Persen Error   : (Tidak dapat dihitung karena Momentum Awal = 0)" << endl;
        }
    }
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
        momentum(); 
        
        // Pertanyaan Looping
        cout << "==========================================================================" << endl;
        cout << "Ingin menghitung ulang data tumbukan lain? (y/n): ";
        cin >> ulang;
        
    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram selesai. Data siap dipindahkan ke laporan!" << endl;

    // Pengaman pause cross-platform
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan Enter untuk keluar...";
    cin.ignore(); cin.get();
#endif
    return 0;
}