#include "../include/stack.h"
#include <iostream>

using namespace std;

HistoryStack::HistoryStack() {

    top = -1;
}

bool HistoryStack::isEmpty() {

    return top == -1;
}

void HistoryStack::push(string nama, string film, int total) {

    if (top == 99) {

        cout << "Stack penuh!\n";
        return;
    }

    top++;

    data[top].nama = nama;
    data[top].film = film;
    data[top].total = total;
}

void HistoryStack::tampilHistori() {

    if (isEmpty()) {

        cout << "\nBelum ada transaksi.\n";
        return;
    }

    cout << "\n===== HISTORI TRANSAKSI =====\n";

    for (int i = top; i >= 0; i--) {

        cout << "Nama  : " << data[i].nama << endl;
        cout << "Film  : " << data[i].film << endl;
        cout << "Total : Rp " << data[i].total << endl;

        cout << "-----------------------------\n";
    }
}
