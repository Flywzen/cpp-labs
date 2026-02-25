#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void intro() {
#ifdef _WIN32
    system("COLOR 6"); // Kuning
#endif
    cout << "--- PROGRAM KECEPATAN BUNYI DI UDARA  ---" << endl;
}

void hitungBunyi() {
    double f, L, lambda, v_p, v_t = 340.0; // v_t standar suhu ruang
    int n;
    
    cout << "Frekuensi (Hz): "; cin >> f;
    cout << "Resonansi ke- (1, 2, atau 3): "; cin >> n;
    cout << "Panjang kolom udara L (m): "; cin >> L;

    if(n == 1) lambda = 4 * L;
    else if(n == 2) lambda = (4.0/3.0) * L;
    else lambda = (4.0/5.0) * L;

    v_p = f * lambda;
    cout << "Panjang Gelombang (lambda): " << lambda << " m" << endl;
    cout << "Cepat Rambat Bunyi (v): " << v_p << " m/s" << endl;
    cout << "Deviasi: " << abs((v_t - v_p)/v_t)*100 << "%" << endl;
}

int main() {
    intro(); hitungBunyi(); 
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan Enter untuk keluar...";
    cin.ignore(); cin.get();
#endif
    return 0;
}