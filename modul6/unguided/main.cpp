#include <iostream>
#include "doublylist.h"
#include "doublylist.cpp"
using namespace std;

int main() {
    List L;
    CreateList(L);

    int jumlahData = 0;
    const int MAX_DATA = 3;

    while (jumlahData < MAX_DATA) {
        infotype kendaraan;

        cout << "Masukkan nomor polisi: ";
        cin >> kendaraan.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> kendaraan.thnBuat;
        cout << endl;

        if (isNopolExist(L, kendaraan.nopol)) {
            cout << "Nomor polisi sudah terdaftar!" << endl << endl;
        } else {
            address P = alokasi(kendaraan);
            insertLast(L, P);
            jumlahData++;
        }
    }

    cout << "=== Data kendaraan yang terdaftar ===" << endl;
    printInfo(L);

    string nopolCari;
    cout << "Masukkan nomor polisi yang ingin dicari: ";
    cin >> nopolCari;

    address hasilCari = findElm(L, nopolCari);
    if (hasilCari != NULL) {
        cout << endl << "Data ditemukan:" << endl;
        cout << "nopol : " << hasilCari->info.nopol << endl;
        cout << "warna : " << hasilCari->info.warna << endl;
        cout << "tahun : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Data dengan nopol tersebut tidak ditemukan." << endl;
    }

    cout << endl;


    string nopolHapus;
    cout << "Masukkan nomor polisi yang ingin dihapus: ";
    cin >> nopolHapus;

    if (deleteByNopol(L, nopolHapus)) {
        cout << "Data berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << endl << "=== Data setelah penghapusan ===" << endl;
    printInfo(L);

    return 0;
}