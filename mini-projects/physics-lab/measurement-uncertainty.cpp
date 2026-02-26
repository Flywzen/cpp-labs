#include <iostream>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void setcolor(unsigned short color) {
#ifdef _WIN32
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
#endif
}

void intro() {
    system("COLOR 7");
    cout << "==========================================================================" << endl;
    cout << " PROGRAM PENGUKURAN DAN KETIDAKPASTIAN By @rafly.ryy" << endl;
    cout << "==========================================================================" << endl;
}

void hitungKetidakpastian() {
    int n;
    double data[100], sum = 0, pBar, sumSquare = 0, deltaP, ketelitian;
    
    setcolor(10); // Hijau
    cout << "Masukkan jumlah data (n): "; cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "Data ke-" << i+1 << ": "; cin >> data[i];
        sum += data[i];
    }
    
    pBar = sum / n;
    
    for(int i = 0; i < n; i++) {
        sumSquare += pow((pBar - data[i]), 2);
    }
    
    deltaP = sqrt(sumSquare / (n * (n - 1)));
    ketelitian = (1 - (deltaP / pBar)) * 100;
    
    cout << "\n--- HASIL ANALISIS ---" << endl;
    cout << "Rata-rata (p bar)  : " << pBar << endl;
    cout << "Ketidakpastian (dp): " << deltaP << endl;
    cout << "Ketelitian         : " << ketelitian << "%" << endl;
}

int main() {
    intro();
    hitungKetidakpastian();
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan Enter untuk keluar...";
    cin.ignore(); cin.get();
#endif
    return 0;
}