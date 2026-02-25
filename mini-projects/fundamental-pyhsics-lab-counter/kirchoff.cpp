#include <iostream>
#include <windows.h>

using namespace std;

void intro() {
    system("COLOR 4"); // Merah
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
    intro(); circuitAnalysis(); system("pause"); return 0;
}