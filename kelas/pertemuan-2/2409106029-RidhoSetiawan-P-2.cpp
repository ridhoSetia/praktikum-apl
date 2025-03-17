#include <iostream>
using namespace std;

int main()
{
    int nomor[3] = {5, 4, 3};
    cout << nomor[1] << endl;

    int totalByte = sizeof(nomor);
    int singleByte = sizeof(nomor[0]);
    int panjangArray = sizeof(nomor) / sizeof(nomor[0]);

    // lebih simple c++ 17 ke atas
    int panjangArray2 = size(nomor);

    for (int i = 0; i < panjangArray2; i++)
    {
        cout << nomor[i] << ", ";
    }
    
    cout << endl;
    
    // forrange
    for (int n : nomor)
    {
        cout << n << ", ";
    }

    cout << endl;

    for (int i = 2; i < 3; i++)
    {
        nomor[i] = nomor[i+1];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << nomor[i] << ", ";
    }

    cout << totalByte << endl;
    cout << singleByte << endl;
    cout << panjangArray << endl;
    cout << panjangArray2 << endl;

    // Array Create
    string buah[4] = {"nanas", "jeruk", "semangka"};
    
    // sebelum
    for (string b : buah)
    {
        cout << b << ", ";
    }

    buah[3] = "kurma";

    // Update
    buah[0] = "mangga";

    // Delete jeruk
    buah[1] = "semangka";
    buah[2] = "kurma";
    buah[3] = "";

    cout << endl;

    // sesudah
    for (string b : buah)
    {
        cout << b << ", ";
    }

    cout << "versi c++: " << __cplusplus << endl;

    return 0;
}