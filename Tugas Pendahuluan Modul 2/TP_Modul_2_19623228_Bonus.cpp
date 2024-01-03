#include <iostream>
using namespace std;
//Tidak boleh membuat global variable

// fungsi untuk menghitung jumlah array
int jumlah(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {//untuk setiap i dari 0 sampai ke size-1
        total += arr[i]; // menambahkan elemen array i (looping) dan menyimpannya di variabel total
    }
    return total; // mengembalikan jumlah total yang sebelumnya ada pada loop for
}

int main() {
    int N; cin >> N;
    int arr[N]; // deklarasi array dengan n yang diinginkan user
    for (int i = 0; i < N; ++i) {cin >> arr[i];} // memasukkan elemen ke dalam array
    cout << jumlah(arr, N) << endl; // Memanggil dan mencetak fungsi yang sebelumnya dibuat untuk menghitung dan menampilkan jumlah elemen
    return 0;
}
