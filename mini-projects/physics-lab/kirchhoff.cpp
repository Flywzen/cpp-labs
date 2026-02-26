#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Fungsi untuk menghitung Kesalahan Relatif (KSR)
double hitungKSR(double teori, double praktek) {
    if (teori == 0) return 0.0;
    return abs((teori - praktek) / teori) * 100.0;
}

int main() {
    char pilihan;
    
    do {
        cout << "======================================================\n";
        cout << "    PHYSICS LAB: KIRCHHOFF'S LAW      \n";
        cout << "    Developed by @rafly.ryy                             \n";
        cout << "======================================================\n\n";

        double R1, R2, R3, V1, V2;

        cout << "[#] INPUT DATA KOMPONEN (TEORI)\n";
        cout << "Masukkan Resistor R1 (Ohm) : "; cin >> R1;
        cout << "Masukkan Resistor R2 (Ohm) : "; cin >> R2;
        cout << "Masukkan Resistor R3 (Ohm) : "; cin >> R3;
        cout << "Masukkan Tegangan V1 (Volt): "; cin >> V1;
        cout << "Masukkan Tegangan V2 (Volt): "; cin >> V2;

        // --- PROSES PERHITUNGAN MATRIKS / SUBSTITUSI 2 LOOP ---
        double D = (R1 * R2) + (R1 * R3) + (R2 * R3);
        
        // Hasil Arus Teori (Hitungan)
        double I1_hit = (V1 * (R2 + R3) - V2 * R3) / D;
        double I2_hit = (V2 * (R1 + R3) - V1 * R3) / D;
        double I3_hit = I1_hit + I2_hit;

        cout << "\n[#] HASIL PERHITUNGAN TEORI\n";
        cout << "I1 (Arus Loop 1)   = " << I1_hit << " A\n";
        cout << "I2 (Arus Loop 2)   = " << I2_hit << " A\n";
        cout << "I3 (Arus Percabangan) = " << I3_hit << " A\n";

        cout << "\n[#] INPUT DATA PENGUKURAN MULTIMETER (PRAKTEK)\n";
        double I1_peng, I2_peng, I3_peng;
        cout << "Masukkan I1 Pengukuran (A) : "; cin >> I1_peng;
        cout << "Masukkan I2 Pengukuran (A) : "; cin >> I2_peng;
        cout << "Masukkan I3 Pengukuran (A) : "; cin >> I3_peng;

        // --- OUTPUT TABEL PERBANDINGAN & KSR ---
        cout << "\n======================================================\n";
        cout << "                TABEL PERBANDINGAN & KSR              \n";
        cout << "======================================================\n";
        
        cout << fixed << setprecision(4);
        cout << "I1 | Teori: " << setw(7) << I1_hit << " A | Ukur: " << setw(7) << I1_peng 
             << " A | KSR: " << hitungKSR(I1_hit, I1_peng) << " %\n";
             
        cout << "I2 | Teori: " << setw(7) << I2_hit << " A | Ukur: " << setw(7) << I2_peng 
             << " A | KSR: " << hitungKSR(I2_hit, I2_peng) << " %\n";
             
        cout << "I3 | Teori: " << setw(7) << I3_hit << " A | Ukur: " << setw(7) << I3_peng 
             << " A | KSR: " << hitungKSR(I3_hit, I3_peng) << " %\n";
             
        cout << "======================================================\n\n";

        // Fitur Ngulang ala Flywzen
        cout << "Ingin menghitung ulang data lain? (y/n): ";
        cin >> pilihan;
        cout << "\n\n";

    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "Terima kasih telah menggunakan kalkulator Kirchhoff ini!\n";
    
    return 0;
}