#include <iostream>
#include <cctype>
#include <limits>

#include "include/film.h"
#include "include/bioskop.h"
#include "include/queue.h"
#include "include/stack.h"
#include "include/utils.h"

using namespace std;

int main() {
    FilmList film;

    film.tambahFilm({101, "Avengers Endgame", 50000, 13, "13:00"});
    film.tambahFilm({102, "The Conjuring", 45000, 18, "15:00"});
    film.tambahFilm({103, "Jumbo", 40000, 7, "10:00"});
    film.tambahFilm({104, "Interstellar", 55000, 13, "12:30"});
    film.tambahFilm({105, "Spider-Man", 52000, 13, "14:00"});
    film.tambahFilm({106, "Frozen", 38000, 7, "09:30"});
    film.tambahFilm({107, "Dune", 60000, 13, "19:00"});

    TicketQueue queue;
    HistoryStack history;

    Bioskop bioskop(&film, &queue, &history);

    int pilih;

    do {
        Utils::header("BIOSKOP APP");

        cout << "1. Daftar Film (Pagination)\n";
        cout << "2. Pesan Tiket\n";
        cout << "3. Lihat Kursi Film\n";
        cout << "4. Sorting Film\n";
        cout << "5. Queue Pembelian\n";
        cout << "6. Histori\n";
        cout << "0. Keluar\n";

        cout << "\nPilih : ";
        cin >> pilih;

        switch (pilih) {
        case 1: {
            int page = 1;
            char nav;
            int totalPage = film.totalHalaman();

            if (totalPage == 0) {
                cout << "\nBelum ada data film.\n";
                break;
            }

            do {
                Utils::header("DAFTAR FILM");

                film.tampilFilmPage(page);

                cout << "\nN = Next | P = Previous | Q = Kembali\n";
                cout << "Pilihan : ";
                cin >> nav;
                nav = toupper(static_cast<unsigned char>(nav));

                if (nav == 'N' && page < film.totalHalaman()) {
                    page++;
                } else if (nav == 'P' && page > 1) {
                    page--;
                } else if (nav == 'Q') {
                    break;
                }
            } while (true);

            break;
        }

        case 2:
            bioskop.pesanTiket();
            break;

        case 3:
            bioskop.lihatKursiFilm();
            break;

        case 4:
            film.sortingFilm();
            break;

        case 5:
            queue.tampilQueue();
            break;

        case 6:
            history.tampilHistori();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia.\n";
        }

        if (pilih != 0) {
            cout << "\nTekan Enter untuk lanjut...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            Utils::clearScreen();
        }

    } while (pilih != 0);

    return 0;
}
