#include "../include/film.h"
#include "../include/kursi.h"
#include <iostream>
#include <algorithm>

using namespace std;

FilmList::FilmList() {
    head = nullptr;
}

void FilmList::tambahFilm(Film film) {
    Node* baru = new Node;
    baru->data = film;

    inisialisasiKursi(baru->data.kursi);

    baru->next = head;
    head = baru;
}

int FilmList::countFilm() {
    int c = 0;
    Node* p = head;
    while (p != nullptr) {
        c++;
        p = p->next;
    }
    return c;
}

int FilmList::totalHalaman() {
    int total = countFilm();
    if (total == 0) return 0;
    return (total + 4) / 5;
}

void FilmList::tampilFilm() {
    tampilFilmPage(1);
}

void FilmList::tampilFilmPage(int page) {
    int totalPage = totalHalaman();

    if (totalPage == 0) {
        cout << "\nBelum ada data film.\n";
        return;
    }

    if (page < 1 || page > totalPage) {
        cout << "\nHalaman tidak tersedia.\n";
        return;
    }

    const int perPage = 5;
    int start = (page - 1) * perPage;
    int end = start + perPage;
    int idx = 0;

    Node* p = head;

    cout << "\n========== DAFTAR FILM ==========\n";
    cout << "Halaman " << page << " dari " << totalPage << "\n";
    cout << "----------------------------------\n";

    while (p != nullptr) {
        if (idx >= start && idx < end) {
            cout << "Kode   : " << p->data.kode << endl;
            cout << "Judul  : " << p->data.judul << endl;
            cout << "Harga  : Rp " << p->data.harga << endl;
            cout << "Rating : R" << p->data.umur << "+" << endl;
            cout << "Jadwal : " << p->data.jadwal << endl;
            cout << "----------------------------------\n";
        }
        idx++;
        p = p->next;
    }
}

Film* FilmList::cariFilm(int kode) {
    Node* bantu = head;

    while (bantu != nullptr) {
        if (bantu->data.kode == kode) {
            return &bantu->data;
        }
        bantu = bantu->next;
    }

    return nullptr;
}

void FilmList::sortingFilm() {
    if (head == nullptr) {
        cout << "\nBelum ada data film.\n";
        return;
    }

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data.jadwal > j->data.jadwal) {
                swap(i->data, j->data);
            }
        }
    }

    cout << "\nFilm berhasil diurutkan berdasarkan jadwal.\n";
}