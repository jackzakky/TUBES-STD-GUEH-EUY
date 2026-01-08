#ifndef TUBES_H
#define TUBES_H

#include <string>
#include <iostream>
using namespace std;

struct InfoType {
    string namaGedung;
    string namaRuangan;
    string masalah;
};

struct Node {
    InfoType info;
    Node* next;
    Node* child;
};


Node* buatNode(InfoType info);
Node* cariGedung(Node* head, string namaGedung);
Node* cariRuangan(Node* headGedung, string namaRuangan);
void tambahGedung(Node*& head, InfoType info);
void tambahRuangan(Node* gedung, InfoType info);
void tambahMasalah(Node* ruangan, InfoType info);


void inputLaporan(Node*& head);
void tampilkanSemua(Node* head);

#endif
