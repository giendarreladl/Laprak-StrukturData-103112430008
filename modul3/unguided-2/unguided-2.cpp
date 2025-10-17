#include <iostream>
#include "unguided-2.h"
using namespace std;
pelajaran buat_pelajaran(string namapel, string kodemapel){

    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodemapel;

return pel;
}
void tampilkan_pelajaran(pelajaran pel){
    
    cout << "Nama Mata Pelajaran: " << pel.namaMapel << endl;
    cout << "Nilai: " << pel.kodeMapel << endl;
}