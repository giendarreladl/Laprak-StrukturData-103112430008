#include <iostream>
#include "unguided-2.h"
#include "unguided-2.cpp"

using namespace std;
int main(){

    string namapel = "Struktur Data";
    string kodemapel = "STD";
    pelajaran pel = buat_pelajaran(namapel, kodemapel);
    tampilkan_pelajaran(pel);

return 0;
}