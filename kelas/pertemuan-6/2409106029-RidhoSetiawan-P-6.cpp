#include <iostream>
using namespace std;

const int MAKS = 100;

struct Mahasiswa
{
    string nama;
    string jurusan;
};

Mahasiswa mahasiswa[MAKS];
int jumlahData = 0;

// CREATE
void tambahMahasiswa(Mahasiswa *data, int &jumlah, string namaBaru, string jurusanBaru)
{
    if (jumlah < MAKS)
    {
        data[jumlah].nama = namaBaru;
        data[jumlah].jurusan = jurusanBaru;
        jumlah++;
        cout << "Mahasiswa ditambahkan.\n";
    }
    else
    {
        cout << "Data penuh!\n";
    }
}

// READ
void tampilMahasiswa(Mahasiswa *data, const int &jumlah)
{
    cout << "\nDaftar Mahasiswa:\n";
    for (int i = 0; i < jumlah; i++)
    {
        cout << i + 1 << ". Nama: " << data[i].nama << ", Jurusan: " << data[i].jurusan << endl;
    }
}

// UPDATE
void ubahMahasiswa(Mahasiswa *data, const int &jumlah, int index, string namaBaru, string jurusanBaru)
{
    if (index >= 0 && index < jumlah)
    {
        data[index].nama = namaBaru;
        data[index].jurusan = jurusanBaru;
        cout << "Data berhasil diubah.\n";
    }
    else
    {
        cout << "Index tidak valid!\n";
    }
}

// DELETE
void hapusMahasiswa(Mahasiswa *data, int &jumlah, int index)
{
    if (index >= 0 && index < jumlah)
    {
        for (int i = index; i < jumlah - 1; i++)
        {
            data[i] = data[i + 1];
        }
        jumlah--;
        cout << "Data berhasil dihapus.\n";
    }
    else
    {
        cout << "Index tidak valid!\n";
    }
}

// Bubble Sort
void bubbleSort(Mahasiswa *data, const int &jumlah)
{
    int n = jumlah;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (data[j].nama > data[j + 1].nama)
            {
                // Menukar elemen jika elemen sebelumnya lebih besar
                string temp = data[j].nama;
                data[j].nama = data[j + 1].nama;
                data[j + 1].nama = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(Mahasiswa *data, const int &jumlah)
{
// Loop untuk mengatur posisi elemen dari depan
for (int i = 0; i < jumlah - 1; i++)
{
    int min = i; // Anggap elemen ke-i adalah yang terkecil

    // Cari elemen terkecil di sisa array (dari i+1 sampai akhir)
    for (int j = i + 1; j < jumlah; j++)
    {
        if (data[j].nama < data[min].nama)
        {
            min = j; // Update indeks elemen terkecil
        }
    }

    // Tukar elemen terkecil dengan elemen di posisi i
    string temp = data[i].nama;
    data[i].nama = data[min].nama;
    data[min].nama = temp;
}
}

// Insertion Sort
void insertionSort(Mahasiswa *data, const int &jumlah)
{
    // Mulai dari elemen kedua, karena elemen pertama dianggap sudah terurut
    for (int i = 1; i < jumlah; i++)
    {
        string key = data[i].nama; // Simpan elemen yang mau disisipkan
        int j = i - 1;

        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && data[j].nama > key)
        {
            data[j + 1].nama = data[j].nama; // Geser elemen ke kanan
            j--;             // Geser indeks ke kiri
        }

        // Tempatkan key di posisi yang tepat
        data[j + 1].nama = key;
    }
}

int main()
{
    int pilihan;
    string nama, jurusan;
    int index;

    do
    {
        cout << "\n===== MENU CRUD MAHASISWA (Struct + Sorting) =====\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Ubah Mahasiswa\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Urutkan Mahasiswa (berdasarkan Nama)\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama: ";
            getline(cin, nama);
            cout << "Masukkan jurusan: ";
            getline(cin, jurusan);
            tambahMahasiswa(mahasiswa, jumlahData, nama, jurusan);
            break;
        case 2:
            tampilMahasiswa(mahasiswa, jumlahData);
            break;
        case 3:
            tampilMahasiswa(mahasiswa, jumlahData);
            cout << "Masukkan nomor yang ingin diubah: ";
            cin >> index;
            cin.ignore();
            cout << "Masukkan nama baru: ";
            getline(cin, nama);
            cout << "Masukkan jurusan baru: ";
            getline(cin, jurusan);
            ubahMahasiswa(mahasiswa, jumlahData, index - 1, nama, jurusan);
            break;
        case 4:
            tampilMahasiswa(mahasiswa, jumlahData);
            cout << "Masukkan nomor yang ingin dihapus: ";
            cin >> index;
            hapusMahasiswa(mahasiswa, jumlahData, index - 1);
            break;
        case 5:
            // bubbleSort(mahasiswa, jumlahData);
            // selectionSort(mahasiswa, jumlahData);
            // insertionSort(mahasiswa, jumlahData);
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}