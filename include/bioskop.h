#ifndef BIOSKOP_H
#define BIOSKOP_H

#include "film.h"
#include "queue.h"
#include "stack.h"

class Bioskop {

private:
    FilmList* filmList;
    TicketQueue* queue;
    HistoryStack* history;

public:
    Bioskop(
        FilmList* film,
        TicketQueue* q,
        HistoryStack* h
    );

    void pesanTiket();
    void lihatKursiFilm();
};

#endif