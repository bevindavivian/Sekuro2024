#include <iostream>
#include <iomanip>
using namespace std;

const float PI = 3.14; 

float luas(float r) {
    return PI * r * r; 
}

int main() {
    cout << fixed << setprecision(2); //
    cout << luas(3) << endl; 
    cout << luas(5.5) << endl; 

    return 0;
}
