#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

void setcolor(unsigned short color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
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
    system("pause");
    return 0;
}