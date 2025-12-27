#ifndef TUBES_H
#define TUBES_H

#include <string>
using namespace std;

struct Node {
    string nama;
    Node* left;
    Node* right;
};

Node* buatNode(string nama);
Node* cariNode(Node* root, string nama);
void tambahAnak(Node* parent, Node* anak);
void tambahLaporan(Node* root);

void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);

#endif
