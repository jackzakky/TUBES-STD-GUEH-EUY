#include "tubes.h"

Node* buatNode(InfoType info) {
    Node* baru = new Node;
    baru->info = info;
    baru->next = NULL;
    baru->child = NULL;
    return baru;
}

Node* cariGedung(Node* head, string namaGedung) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->info.namaGedung == namaGedung) return temp;
        temp = temp->next;
    }
    return NULL;
}

Node* cariRuangan(Node* headGedung, string namaRuangan) {
    if (headGedung == NULL) return NULL;
    Node* temp = headGedung->child;
    while (temp != NULL) {
        if (temp->info.namaRuangan == namaRuangan) return temp;
        temp = temp->next;
    }
    return NULL;
}

void tambahGedung(Node*& head, InfoType info) {
    Node* baru = buatNode(info);
    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = baru;
    }
}

void inputLaporan(Node*& head) {
    InfoType info;
    cout << "Gedung : "; getline(cin, info.namaGedung);
    cout << "Ruang  : "; getline(cin, info.namaRuangan);
    cout << "Masalah: "; getline(cin, info.masalah);


    Node* g = cariGedung(head, info.namaGedung);
    if (g == NULL) {
        tambahGedung(head, info);
        g = cariGedung(head, info.namaGedung);
    }


    Node* r = cariRuangan(g, info.namaRuangan);
    if (r == NULL) {
        Node* baruR = buatNode(info);
        if (g->child == NULL) {
            g->child = baruR;
        } else {
            Node* tempR = g->child;
            while (tempR->next != NULL) tempR = tempR->next;
            tempR->next = baruR;
        }
        r = baruR;
    }


    Node* baruM = buatNode(info);
    if (r->child == NULL) {
        r->child = baruM;
    } else {
        Node* tempM = r->child;
        while (tempM->next != NULL) tempM = tempM->next;
        tempM->next = baruM;
    }
    cout << "Laporan tersimpan.\n";
}

void tampilkanSemua(Node* head) {
    Node* pGedung = head;
    if (pGedung == NULL) cout << "List Kosong.\n";

    while (pGedung != NULL) {
        cout << "[Gedung: " << pGedung->info.namaGedung << "]" << endl;

        Node* pRuang = pGedung->child;
        while (pRuang != NULL) {
            cout << "  - Ruang: " << pRuang->info.namaRuangan << endl;

            Node* pMasalah = pRuang->child;
            while (pMasalah != NULL) {
                cout << "    * Masalah: " << pMasalah->info.masalah << endl;
                pMasalah = pMasalah->next;
            }
            pRuang = pRuang->next;
        }
        pGedung = pGedung->next;
        cout << endl;
    }
}
