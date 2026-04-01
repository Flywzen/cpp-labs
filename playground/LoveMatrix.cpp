#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

int main() {
    // Efek Matrix berjalan selama ~3 detik
    cout << "\033[32m"; // Warna hijau terminal
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 40; j++) {
            cout << rand() % 2 << " "; // Print 0 atau 1 acak
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(30));
    }

   
    system("clear || cls");

    
    cout << "\033[1;32m[SYSTEM] DECRYPTING HEART... SUCCESS!\033[0m\n\n";
    this_thread::sleep_for(chrono::seconds(1));
    
    cout << "\033[1;31mYOU ARE MY WORLD ❤️\033[0m\n\n";
    
    return 0;
}
