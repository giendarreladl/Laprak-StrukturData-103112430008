#include "Playlist.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    Playlist daftarLagu;
    int menu;
    string judul, artis;
    float waktu;

    do {
        cout << "\n=== MENU PLAYLIST ===\n";
        cout << "1. Tambah lagu di awal\n";
        cout << "2. Tambah lagu di akhir\n";
        cout << "3. Sisip lagu setelah lagu ke-3\n";
        cout << "4. Hapus lagu berdasarkan judul\n";
        cout << "5. Lihat daftar lagu\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore(); // menghapus newline agar getline tidak terlewat

        switch (menu) {
            case 1:
                cout << "Judul lagu   : ";
                getline(cin, judul);
                cout << "Artis        : ";
                getline(cin, artis);
                cout << "Durasi (menit): ";
                cin >> waktu;
                daftarLagu.tambahDiAwal(judul, artis, waktu);
                break;

            case 2:
                cout << "Judul lagu   : ";
                getline(cin, judul);
                cout << "Artis        : ";
                getline(cin, artis);
                cout << "Durasi (menit): ";
                cin >> waktu;
                daftarLagu.tambahDiAkhir(judul, artis, waktu);
                break;

            case 3:
                cout << "Judul lagu   : ";
                getline(cin, judul);
                cout << "Artis        : ";
                getline(cin, artis);
                cout << "Durasi (menit): ";
                cin >> waktu;
                daftarLagu.sisipSetelahKe3(judul, artis, waktu);
                break;

            case 4:
                cout << "Masukkan judul lagu yang ingin dihapus: ";
                getline(cin, judul);
                daftarLagu.hapusLagu(judul);
                break;

            case 5:
                daftarLagu.tampilkanDaftar();
                break;

            case 0:
                cout << "Terima kasih! Program selesai.\n";
                break;

            default:
                cout << "Menu tidak tersedia, coba lagi.\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // mencegah input nyangkut
    } while (menu != 0);

    return 0;
}
