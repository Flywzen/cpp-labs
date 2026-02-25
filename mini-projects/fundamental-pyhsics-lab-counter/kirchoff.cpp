#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void intro() {
#ifdef _WIN32
    system("COLOR 4"); // Merah
#endif
    cout << "--- PHYSICS LAB: KIRCHHOFF'S LAW By @rafly.ryy ---" << endl;
}

void circuitAnalysis() {
    double vPeng, iPeng, r;
    cout << "[#] Masukkan Nilai Resistor (Ohm): "; cin >> r;
    cout << "V Pengukuran Multimeter (V): "; cin >> vPeng;
    cout << "I Pengukuran Multimeter (A): "; cin >> iPeng;

    double vHit = iPeng * r;
    double iHit = vPeng / r;

    cout << "\n--- TABEL PERBANDINGAN ---" << endl;
    cout << "V Hitung: " << vHit << " V | V Peng: " << vPeng << " V" << endl;
    cout << "I Hitung: " << iHit << " A | I Peng: " << iPeng << " A" << endl;
}

int main() {
    intro(); circuitAnalysis(); 
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan Enter untuk keluar...";
    cin.ignore(); cin.get();
#endif
    return 0;
}