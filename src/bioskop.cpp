#include "../include/bioskop.h"
#include "../include/kursi.h"
#include <iostream>
#include <limits>

using namespace std;

Bioskop::Bioskop(
    FilmList* film,
    TicketQueue* q,
    HistoryStack* h
) {
    filmList = film;
    queue = q;
    history = h;
}

void Bioskop::lihatKursiFilm() {
    int kodeFilm;

    cout << "Masukkan kode film: ";
    cin >> kodeFilm;

    Film* film = filmList->cariFilm(kodeFilm);

    if (film == nullptr) {
        cout << "Film tidak ditemukan.\n";
        return;
    }

    cout << "\nFilm: " << film->judul << endl;
    tampilKursi(film->kursi);
}

void Bioskop::pesanTiket() {
    string nama;
    int kode;
    int umur;
    int jumlah;

    cout << "\n===== PEMESANAN TIKET =====\n";

    cout << "Nama Pemesan : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nama);

    cout << "Kode Film    : ";
    cin >> kode;

    Film* film = filmList->cariFilm(kode);

    if (film == nullptr) {
        cout << "Film tidak ditemukan.\n";
        return;
    }

    cout << "Umur Anda    : ";
    cin >> umur;

    if (film->umur >= 18 && umur < 18) {
        cout << "\nPERINGATAN!\n";
        cout << "Film ini khusus usia " << film->umur << "+\n";
        return;
    }

    cout << "Jumlah Tiket : ";
    cin >> jumlah;

    if (jumlah <= 0) {
        cout << "Jumlah tiket tidak valid.\n";
        return;
    }

    int total = film->harga * jumlah;

    if (jumlah > 5) {
        cout << "\nDiskon 10% diterapkan!\n";
        total -= total / 10;
    }

    cout << "\n===== PILIH KURSI =====\n";
    tampilKursi(film->kursi);

    for (int i = 0; i < jumlah; i++) {
        int baris, kolom;

        cout << "\nKursi ke-" << i + 1 << endl;
        cout << "Baris (1-5) : ";
        cin >> baris;
        cout << "Kolom (1-5) : ";
        cin >> kolom;

        if (baris < 1 || baris > 5 || kolom < 1 || kolom > 5) {
            cout << "Input kursi tidak valid.\n";
            i--;
            continue;
        }

        if (pesanKursi(film->kursi, baris - 1, kolom - 1)) {
            cout << "Kursi berhasil dipesan.\n";
        } else {
            cout << "Kursi sudah terisi.\n";
            i--;
        }
    }

    queue->enqueue(nama, film->judul, jumlah);
    history->push(nama, film->judul, total);

    cout << "\n========== TIKET ==========\n";
    cout << "Nama      : " << nama << endl;
    cout << "Film      : " << film->judul << endl;
    cout << "Jadwal    : " << film->jadwal << endl;
    cout << "Jumlah    : " << jumlah << endl;
    cout << "Total     : Rp " << total << endl;
    cout << "===========================\n";
}
