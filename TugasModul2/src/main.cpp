#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

struct Coordinate {
    double x;
    double y;
};

vector<Coordinate> rekam;
int rekamIndex = -1;

Coordinate posisi = {0.0, 0.0};

void displayMenu() {
    cout << "Program Simulasi Drone Bev" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Lokasi Drone" << endl;
    cout << "2. Gerakkan Drone" << endl;
    cout << "3. Gerakkan dengan Kecepatan dan Waktu" << endl;
    cout << "4. Undo" << endl;
    cout << "5. Redo" << endl;
    cout << "6. Simpan Koordinat Terakhir" << endl;
    cout << "7. Muat Koordinat Terakhir" << endl;
    cout << "8. Keluar" << endl;
    cout << "Pilih opsi: ";
}

void lokasi() {
    cout << "Lokasi => (" << fixed << setprecision(2) << posisi.x << ", " << posisi.y << ")" << endl;
}

void gerak(double x, double y) {
    rekam.push_back(posisi);
    rekamIndex++;
    posisi.x += x;
    posisi.y += y;
    cout << "Drone bergerak ke (" << posisi.x << ", " << posisi.y << ")" << endl;
}

void gerak_2(double v, double t, double theta) {
    double radian = theta * (M_PI / 180.0);
    double x = v * t * cos(radian);
    double y = v * t * sin(radian);
    gerak(x, y);
}

void undo() {
    if (rekamIndex >= 0) {
        posisi = rekam[rekamIndex];
        rekamIndex--;
        cout << "Undo berhasil :)" << endl;
    } else {
        cout << "Tidak dapat melakukan undo :(" << endl;
    }
}

void redo() {
    if (rekamIndex < static_cast<int>(rekam.size()) - 1) {
        rekamIndex++;
        posisi = rekam[rekamIndex];
        cout << "Redo berhasil :)" << endl;
    } else {
        cout << "Tidak dapat melakukan redo :(" << endl;
    }
}

void save() {
    ofstream file("drone_bev.txt");
    if (file.is_open()) {
        file << posisi.x << " " << posisi.y << endl;
        file.close();
        cout << "Koordinat berhasil disimpan!" << endl;
    } else {
        cout << "Gagal menyimpan koordinat :(" << endl;
    }
}

void load() {
    ifstream file("drone_bev.txt");
    if (file.is_open()) {
        file >> posisi.x >> posisi.y;
        file.close();
        cout << "Koordinat berhasil dimuat!" << endl;
    } else {
        cout << "Gagal memuat koordinat :(" << endl;
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                lokasi();
                break;
            case 2:
                double pindahX, pindahY;
                cout << "Masukkan perpindahan x: ";
                cin >> pindahX;
                cout << "Masukkan perpindahan y: ";
                cin >> pindahY;
                gerak(pindahX, pindahY);
                break;
            case 3:
                double kecepatan, waktu, sudut;
                cout << "Masukkan kecepatan (meter/s): ";
                cin >> kecepatan;
                cout << "Masukkan waktu (detik): ";
                cin >> waktu;
                cout << "Masukkan sudut theta dari horizontal (derajat): ";
                cin >> sudut;
                gerak_2(kecepatan, waktu, sudut);
                break;
            case 4:
                undo();
                break;
            case 5:
                redo();
                break;
            case 6:
                save();
                break;
            case 7:
                load();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program simulasi drone inii. <3 <3 <3" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali yaa! :)" << endl;
        }
    } while (choice != 8);

    return 0;
}
