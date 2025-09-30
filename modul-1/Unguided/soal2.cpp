#include <iostream>
#include <string>
using namespace std;

int main() {
    string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};
    string dasar[]  = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh"};

    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n == 100) {
        cout << "Seratus";
    } 
    else if (n > 10 && n < 20) {  
        cout << dasar[n - 10] << " Belas";
    } 
    else if (n >= 20) {           
        int puluh = n / 10;
        int sisa  = n % 10;

        cout << satuan[puluh] << " Puluh";
        if (sisa) cout << " " << satuan[sisa];
    } 
    else {
        cout << dasar[n];
    }

    cout << endl;
    return 0;
}
