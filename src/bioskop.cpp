#include "../include/bioskop.h"
#include <iostream>

using namespace std;

Bioskop::Bioskop(
    FilmList* film,
    Kursi* kursiObj,
    TicketQueue* q,
    HistoryStack* h
) {

    filmList = film;

    kursi = kursiObj;

    queue = q;

    history = h;
}

void Bioskop::pesanTiket() {

    string nama;

    int kode;
    int umur;
    int jumlah;

    filmList->tampilFilm();

    cin.ignore();

    cout << "\nNama Pemesan : ";
    getline(cin, nama);

    cout << "Kode Film    : ";
    cin >> kode;

    Film* film = filmList->cariFilm(kode);

    if (film == NULL) {

        cout << "Film tidak ditemukan.\n";
        return;
    }

    cout << "Umur Anda    : ";
    cin >> umur;

    if (film->umur >= 18 && umur < 18) {

        cout << "\nAKSES DITOLAK!\n";
        cout << "Film ini khusus usia "
             << film->umur
             << "+\n";

        return;
    }

    cout << "Jumlah Tiket : ";
    cin >> jumlah;

    int total = film->harga * jumlah;

    if (jumlah > 5) {

        cout << "\nDiskon 10% diterapkan!\n";

        total -= total * 0.10;
    }

    cout << "\n===== PILIH KURSI =====\n";

    kursi->tampilKursi();

    for (int i = 0; i < jumlah; i++) {

        int baris, kolom;

        cout << "\nKursi ke-" << i + 1 << endl;

        cout << "Baris : ";
        cin >> baris;

        cout << "Kolom : ";
        cin >> kolom;

        if (kursi->pesanKursi(baris - 1, kolom - 1)) {

            cout << "Kursi berhasil dipesan.\n";
        }
        else {

            cout << "Kursi sudah terisi.\n";
            i--;
        }
    }

    queue->enqueue(
        nama,
        film->judul,
        jumlah
    );

    history->push(
        nama,
        film->judul,
        total
    );

    cout << "\n========== TIKET ==========\n";

    cout << "Nama      : " << nama << endl;
    cout << "Film      : " << film->judul << endl;
    cout << "Jadwal    : " << film->jadwal << endl;
    cout << "Jumlah    : " << jumlah << endl;
    cout << "Total     : Rp " << total << endl;

    cout << "===========================\n";
}
