#include <iostream>
using namespace std;

int main() {
    int N;
    float sum = 0;
    
    cout << "jumlah bilangan : "; cin >> N;

    for (int i = 1; i <= N; ++i) {
        float num;
        cout << "bilangan " << i << " : ";
        cin >> num;
        sum += num;
    }

    if (N > 0) {
        float average = sum / N;
        cout << "RATA-RATA : " << fixed << average << endl;
    } else {
        cout << "Bilangan yang dimasukkan tidak valid" << endl;
    }
    return 0;
}
