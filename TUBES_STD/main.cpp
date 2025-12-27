#include <iostream>
#include "tubes.h"
using namespace std;

int main() {
    Node* root = buatNode("Kampus");
    int pilihan;

    do {
        cout << "\n=== Sistem Pelaporan Fasilitas Kampus ===\n";
        cout << "1. Tambah laporan baru\n";
        cout << "2. Tampilkan seluruh laporan (Pre-order)\n";
        cout << "3. Traversal In-order\n";
        cout << "4. Traversal Post-order\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahLaporan(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
        }
    } while (pilihan != 0);

    return 0;
}
