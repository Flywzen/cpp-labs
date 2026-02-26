#include <iostream>

using namespace std;

int main() {
    char jawaban;

    cout << "======================================\n";
    cout << "       SYSTEM SECURITY CHECK          \n";
    cout << "======================================\n";

    do {
        cout << "\nDo you want to go out with me this Saturday? (y/n): ";
        cin >> jawaban;

        if(jawaban == 'n' || jawaban == 'N') {
            cout << "\033[31m[!] INVALID CHOICE: My system prevents me from accepting a 'no'. Try again!\033[0m\n";
        }

    } while(jawaban != 'y' && jawaban != 'Y');

    cout << "\n\033[1;32mYAY! Date confirmed. Can't wait! 🎉\033[0m\n\n";

    return 0;
}