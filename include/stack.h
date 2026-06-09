#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

struct HistoryData {

    string nama;
    string film;
    int total;
};

class HistoryStack {

private:
    HistoryData data[100];

    int top;

public:
    HistoryStack();

    void push(string nama, string film, int total);

    void tampilHistori();

    bool isEmpty();
};

#endif