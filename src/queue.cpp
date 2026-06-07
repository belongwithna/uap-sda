#include "../include/queue.h"
#include <iostream>

using namespace std;

TicketQueue::TicketQueue() {

    front = -1;
    rear = -1;
}

bool TicketQueue::isEmpty() {

    return front == -1;
}

void TicketQueue::enqueue(string nama, string film, int jumlah) {

    if (rear == 99) {

        cout << "Queue penuh!\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;

    data[rear].nama = nama;
    data[rear].film = film;
    data[rear].jumlah = jumlah;
}

void TicketQueue::tampilQueue() {

    if (isEmpty()) {

        cout << "\nQueue kosong.\n";
        return;
    }

    cout << "\n===== ANTRIAN PEMBELIAN =====\n";

    for (int i = front; i <= rear; i++) {

        cout << i + 1 << ". "
             << data[i].nama
             << " - "
             << data[i].film
             << " (" << data[i].jumlah
             << " tiket)\n";
    }
}