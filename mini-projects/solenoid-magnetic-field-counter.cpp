#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void intro() { // Pakai void karena tidak mengembalikan nilai
    system("COLOR B");
    cout << "=========================================================================================" << endl;
    cout << " PROGRAM PERHITUNGAN MEDAN MAGNET PADA SOLENOIDA By @rafly.ryy" << endl;
    cout << "=========================================================================================" << endl;
    cout << "\nNB: Gunakan titik (.) sebagai pengganti koma (,)\n" << endl;
}

void BTeori() {
    int z;
    cout << "- Mencari nilai B(0) atau B Teori" << endl;
    cout << "Masukkan jumlah tabel yang akan dihitung: ";
    cin >> z;

    for (int a = 0; a < z; a++) {
        // mu0 = 4 * pi * 10^-7
        const double mu0 = 4 * M_PI * std::pow(10, -7);
        double L, N, I, X;

        cout << "\n- Perhitungan tabel ke-" << a + 1 << endl;
        cout << "Masukkan Data N: "; cin >> N;
        cout << "Masukkan Data I: "; cin >> I;
        cout << "Masukkan Data L: "; cin >> L;

        X = (mu0 * N * I) / L;
        cout << "Nilai BTeori adalah: " << X << " Tesla" << endl;
    }
}

int main() {
    char x;
    do {
        system("cls"); // Bersihkan layar setiap kali ulang
        intro();
        BTeori();
        cout << "\nApakah anda ingin mengulang program ini? [Y/n]: ";
        cin >> x;
    } while (x == 'Y' || x == 'y');

    cout << "Program Selesai, Terima kasih!" << endl;
    return 0;
}