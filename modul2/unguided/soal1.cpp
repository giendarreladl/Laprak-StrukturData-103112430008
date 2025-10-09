#include <iostream>
#define mahasiswa 5
#define matkul 3
using namespace std;


int main() {
    string nama[mahasiswa];
    float nilai[mahasiswa][matkul];
    float ratarata[mahasiswa];
    float tertinggi = 0;
    
    for(int i = 0; i < mahasiswa; i++) {
        cout << "Nama: ";
        cin >> nama[i];
        cout << "3 nilai matkul: ";
        for(int j = 0; j < matkul; j++) {
            cin >> nilai[i][j];
        }
        
        ratarata[i] = 0;
        for(int j = 0; j < matkul; j++) {
            ratarata[i] += nilai[i][j];
        }
        ratarata[i] /= matkul;
        
        if(ratarata[i] > tertinggi) {
            tertinggi = ratarata[i];
        }
    }
    
    cout << "\nHasil:\n";
    for(int i = 0; i < mahasiswa; i++) {
        cout << nama[i] << " = rata-rata: " << ratarata[i];
        if(ratarata[i] == tertinggi) cout << " (TERBAIK)";
        cout << endl;
    }
    
    return 0;
}