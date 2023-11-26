#include <iostream>

using namespace std;

class LinearLine
{
private:
    float x1;
    float y1;
    float x2;
    float y2;

public:
    LinearLine(float x1, float y1, float x2, float y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    float gradient() {
        return (this->y2 - this->y1)/(this->x2 - this->x1);
    }
    float y_intercept() {
        return this->gradient()*(0-this->x1) + this->y1;
    }
    void operator + (float a) {
        this->x1 += a;
        this->x2 += a;
    }
    void printEquation() {
        cout << "y = " << this->gradient() << "x + " << this->y_intercept() << endl;
    }
    void printPoints() {
        cout <<endl << "(x1, y1) = ("<< this->x1 <<", "<< this->y1 <<")" << endl; 
        cout << "(x2, y2) = ("<< this->x2 <<", "<< this->y2 <<")" << endl; 
    }
};

int main() {
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f);//inisialisasi objek line
    int a = 3;// nilai banyaknya penggeseran pada persamaan linear
    line.printPoints();
    cout << "Sehingga didapatkan" << endl;
    cout << "gradient = " << line.gradient() << endl;
    cout << "y_intercept = " << line.y_intercept() << endl;
    line.printEquation();
    cout << endl;
    cout << "Setelah digeser sejauh a, didapatkan persamaan baru:" << endl;
    line + a;
    line.printEquation();
    return 0;
}