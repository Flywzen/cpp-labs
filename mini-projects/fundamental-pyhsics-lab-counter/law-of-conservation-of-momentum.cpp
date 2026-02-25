#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void intro() {
#ifdef _WIN32
    system("COLOR 1"); // Biru
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
        cout << "Kecepatan gabungan setelah tumbukan (v'): " << vaksen << " m/s" << endl;
    } else {
        cout << "Input va' (hasil pengamatan): "; cin >> vaksen;
        cout << "Input vb' (hasil pengamatan): "; cin >> vbaksen;
        double pAwal = ma*va + mb*vb;
        double pAkhir = ma*vaksen + mb*vbaksen;
        cout << "Momentum Awal  : " << pAwal << endl;
        cout << "Momentum Akhir : " << pAkhir << endl;
        cout << "Persen Error   : " << abs((pAwal-pAkhir)/pAwal)*100 << "%" << endl;
    }
}

int main() {
    intro(); momentum(); 
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan Enter untuk keluar...";
    cin.ignore(); cin.get();
#endif
    return 0;
}