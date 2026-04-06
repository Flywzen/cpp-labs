#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

int main() {
    int jarak = 30; // Jarak awal
    int padding_kiri = 5;

    cout << "\033[33mMenginisialisasi Hukum Gravitasi Newton...\033[0m\n\n";
    this_thread::sleep_for(chrono::seconds(2));

    
    while(jarak > 0) {
        
        cout << "\r" << string(padding_kiri, ' ') << "(A)" << string(jarak, '-') << "(B)" << flush;
        
        jarak -= 2;
        padding_kiri += 1; 
        
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    
    cout << "\r" << string(padding_kiri, ' ') << "(Rafly❤️Hanna)" << string(20, ' ') << "\n\n";
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Menurut Newton, benda bermassa akan saling tarik-menarik...\n";
    cout << "\033[1;35mDan itu adalah alasan mengapa aku selalu tertarik padamu secara eksponensial. ✨\033[0m\n\n";

    return 0;
}
