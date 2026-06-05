#ifndef BIOSKOP_H
#define BIOSKOP_H

#include "film.h"
#include "kursi.h"
#include "queue.h"
#include "stack.h"

class Bioskop {

private:

    FilmList* filmList;

    Kursi* kursi;

    TicketQueue* queue;

    HistoryStack* history;

public:

    Bioskop(
        FilmList* film,
        Kursi* kursiObj,
        TicketQueue* q,
        HistoryStack* h
    );

    void pesanTiket();
};

#endif