#include <string>
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
using namespace std;

struct pelajaran{

    string namaMapel;
    string kodeMapel;

};
pelajaran buat_pelajaran(string namapel, string kodemapel);
void tampilkan_pelajaran(pelajaran pel);
#endif