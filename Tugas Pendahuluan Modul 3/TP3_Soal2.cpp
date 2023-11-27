#include <iostream>

using namespace std;

class Shape
{
private:
    float area;
    float keliling;
    
public:
    virtual float calculateArea() { return 0; }
    virtual float calculateKeliling() { return 0; }
};

class Rectangle : public Shape
{
private:
    float width;
    float length;
public:
    Rectangle(float width, float length) {
        this->width = width;
        this->length = length;
    }
    float calculateArea() {
        return width*length;
    }
    float calculateKeliling() {
        return 2*(width+length);
    }
};

int main()
{
    Rectangle rect(5.0, 4.0);
    Shape* shape1 = &rect;
    float A = shape1->calculateArea();
    float K = shape1->calculateKeliling();

    cout << "Luasnya adalah: " << A << endl;
    cout << "Kelilingnya adalah: " << K << endl;

    return 0;
}