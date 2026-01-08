#include <iostream>
#include "tubes.h"
using namespace std;

int main() {
    Node* listGedung = NULL; // Head utama MLL
    int pilih;

    do {
        cout << "=== SISTEM PELAPORAN MLL ===\n";
        cout << "1. Tambah Laporan\n";
        cout << "2. Tampilkan Laporan\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            inputLaporan(listGedung);
        } else if (pilih == 2) {
            cout << "\n--- DATA LAPORAN ---\n";
            tampilkanSemua(listGedung);
        }
    } while (pilih != 0);

    return 0;
}
