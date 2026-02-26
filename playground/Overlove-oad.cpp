#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    cout << "System Booting...\n";
    this_thread::sleep_for(chrono::seconds(1));

    // Animasi Loading
    for(int i = 1; i <= 100; i++) {
        cout << "\r\033[36mLoading feelings: [";
        for(int j = 0; j < 20; j++) {
            if(j < i / 5) cout << "#";
            else cout << ".";
        }
        cout << "] " << i << "%\033[0m" << flush;
        
        // Bikin loadingnya agak lambat di akhir biar dramatis
        if (i > 80) this_thread::sleep_for(chrono::milliseconds(150));
        else this_thread::sleep_for(chrono::milliseconds(40));
    }

    // Plot Twist
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n\n\033[1;31m[FATAL ERROR] Variable 'Love' exceeded maximum capacity (Integer Overflow).\033[0m\n";
    
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\033[35m...Just kidding, I just really love you!\033[0m\n\n";

    return 0;
}