#include <iostream>
using namespace std;

bool cekKabisat(int tahun) {
    if ((tahun % 400 == 0) || ((tahun % 100 != 0) && (tahun % 4 == 0))) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int tahun;
    cout << "Tahun : ";
    cin >> tahun;

    if (cekKabisat(tahun)) {
        cout << "kabisat" << endl;
    } else {
        cout << "bukan kabisat" << endl;
    }
    return 0;
}
