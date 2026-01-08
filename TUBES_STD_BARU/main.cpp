#include <iostream>
#include "tubes.h"
using namespace std;

int main() {
    List L;
    createList(L);
    int pilih;

    do {
        cout << "\n==== SISTEM PELAPORAN FASILITAS KAMPUS ====\n";
        cout << "1. Submit Laporan\n";
        cout << "2. Tampilkan Semua Gedung & Masalah\n";
        cout << "0. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            inputLaporan(L);
        } else if (pilih == 2) {
            cetakLaporan(L);
        }
    } while (pilih != 0);

    return 0;
}
