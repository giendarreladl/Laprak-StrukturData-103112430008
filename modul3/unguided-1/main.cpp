#include <iostream>
#include "unguided-1.h"
#include "unguided-1.cpp"

using namespace std;

struct Mahasiswa {
string nama;
string nim;
float uts, uas, tugas, nilaiAkhir;
};

int main() {
    Mahasiswa mhs[10];
    int n;
    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;
    if (n > 10) n = 10;
    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas,
        mhs[i].tugas);
    }
    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNama : " << mhs[i].nama;
        cout << "\nNIM : " << mhs[i].nim;
        cout << "\nUTS : " << mhs[i].uts;
        cout << "\nUAS : " << mhs[i].uas;
        cout << "\nTugas : " << mhs[i].tugas;
        cout << "\nRata2 Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
return 0;
}