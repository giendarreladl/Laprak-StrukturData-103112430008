#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string artis;
    float waktu;
    Lagu* berikut; 
};

class Playlist {
private:
    Lagu* awal;

public:
    Playlist();

    void tambahDiAwal(string judul, string artis, float waktu);

    void tambahDiAkhir(string judul, string artis, float waktu);

    void sisipSetelahKe3(string judul, string artis, float waktu);

    void hapusLagu(string judul);

    void tampilkanDaftar();
};

#endif
