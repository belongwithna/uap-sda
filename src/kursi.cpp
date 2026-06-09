#include "../include/kursi.h"
#include <iostream>

using namespace std;

void inisialisasiKursi(bool kursi[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kursi[i][j] = false;
        }
    }
}

void tampilKursi(const bool kursi[5][5]) {
    cout << "\n===== DENAH KURSI =====\n";
    cout << "O = kosong, X = terisi\n\n";

    cout << "    1 2 3 4 5\n";
    cout << "   -----------\n";

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 5; j++) {
            cout << (kursi[i][j] ? 'X' : 'O') << ' ';
        }
        cout << '\n';
    }
}

bool pesanKursi(bool kursi[5][5], int baris, int kolom) {
    if (baris < 0 || baris >= 5 || kolom < 0 || kolom >= 5) {
        return false;
    }

    if (kursi[baris][kolom]) {
        return false;
    }

    kursi[baris][kolom] = true;
    return true;
}