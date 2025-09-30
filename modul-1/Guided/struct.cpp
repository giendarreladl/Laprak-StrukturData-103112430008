#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama;
    string NIM;
};

int main(){
    mahasiswa mhs;
    mhs.nama = "Gien";
    mhs.NIM = "103112430008";

    cout << "Nama : "<< mhs.nama << endl 
    << "NIM :" << mhs.NIM;
}