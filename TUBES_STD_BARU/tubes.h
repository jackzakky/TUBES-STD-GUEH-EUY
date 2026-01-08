#ifndef TUBES_H
#define TUBES_H

#include <string>
#include <iostream>
using namespace std;

typedef struct ElmParent* adrParent;
typedef struct ElmChild* adrChild;

struct ElmChild {
    string namaRuangan;
    string masalah;
    adrChild next;
};

struct ElmParent {
    string namaGedung;
    adrParent next;
    adrChild firstChild;
};

struct List {
    adrParent first;
};

void createList(List &L);
adrParent createParent(string namaGedung);
adrChild createChild(string namaRuangan, string masalah);

adrParent findParent(List L, string namaGedung);
void insertParent(List &L, adrParent P);
void insertChild(adrParent P, adrChild C);

void inputLaporan(List &L);
void cetakLaporan(List L);

#endif
