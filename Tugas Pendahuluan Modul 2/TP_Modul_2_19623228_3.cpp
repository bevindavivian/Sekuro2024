#include <iostream> 
using namespace std; 
int main(){ 
    int a = 10; 
    int b = 20; 
    int* pa = &a; 
    int* pb = &b; 
    int** ppa = &pa; 
    int** ppb = &pb; 
 
    // Asumsikan address dari a adalah 0x111111 
    // Asumsikan address dari b adalah 0x222222 
    // Asumsikan address dari pa adalah 0x333333 
    // Asumsikan address dari pb adalah 0x444444 
    cout<<a<<endl; //Mencetak nilai variabel 'a' yang bernilai 10 dan bertipe integer
    cout<<&a<<endl; //Mencetak alamat memori dari variabel a yang diasumsikan 0x111111
    cout<<pb<<endl; //Mencetak alamat memori yang disimpan oleh pointer pb yang diasumsikan 0x444444
    cout<<ppa<<endl; //Mencetak alamat memori yang disimpan oleh pointer ppa yang diasumsikan 0x333333
 
    cout<<*pa<<endl; //Mencetak nilai dari variabel yang ditunjuk oleh pointer pa, yaitu nilai dari variabel a, 10
    cout<<*ppb<<endl; //Mencetak nilai dari variabel yang ditunjuk oleh pointer yang ditunjuk oleh ppb, yaitu nilai dari variabel pb yang diasumsikan 0x444444.
    cout<<**ppa<<endl; //Mencetak   nilai dari variabel yang ditunjuk oleh pointer yang ditunjuk oleh ppa, yaitu nilai dari variabel a, 10.
 
    cout<<*pb * **ppb<<endl; //Mengalikan nilai dari variabel yang ditunjuk oleh pointer pb dengan nilai dari variabel yang ditunjuk oleh pointer yang ditunjuk oleh ppb, yaitu 20 dikali 20, menghasilkan 400.
}