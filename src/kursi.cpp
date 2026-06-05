#include "../include/kursi.h"
#include <iostream>

using namespace std;

Kursi::Kursi() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kursi[i][j] = 'O';
        }
    }
}

void Kursi::tampilKursi() {

    cout << "\n===== DENAH KURSI =====\n\n";

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            cout << kursi[i][j] << " ";
        }

        cout << endl;
    }
}

bool Kursi::pesanKursi(int baris, int kolom) {

    if (kursi[baris][kolom] == 'O') {

        kursi[baris][kolom] = 'X';
        return true;
    }

    return false;
}

bool Kursi::cariKursiKosong(int baris, int kolom) {

    if (baris == 5)
        return false;

    if (kolom == 5)
        return cariKursiKosong(baris + 1, 0);

    if (kursi[baris][kolom] == 'O') {

        kursi[baris][kolom] = 'X';

        cout << "Kursi otomatis dipilih.\n";

        return true;
    }

    return cariKursiKosong(baris, kolom + 1);
}