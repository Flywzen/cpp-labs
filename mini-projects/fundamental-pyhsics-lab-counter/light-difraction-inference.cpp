#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

void difraksi() {
    system("COLOR 5"); // Ungu
    double d, y, L, lambda_teori = 632e-9, lambda_perc;
    int n;

    cout << "--- PROGRAM PERHITUNGAN MODUL DIFRAKSI CAHAYA ---" << endl;
    cout << "Orde terang (n): "; cin >> n;
    cout << "Jarak antar celah d (m): "; cin >> d;
    cout << "Jarak layar L (m): "; cin >> L;
    cout << "Jarak terang pusat ke-n y (m): "; cin >> y;

    // Rumus: lambda = (d * y) / (n * L)
    lambda_perc = (d * y) / (n * L);

    cout << "\nLambda Percobaan : " << lambda_perc << " m" << endl;
    cout << "KSR: " << abs((lambda_perc - lambda_teori)/lambda_teori)*100 << "%" << endl;
}

int main() {
    difraksi(); system("pause"); return 0;
}