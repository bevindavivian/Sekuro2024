//NIM/Nama  : 19623228/Bevinda Vivian
//Tanggal   : 11 November 2023
//Deskripsi : Membuat Program Penerbangan Luar Angkasa Berdasarkan Masukan Kode Pesawat dari User

//Catatan   : Halo kak, sebelumnya mohon maaf, saya sudah mencoba menamakan file sesuai format yaitu TP Modul X_NIM_NAMA
//Namun, saat saya coba debug/run tidak bisa dirun sehingga saya menggunakan underscore untuk setiap katanya, terima kasih kak.

//KAMUS
//pesawat: character
//kondisi: bool
//i      : integer

//ALGORITMA
#include <iostream>
using namespace std;

int main() {
    char pesawat; //mendefinisikan variabel terlebih dahulu, karna inputnya berupa kode satu abjad, maka kita gunakan char
    bool kondisi=true; //mendefinisikan variabel untuk keperluan looping nantinya

    while (kondisi) {
        cout << "Masukkan jenis pesawat (a/b/o): ";
        cin >> pesawat;

        if (pesawat == 'a') {
            for (int i = 3; i > 0; i--) { //jika masukan user adalah 'a', maka akan dicetak i dari 3 sampai 1 (cout)
                cout << i << endl;
            }
            cout << "PESAWAT A BERANGKAT" << endl; //mencetak juga bahwa pesawat A berangkat
        } else if (pesawat == 'b') {
            for (int i = 5; i > 0; i--) {//jika masukan user adalah 'b', maka akan dicetak i dari 5 sampai 1 (cout)
                cout << i << endl;
            }
            cout << "PESAWAT B BERANGKAT" << endl; //mencetak juga bahwa pesawat B berangkat
        } else if (pesawat == 'o') {
            cout << "PENERBANGAN DITUTUP" << endl; //jika masukan user adalah 'o', maka akan dicetak penerbangan ditutup
            kondisi=false; //sehingga kondisi yang di awalnya true untuk while loop, akan kita ubah menjadi false
            // pada kondisi ini code akan selesai dan keluar dari while loop
        } else {
            cout << "INPUT TIDAK VALID" << endl; //jika masukan user selain 'a', 'b', dan 'o', maka akan dicetak input tidak valid
            //selama user belum memasukkan 'o' maka loop akan terus berjalan dan selalu meminta masukan user.
        }
    }
    return 0;
}