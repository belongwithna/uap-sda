#include "../include/utils.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void Utils::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Utils::pause() {
    cout << "Tekan Enter untuk lanjut...";
    cin.get();
}

void Utils::header(string title) {
    cout << "\n==============================\n";
    cout << title << endl;
    cout << "==============================\n";
}
