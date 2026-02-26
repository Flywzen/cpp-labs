#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

// Tambahan library untuk deteksi OS Windows
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void intro() {
    // Pengaman: Perintah COLOR hanya dieksekusi jika dijalankan di Windows
#ifdef _WIN32
    system("COLOR 03"); // Background hitam, teks cyan/aqua
#endif
    cout << "========================================================================================" << endl;
    cout << " PROGRAM PERHITUNGAN MOMEN INERSIA By @rafly.ryy" << endl;
    cout << "========================================================================================" << endl;
    cout << "\n[!] Gunakan titik (.) untuk desimal." << endl;
    cout << "________________________________________________________________________________________\n" << endl;
}

// Fungsi pembantu untuk input rata-rata agar tidak repetitif
double hitungRataRata(int n) {
    double total = 0, temp;
    for(int i = 1; i <= n; i++) {
        cout << "Masukkan nilai x" << i << " : ";
        cin >> temp;
        total += temp;
    }
    return total / n;
}

void ITeori() {
    double m, r, t, result;
    char pilihan;
    cout << "\n--- [ Tabel 5: Perhitungan I-Teori ] ---" << endl;
    
    // Sub-loop untuk memilih bangun ruang (Kode aslimu sudah sangat bagus!)
    do {
        cout << "1. Bola Pejal (2/5 mr^2)\n2. Silinder Pejal (1/2 mr^2)\n3. Piringan Pejal (1/4 mr^2 + 1/12 ml^2)\n4. Kerucut Pejal (3/10 mr^2)\nx. Selesai\nPilihan: ";
        cin >> pilihan;
        
        if(pilihan == 'x' || pilihan == 'X') break;

        cout << "Masukkan massa (kg): "; cin >> m;
        cout << "Masukkan jari-jari (m): "; cin >> r;

        switch(pilihan) {
            case '1': result = 0.4 * m * r * r; break;
            case '2': result = 0.5 * m * r * r; break;
            case '3': 
                cout << "Masukkan tinggi/panjang: "; cin >> t;
                result = (0.25 * m * r * r) + ( (1.0/12.0) * m * t * t); 
                break;
            case '4': result = 0.3 * m * r * r; break;
            default: 
                cout << "Pilihan tidak valid, silakan coba lagi.\n" << endl;
                continue;
        }
        cout << ">> Nilai I-Teori: " << result << " kg.m^2\n" << endl;
    } while (pilihan != 'x' && pilihan != 'X');
}

int main() {
    char ulang;

    // MASTER LOOP: Mengulang keseluruhan program
    do {
        // Fitur Auto-Clear Screen
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        intro();
        
        cout << "- Mencari x rata-rata data awal" << endl;
        double xBar = hitungRataRata(5);
        cout << "Nilai x rata-rata: " << xBar << "\n" << endl;

        // Panggil fungsi momen inersia
        ITeori();

        // Pertanyaan untuk mengulang seluruh program dari awal
        cout << "========================================================================================" << endl;
        cout << "Ingin mengulang seluruh program perhitungan Momen Inersia? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nAnalisis selesai. Data siap dipindahkan ke laporan!" << endl;
    
    // Pengaman pause cross-platform
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan Enter untuk keluar...";
    cin.ignore(); cin.get();
#endif
    
    return 0;
}