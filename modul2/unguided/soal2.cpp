#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah bilangan: ";
    cin >> N;

    int *ptr = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "Masukkan bilangan ke-" << (i+1) << ": ";
        cin >> ptr[i];
    }

    int jumlah = 0;
    int max = ptr[0];
    int min = ptr[0];

    for (int i = 1; i < N; i++) {
        jumlah += ptr[i];
        if (ptr[i] > max) {
            max = ptr[i];
        }
        if (ptr[i] < min) {
            min = ptr[i];
        }
    }

    cout << "\nHasil:" << endl;
    cout << "Jumlah: " << jumlah << endl;
    cout << "Nilai max: " << max << endl;
    cout << "Nilai min: " << min << endl;

    delete[] ptr;
    return 0;
}