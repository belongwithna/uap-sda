#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;

struct QueueData {
    string nama;
    string film;
    int jumlah;
};

class TicketQueue {

private:
    QueueData data[100];

    int front;
    int rear;

public:
    TicketQueue();

    void enqueue(string nama, string film, int jumlah);

    void tampilQueue();

    bool isEmpty();
};

#endif