#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

void intro() {
    system("COLOR 3");
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
    do {
        cout << "1. Bola Pejal (2/5 mr^2)\n2. Silinder Pejal (1/2 mr^2)\n3. Piringan Pejal (1/4 mr^2 + 1/12 ml^2)\n4. Kerucut Pejal (3/10 mr^2)\nx. Selesai\nPilihan: ";
        cin >> pilihan;
        
        if(pilihan == 'x') break;

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
            default: continue;
        }
        cout << ">> Nilai I-Teori: " << result << " kg.m^2\n" << endl;
    } while (pilihan != 'x');
}

int main() {
    intro();
    
    cout << "- Mencari x rata-rata data awal" << endl;
    double xBar = hitungRataRata(5);
    cout << "Nilai x rata-rata: " << xBar << "\n" << endl;

    // ... (Fungsi lain bisa dipanggil di sini)
    
    ITeori();

    cout << "\nAnalisis selesai. Data siap dipindahkan ke laporan!" << endl;
    system("pause");
    return 0;
}