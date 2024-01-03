#include <iostream>
using namespace std;

//maaf kak udah mentok hampir dapet tapi gabisa kesolve :(
int main() {
    int N;
    cout << "N = "; cin >> N;
    int middle = N / 2;
    int num = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (i < middle) {
                if (j < middle - i - 1) {
                    cout << "  ";
                } else {
                    cout << num;
                    if (j != i) {
                        cout << " ";
                    }
                    num = (num + 1) % 10;
                }
            } else {
                if (j < i - middle) {
                    cout << "  ";
                } else {
                    cout << num;
                    if (j != i) {
                        cout << " ";
                    }
                    num = (num + 1) % 10;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
