#ifndef FILM_H
#define FILM_H

#include <string>

using namespace std;

struct Film {
    int kode;
    string judul;
    int harga;
    int umur;
    string jadwal;
};

struct Node {
    Film data;
    Node* next;
};

class FilmList {
private:
    Node* head;

public:
    FilmList();

    void tambahFilm(Film film);
    void tampilFilm();
    Film* cariFilm(int kode);
    void sortingFilm();
};

#endif