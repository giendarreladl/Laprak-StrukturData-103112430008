#include "Playlist.h"
#include <iostream>
using namespace std;

Playlist::Playlist() {
    awal = nullptr; // playlist kosong saat pertama kali dibuat
}

void Playlist::tambahDiAwal(string judul, string artis, float waktu) {
    // Membuat node baru dan menghubungkannya ke awal
    Lagu* baru = new Lagu{judul, artis, waktu, awal};
    awal = baru;
}

void Playlist::tambahDiAkhir(string judul, string artis, float waktu) {
    Lagu* baru = new Lagu{judul, artis, waktu, nullptr};

    if (awal == nullptr) {
        awal = baru;
        return;
    }

    Lagu* bantu = awal;
    while (bantu->berikut != nullptr)
        bantu = bantu->berikut;
    bantu->berikut = baru;
}

void Playlist::sisipSetelahKe3(string judul, string artis, float waktu) {
    Lagu* bantu = awal;
    int posisi = 1;

    while (bantu != nullptr && posisi < 3) {
        bantu = bantu->berikut;
        posisi++;
    }

    if (bantu != nullptr) {
        Lagu* baru = new Lagu{judul, artis, waktu, bantu->berikut};
        bantu->berikut = baru;
    } else {
        cout << "Jumlah lagu kurang dari tiga, penyisipan gagal.\n";
    }
}

void Playlist::hapusLagu(string judul) {
    if (awal == nullptr) {
        cout << "Playlist masih kosong.\n";
        return;
    }

    // Jika lagu yang dihapus berada di awal
    if (awal->judul == judul) {
        Lagu* hapus = awal;
        awal = awal->berikut;
        delete hapus;
        cout << "Lagu \"" << judul << "\" telah dihapus.\n";
        return;
    }

    // Mencari lagu di tengah/akhir
    Lagu* bantu = awal;
    while (bantu->berikut != nullptr && bantu->berikut->judul != judul)
        bantu = bantu->berikut;

    if (bantu->berikut == nullptr) {
        cout << "Lagu dengan judul \"" << judul << "\" tidak ditemukan.\n";
    } else {
        Lagu* hapus = bantu->berikut;
        bantu->berikut = hapus->berikut;
        delete hapus;
        cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
    }
}

void Playlist::tampilkanDaftar() {
    if (awal == nullptr) {
        cout << "Tidak ada lagu di playlist.\n";
        return;
    }

    Lagu* bantu = awal;
    int nomor = 1;
    while (bantu != nullptr) {
        cout << nomor++ << ". Judul: " << bantu->judul
             << " | Artis: " << bantu->artis
             << " | Durasi: " << bantu->waktu << " menit\n";
        bantu = bantu->berikut;
    }
}
