#include <iostream>
using namespace std;

// Penggunaan Address-of Operator ( & ) sebagai parameter fungsi
int ubahNilai(int &x, int y)
{
    return x = y;
}

// Penggunaan Dereference Operator ( * ) sebagai parameter fungsi
int ubahNilai(int *x, int y, int z)
{
    return *x = y;
}

struct Menu
{
    string nama;
    float harga;
};

int main()
{
    struct Address
    {
        string kota;
        string provinsi;
        string negara;
    };
    // deklarasi variabel dengan struct
    Address address1, address2;
    // mengisi value address1
    address1.kota = "Samarinda";
    address1.provinsi = "Kalimantan Timur";
    address1.negara = "Indonesia";
    // mengcopy value address1 ke address2
    address2 = address1;
    // mengganti property kota dari samarinda ke ikn
    address2.kota = "ikn";
    // value address1
    cout << address1.kota << endl;
    // value address2
    cout << address2.kota << endl;

    // ADDRESS-OF OPERATOR ( & )
    string nama = "Ridho Lawe";
    cout << &nama << " adalah alamatnya " << nama << endl;

    // DEREFERENCE OPERATOR ( * ) DAN MEMBUAT POINTER
    // berikut adalah variabel pointer bernama namaPtr
    // yang menampung alamat dari variabel nama
    // dengan begini akan ada variabel namaPtr yang memiliki value alamat
    // dari variabel nama
    string *namaPtr = &nama; // ini adalah variabel pointer
    // jika kita print namaPtr maka akan mengeluarkan output alamat dari
    // variabel nama
    cout << "Hasil dari namaPtr: " << namaPtr << endl;
    // karena namaPtr adalah pointer yang menunjuk ke nama maka namaPtr
    // bisa menggunakan value dari nama
    // dengan ini kita memanfaatkan operator Dereference ( * )
    cout << "Hasil dari *namaPtr: " << *namaPtr << endl;
    cout << endl
         << "Kesimpulannya namaPtr isi nya alamatnya nama" << endl;
    cout << "*namaPtr hasilnya value dari nama" << endl;
    cout << "Jika masih bingung bisa amati output berikut" << endl;
    cout << endl;
    cout << "Hasil/value dari nama " << nama << endl;
    cout << "Hasil/value dari alamat nama (&nama) " << &nama << endl;
    cout << "Hasil/value dari namaPtr " << namaPtr << endl;
    cout << "Hasil/value dari *namaPtr " << nama << endl;

    cout << endl;
    cout << "pointer yang menunjuk ke suatu array" << endl;
    int a[5] = {1, 2, 3, 4, 5};
    int (*aPtr)[5] = &a;
    for (int i = 0; i < 5; i++)
    {
        cout << *aPtr << endl;
    }

    cout << endl;
    cout << "Pointer yang menunjuk ke arah elemen array" << endl;
    int b[5] = {1, 2, 3, 4, 5};

    int *bPtr = b;
    for (int i = 0; i < 5; i++)
    {
        cout << bPtr << endl;
        // cout << *bPtr <<endl;
        bPtr++;
    }

    int x, y;

    x = 5;
    y = 14;
    cout << "Nilai x sebelum diubah: " << x << endl;
    // Penggunaan Address-of Operator ( & ) sebagai parameter fungsi
    ubahNilai(x, y);
    cout << "Nilai x setelah diubah: " << x << endl;

    x = 8;
    y = 12;
    cout << "Nilai x sebelum diubah: " << x << endl;
    // Penggunaan Dereference Operator ( * ) sebagai parameter fungsi
    ubahNilai(&x, y, 0);
    cout << "Nilai x setelah diubah: " << x << endl;

    Menu nasgor;
    Menu *nasgorPtr = &nasgor;
    nasgor.nama = "Nasi Goreng Cumi Hitam Pak Kris";
    nasgor.harga = 15000;

    cout << nasgor.nama << " " << nasgor.harga << endl;
    // kita bisa mengakses/manipulasi value variabel nasgor
    // melalui variabel nasgorPtr
    nasgorPtr->nama = "Nasi Goreng Mawut";
    nasgorPtr->harga = 13000;
    cout << nasgor.nama << " " << nasgor.harga << endl;
    // kalau memberi value pada atribut biasa pakai ( . )
    // kalau memberi value pada atribut dari pointer pakai ( -> )

    return 0;
}
