#include "../include/film.h"
#include <iostream>

using namespace std;

FilmList::FilmList() {
    head = NULL;
}

void FilmList::tambahFilm(Film film) {

    Node* baru = new Node;

    baru->data = film;
    baru->next = head;

    head = baru;
}

void FilmList::tampilFilm() {

    Node* bantu = head;

    cout << "\n========== DAFTAR FILM ==========\n";

    while (bantu != NULL) {

        cout << "Kode   : " << bantu->data.kode << endl;
        cout << "Judul  : " << bantu->data.judul << endl;
        cout << "Harga  : Rp " << bantu->data.harga << endl;
        cout << "Rating : R" << bantu->data.umur << "+" << endl;
        cout << "Jadwal : " << bantu->data.jadwal << endl;

        cout << "--------------------------------\n";

        bantu = bantu->next;
    }
}

Film* FilmList::cariFilm(int kode) {

    Node* bantu = head;

    while (bantu != NULL) {

        if (bantu->data.kode == kode) {
            return &bantu->data;
        }

        bantu = bantu->next;
    }

    return NULL;
}

void FilmList::sortingFilm() {

    for (Node* i = head; i != NULL; i = i->next) {

        for (Node* j = i->next; j != NULL; j = j->next) {

            if (i->data.jadwal > j->data.jadwal) {
                swap(i->data, j->data);
            }
        }
    }

    cout << "\nFilm berhasil diurutkan.\n";
}