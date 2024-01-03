#include <iostream>

class Matrix {
private:
    int baris;
    int kolom;
    double** data;

public:
    Matrix(double** data, int baris, int kolom) : baris(baris), kolom(kolom) {
        this->data = new double*[baris];
        for (int i = 0; i < baris; ++i) {
            this->data[i] = new double[kolom];
            for (int j = 0; j < kolom; ++j) {
                this->data[i][j] = data[i][j];
            }
        }
    }

    Matrix(int baris, int kolom) : baris(baris), kolom(kolom) {
        this->data = new double*[baris];
        for (int i = 0; i < baris; ++i) {
            this->data[i] = new double[kolom];
            for (int j = 0; j < kolom; ++j) {
                this->data[i][j] = 0; // Menginisialisasi dengan nilai 0
            }
        }
    }

    Matrix(const Matrix& other) : baris(other.baris), kolom(other.kolom) {
        this->data = new double*[baris];
        for (int i = 0; i < baris; ++i) {
            this->data[i] = new double[kolom];
            for (int j = 0; j < kolom; ++j) {
                this->data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < baris; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void display() const {
        for (int i = 0; i < baris; ++i) {
            for (int j = 0; j < kolom; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (this->baris != other.baris || this->kolom != other.kolom) {
            std::cerr << "The matrix dimension is not valid!" << std::endl;
            return Matrix(1, 1); // Return matriks 1x1 dengan nilai 0
        }

        Matrix hasil(this->baris, this->kolom);
        for (int i = 0; i < this->baris; ++i) {
            for (int j = 0; j < this->kolom; ++j) {
                hasil.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }

        return hasil;
    }

    Matrix operator-(const Matrix& other) const {
        if (this->baris != other.baris || this->kolom != other.kolom) {
            std::cerr << "The matrix dimension is not valid!" << std::endl;
            return Matrix(1, 1); // Return matriks 1x1 dengan nilai 0
        }

        Matrix hasil(this->baris, this->kolom);
        for (int i = 0; i < this->baris; ++i) {
            for (int j = 0; j < this->kolom; ++j) {
                hasil.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }

        return hasil;
    }

    Matrix operator*(const Matrix& other) const {
        if (this->kolom != other.baris) {
            std::cerr << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second." << std::endl;
            return Matrix(1, 1);                
        }

        Matrix hasil(this->baris, other.kolom);
        for (int i = 0; i < this->baris; ++i) {
            for (int j = 0; j < other.kolom; ++j) {
                double sum = 0;
                for (int k = 0; k < this->kolom; ++k) {
                    sum += this->data[i][k] * other.data[k][j];
                }
                hasil.data[i][j] = sum;
            }
        }

        return hasil;
    }
};

// int main() {
//     double arr1[2][3] = {{1, 2, 3}, {2, 3, 1}};
//     double arr2[3][3] = {{0, 2, 4}, {1, 2, 5}, {8, 2, 1.2}};

//     Matrix A(reinterpret_cast<double**>(arr1), 2, 3);
//     Matrix B(reinterpret_cast<double**>(arr2), 3, 3);
//     Matrix C(2, 3);

//     std::cout << "Matrix A\n";
//     A.display();
//     std::cout << "Matrix B\n";
//     B.display();
//     std::cout << "Matrix C\n";
//     C.display();
//     std::cout << '\n';

//     Matrix C1 = A + C;
//     std::cout << "Matrix C1\n";
//     C1.display();
//     std::cout << '\n';

//     Matrix C2 = A - C;
//     std::cout << "Matrix C2\n";
//     C2.display();
//     std::cout << '\n';

//     Matrix C3 = A * B;
//     std::cout << "Matrix C3\n";
//     C3.display();
//     std::cout << '\n';

//     Matrix C4 = B * A;
//     std::cout << "Matrix C4\n";
//     C4.display();
//     std::cout << '\n';

//     return 0;
// }