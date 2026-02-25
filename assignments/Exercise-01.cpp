#include <iostream>
using namespace std;

int main() {
    // Inisialisasi variabel
    float diagonal = 20;
    float phi = 3.14;
    float jarijari = 0.5 * diagonal;

    // Perhitungan
    float luasLingkaran = phi * jarijari * jarijari;
    float luasBelahKetupat = 0.5 * diagonal * diagonal;
    float luasArsir = luasLingkaran - luasBelahKetupat;

    // Output
    cout << "Luas Daerah Yang Diarsir Adalah : " << luasArsir << endl;

    return 0;
}