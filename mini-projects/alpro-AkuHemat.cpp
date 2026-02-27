/*
 * PROJECT: AKUHEMAT - Debt Management System
 * AUTHOR: @flywzen
 * FEATURES: User Authentication, Recursion Totaling, Sorting (High/Low), and Data Searching.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

// Data structure to store debt information
struct Debt {
    string name;
    long long int waNumber;
    long int amount;
};

// --- SYSTEM UTILITIES ---

string getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    char timeStr[100];
    if (strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localtime(&now_time))) {
        return string(timeStr);
    }
    return "Time Error";
}

void saveAccount(string user, int pass) {
    ofstream file("accounts.txt", ios::app);
    if (file.is_open()) {
        file << user << " " << pass << endl;
        file.close();
        cout << "[+] Account saved successfully!\n";
    }
}

bool checkAccount(string user, int pass) {
    ifstream file("accounts.txt");
    string line;
    while (getline(file, line)) {
        if (line == user + " " + to_string(pass)) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// --- DATA PROCESSING (RECURSION & SORTING) ---

long int calculateTotal(int n, Debt *data, int index) {
    if (index == n) return 0;
    return data[index].amount + calculateTotal(n, data, index + 1);
}

void sortHighToLow(Debt *data, int n) {
    sort(data, data + n, [](Debt a, Debt b) { return a.amount > b.amount; });
}

void sortLowToHigh(Debt *data, int n) {
    sort(data, data + n, [](Debt a, Debt b) { return a.amount < b.amount; });
}

// --- CORE FUNCTIONS ---

void inputDebtData(int &n, Debt *data) {
    cout << "\n====================================" << endl;
    cout << "  INPUT DEBTOR DATA (Nagih Mode: ON)" << endl;
    cout << "====================================" << endl;
    cout << "Masukkan jumlah penghutang: "; cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\n[ Data #" << i + 1 << " ]" << endl;
        cout << "Nama: "; getline(cin, data[i].name);
        cout << "Nomor WhatsApp: "; cin >> data[i].waNumber;
        cout << "Jumlah Hutang: Rp."; cin >> data[i].amount;
        cin.ignore();
    }
}

void showDebtList(int n, Debt *data, string time) {
    cout << "\n--- LIST DATA PENGHUTANG ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << data[i].name << " | WA: " << data[i].waNumber 
             << " | Rp." << data[i].amount << endl;
    }
    cout << "\nLast Update: " << time << endl;
}

int main() {
    int choice;
    string user, timeNow;
    int pass, n;
    Debt data[100];
    char exitChar = 'Y';

    while (exitChar == 'Y' || exitChar == 'y') {
        system("cls"); // Clear screen for cleaner look
        cout << "+--------------------------------+\n";
        cout << "      AKUHEMAT - DEBT TRACKER\n";
        cout << "+--------------------------------+\n";
        cout << "1. Login\n2. Create Account\nChoice: "; cin >> choice;

        if (choice == 1) {
            cout << "Username: "; cin >> user;
            cout << "Password (number): "; cin >> pass;

            if (checkAccount(user, pass)) {
                cout << "\nWelcome back, " << user << "!\n";
                timeNow = getCurrentTime();
                inputDebtData(n, data);

                cout << "\nUrutkan data? (1: Terkecil, 2: Terbesar, 3: No): ";
                int s; cin >> s;
                if(s == 1) sortLowToHigh(data, n);
                else if(s == 2) sortHighToLow(data, n);

                showDebtList(n, data, timeNow);
                cout << "TOTAL HUTANG KE ANDA: Rp." << calculateTotal(n, data, 0) << endl;
            } else {
                cout << "Login failed!\n";
            }
        } else if (choice == 2) {
            cout << "New Username: "; cin >> user;
            cout << "New Password (number): "; cin >> pass;
            saveAccount(user, pass);
        }

        cout << "\nLanjut program? (Y/Q): "; cin >> exitChar;
    }

    return 0;
}
