#include <iostream>
using namespace std;

bool prima(int angka) {
    if (angka <= 1) {
        return false;
    }
    for (int i = 2; i * i <= angka; ++i) {
        if (angka % i == 0) {
            return false; // jika angka habis dibagi oleh salah satu i, maka bukan prima
        }
    }
    return true; // jika angka tidak habis dibagi bilangan i apapun, maka bilangan tersebut prima
}

int main() {
    int angka;
    cout << "Input satu angka bulat: "; cin >> angka;

    if (prima(angka)) {
        cout << angka << " adalah angka prima" << endl;
    } else {
        cout << angka << " bukan angka prima" << endl;
    }
    return 0;
}
