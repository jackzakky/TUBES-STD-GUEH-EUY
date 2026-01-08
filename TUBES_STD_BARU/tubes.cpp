#include "tubes.h"

void createList(List &L) {
    L.first = NULL;
}

adrParent createParent(string namaGedung) {
    adrParent P = new ElmParent;
    P->namaGedung = namaGedung;
    P->next = NULL;
    P->firstChild = NULL;
    return P;
}

adrChild createChild(string namaRuangan, string masalah) {
    adrChild C = new ElmChild;
    C->namaRuangan = namaRuangan;
    C->masalah = masalah;
    C->next = NULL;
    return C;
}

adrParent findParent(List L, string namaGedung) {
    adrParent P = L.first;
    while (P != NULL) {
        if (P->namaGedung == namaGedung) return P;
        P = P->next;
    }
    return NULL;
}

void insertParent(List &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrParent last = L.first;
        while (last->next != NULL) last = last->next;
        last->next = P;
    }
}

void insertChild(adrParent P, adrChild C) {
    if (P->firstChild == NULL) {
        P->firstChild = C;
    } else {
        adrChild last = P->firstChild;
        while (last->next != NULL) last = last->next;
        last->next = C;
    }
}

void inputLaporan(List &L) {
    string gedung, ruang, masalah;
    cout << "Input Nama Gedung : "; getline(cin, gedung);
    cout << "Input Nama Ruangan: "; getline(cin, ruang);
    cout << "Input Masalah     : "; getline(cin, masalah);

    adrParent P = findParent(L, gedung);

    if (P == NULL) {
        P = createParent(gedung);
        insertParent(L, P);
    }

    adrChild C = createChild(ruang, masalah);
    insertChild(P, C);

    cout << ">>> Laporan berhasil disimpan ke " << gedung << endl;
}

void cetakLaporan(List L) {
    adrParent P = L.first;
    if (P == NULL) {
        cout << "List Laporan Kosong." << endl;
        return;
    }

    while (P != NULL) {
        cout << "\n[ GEDUNG: " << P->namaGedung << " ]" << endl;
        adrChild C = P->firstChild;
        int i = 1;
        while (C != NULL) {
            cout << "  " << i++ << ". Ruangan: " << C->namaRuangan << endl;
            cout << "     Masalah: " << C->masalah << endl;
            C = C->next;
        }
        P = P->next;
    }
}
