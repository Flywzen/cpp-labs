#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>

using namespace std;

// Fungsi untuk mewarnai teks di terminal Windows
void setcolor(unsigned short color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

void intro() {
    system("COLOR 0F"); // Latar hitam, teks putih agar netral di awal
    cout << "========================================================================================" << endl;
    cout << " PROGRAM PERHITUNGAN PRAKTIKUM FISIKA VISKOSITAS By @rafly.ryy" << endl;
    cout << "========================================================================================" << endl;
    cout << "\nNB : Gunakan titik (.) untuk bilangan desimal." << endl;
    cout << "________________________________________________________________________________________\n" << endl;
}

void hitungViskositas() {
    setcolor(6); // Warna emas/kuning
    cout << "[#] Mencari Nilai Koefisien Viskositas" << endl;
    double t, r, g, Pbola, Pfluida, d, x;
    g = 9.8;
    Pbola = 1000;
    Pfluida = 800;
    r = 0.003374;

    cout << "Masukkan Data t : "; cin >> t;
    cout << "Masukkan Data d : "; cin >> d;
    
    // Rumus: x = (Pbola - Pfluida) * 2 * g * r^2 * t / (9 * d)
    // Catatan: r di kode kamu belum dikuadratkan, pastikan sesuai modul ya!
    x = (Pbola - Pfluida) * 2 * g * r * t / (9 * d);
    
    cout << ">> Nilai Koefisien Viskositas: " << x << " Pa.s" << endl;
    setcolor(7); // Reset ke putih
    cout << endl;
}

void hitungKetelitian() {
    setcolor(11); // Biru muda
    double t1, t2, t3, tbar, dt;
    cout << "[#] Analisis Data & Ketelitian" << endl;
    cout << "Masukkan t1: "; cin >> t1;
    cout << "Masukkan t2: "; cin >> t2;
    cout << "Masukkan t3: "; cin >> t3;

    tbar = (t1 + t2 + t3) / 3;
    // Mencari Delta t (Ketidakpastian)
    dt = sqrt(((tbar - t1) * (tbar - t1) + (tbar - t2) * (tbar - t2) + (tbar - t3) * (tbar - t3)) / 6);
    
    cout << ">> t rata-rata : " << tbar << endl;
    cout << ">> Delta t     : " << dt << endl;
    cout << ">> Ketelitian  : " << (1 - (dt / tbar)) * 100 << "%" << endl;
    setcolor(7);
    cout << endl;
}

int main() {
    intro();
    hitungViskositas();
    hitungKetelitian();
    
    cout << "Program Selesai. Tetap semangat praktikumnya!" << endl;
    system("pause");
    return 0;
}