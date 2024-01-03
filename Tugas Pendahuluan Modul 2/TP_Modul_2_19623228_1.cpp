#include <iostream>
using namespace std;

int main() {
    int ukuran;

    cout << "Masukkan jumlah anggota array yang diinginkan: ";
    cin >> ukuran;

    int arr[ukuran];
    int arr2[ukuran];
    int sum[ukuran];

    cout << "Masukkan elemen-elemen untuk array pertama:\n";
    for (int i = 0; i < ukuran; ++i) {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nMasukkan elemen-elemen untuk array kedua:\n";
    for (int i = 0; i < ukuran; ++i) {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> arr2[i];
    }

    for (int i = 0; i < ukuran; ++i) {
        sum[i] = arr[i] + arr2[i];
    }

    cout << "\nJumlah Kedua Array:\n";
    for (int i = 0; i < ukuran; ++i) {
        cout << sum[i] << " ";
    }
    cout << endl;

    return 0;
}
