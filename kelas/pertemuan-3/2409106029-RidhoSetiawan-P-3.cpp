#include <iostream>
using namespace std;

struct Tanggal
{
    int hari;
    int bulan;
    int tahun;
};


struct Mahasiswa
{
    string nama;
    string nim;
    string jenis_kelamin;
    Tanggal tglLahir;
};


int main()
{
    Mahasiswa mhsBaru;
    Mahasiswa mhsLama;

    mhsBaru.nama = "Ridho";
    mhsBaru.nim = "029";
    mhsBaru.jenis_kelamin = "Pria";
    mhsBaru.tglLahir.hari = 24;
    mhsBaru.tglLahir.bulan = 4;
    mhsBaru.tglLahir.tahun = 2025;

    cout << mhsBaru.nama << endl;
    cout << mhsBaru.nim << endl;
    cout << mhsBaru.jenis_kelamin << endl;
    cout << "Tanggal Lahir: " << mhsBaru.tglLahir.hari << "/" << mhsBaru.tglLahir.bulan << "/" << mhsBaru.tglLahir.tahun << endl;

    Mahasiswa mhsKece [5];
    mhsKece[0].nama = "Jamal";
    mhsKece[2].nama = "Ujang";
    mhsKece[4].nama = "Anang";

    for (int i = 0; i < size(mhsKece); i++)
    {
        cout << mhsKece[i].nama << endl;
    }
    

    return 0;
}