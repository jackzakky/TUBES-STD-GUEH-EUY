#include "tubes.h"
#include <iostream>

Node* buatNode(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* cariNode(Node* root, string nama) {
    if (root == NULL) return NULL;
    if (root->nama == nama) return root;

    Node* ditemukan = cariNode(root->left, nama);
    if (ditemukan != NULL) return ditemukan;

    return cariNode(root->right, nama);
}

void tambahAnak(Node* parent, Node* anak) {
    if (parent->left == NULL) {
        parent->left = anak;
    } else {
        Node* temp = parent->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = anak;
    }
}

void tambahLaporan(Node* root) {
    string gedung, ruang, kerusakan;

    cout << "Masukkan nama gedung: ";
    getline(cin, gedung);

    cout << "Masukkan nama ruangan: ";
    getline(cin, ruang);

    cout << "Masukkan jenis kerusakan: ";
    getline(cin, kerusakan);

    Node* nodeGedung = cariNode(root, gedung);
    if (nodeGedung == NULL) {
        nodeGedung = buatNode(gedung);
        tambahAnak(root, nodeGedung);
    }

    Node* nodeRuang = cariNode(nodeGedung, ruang);
    if (nodeRuang == NULL) {
        nodeRuang = buatNode(ruang);
        tambahAnak(nodeGedung, nodeRuang);
    }

    Node* nodeKerusakan = buatNode(kerusakan);
    tambahAnak(nodeRuang, nodeKerusakan);

    cout << "Laporan berhasil ditambahkan\n";
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->nama << endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->nama << endl;
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->nama << endl;
}
