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
    bool kursi[5][5];
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
    void tampilFilmPage(int page);
    int countFilm();
    int totalHalaman();
    Film* cariFilm(int kode);
    void sortingFilm();
};

#endif