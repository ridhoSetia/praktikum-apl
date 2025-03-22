#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std;

#define MAX_MOTOR 5
int panjang_antrean = 0;
int panjang_akun = 0;

string inputUsername;
string inputPassword;

struct IsiBengkel
{
    string nama_motor;
    string plat_nomor;
    string nomor_hp;
};

struct Bengkel
{
    IsiBengkel detailAntrean;
};

struct ServisMotor
{
    string username;
    string password;
    string status_servis;
    int estimasi_selesai;
};

ServisMotor servis[20];
Bengkel isi_bengkel[MAX_MOTOR];

int main()
{
    system("clear || cls");

    servis[panjang_akun].username = "ridho";
    servis[panjang_akun].password = "029";
    servis[0].status_servis = "Menunggu";
    servis[1].status_servis = "Dikerjakan";
    servis[2].status_servis = "Selesai";
    servis[3].status_servis = " ";

    int pilihan_awal;
    int pilihan;

    do
    {
        if (pilihan == 5)
        {
            cout << "Program berhenti" << endl;
            break;
        }

        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "\nPilih: ";
        cin >> pilihan_awal;

        if (pilihan_awal == 1)
        {
            system("clear || cls");

            panjang_akun++;
            cout << "Username baru: ";
            cin >> inputUsername;
            cout << "Password baru: ";
            cin >> inputPassword;

            servis[panjang_akun].username = inputUsername;
            servis[panjang_akun].password = inputPassword;

            cout << "Berhasil membuat akun baru\n" << endl;

            sleep(1);

            system("clear || cls");
        }
        else if (pilihan_awal == 2)
        {
            system("clear || cls");
            cout << endl;
            cout << "░█░░░█▀█░█▀▀░▀█▀░█▀█" << endl;
            cout << "░█░░░█░█░█░█░░█░░█░█" << endl;
            cout << "░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀" << endl;
            cout << endl;

            int chance = 3;
            int index = 0;

            while (chance != 0)
            {
                if (pilihan == 5)
                {
                    break;
                }

                else
                {
                    cout << "Username: ";
                    cin >> inputUsername;

                    cout << "Password: ";
                    cin >> inputPassword;
                }

                bool validasi_akun = false; // Awalnya false
                for (int i = 0; i < 20; i++)
                {
                    if (servis[i].username == inputUsername && servis[i].password == inputPassword)
                    {
                        validasi_akun = true;
                        break; // Keluar dari loop setelah menemukan akun valid
                    }
                }
                
                if (validasi_akun == true)
                {
                    cout << "Login Berhasil" << endl;
                    sleep(2);
                    do
                    {
                        system("clear || cls");

                        cout << endl;
                        cout << "Bengkel Mas Tahir" << endl;
                        cout << endl;

                        cout << "1. Lihat antrean dan lakukan servis motor" << endl;
                        cout << "2. Tambah antrean servis motor" << endl;
                        cout << "3. Edit antrean servis motor" << endl;
                        cout << "4. Hapus antrean servis motor" << endl;
                        cout << "5. Keluar" << endl;

                        cout << "\nPilih: ";
                        cin >> pilihan;
                        cout << endl;

                        if (pilihan == 1)
                        {
                            system("clear || cls");

                            if (panjang_antrean == 0)
                            {
                                cout << "Belum ada antrean motor" << endl;
                            }
                            else
                            {
                                // Header tabel
                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       | Lama Servis | Status Servis |" << endl;
                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                // Looping untuk isi tabel
                                for (int i = 0; i < MAX_MOTOR; i++)
                                {
                                    cout << "| " << setw(3) << left << i + 1;

                                    cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nama_motor;
                                    cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.plat_nomor;
                                    cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nomor_hp;

                                    if (servis[i].estimasi_selesai != 0)
                                    {
                                        cout << "| " << servis[i].estimasi_selesai << setw(11) << " jam";
                                    }
                                    else
                                    {
                                        cout << "|" << setw(13) << " ";
                                    }

                                    if (i == 0)
                                    {
                                        cout << "| " << setw(14) << servis[0].status_servis;
                                    }
                                    else if (i > 0 && servis[i].estimasi_selesai != 0)
                                    {
                                        cout << "| " << setw(14) << servis[0].status_servis;
                                    }
                                    else
                                    {
                                        cout << "| " << setw(14) << " ";
                                    }
                                    cout << "|" << endl;
                                }

                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                string mulai;

                                do
                                {
                                    cout << "Lakukan Servis (y/t)? : ";
                                    cin >> mulai;

                                    if (mulai == "y")
                                    {
                                        system("clear || cls");

                                        cout << "Proses servis motor " << isi_bengkel[0].detailAntrean.nama_motor << " sedang dilakukan" << endl;

                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                        cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       | Lama Servis | Status Servis |" << endl;
                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                        // Looping untuk isi tabel
                                        for (int i = 0; i < MAX_MOTOR; i++)
                                        {
                                            cout << "| " << setw(3) << left << i + 1;

                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nama_motor;
                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.plat_nomor;
                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nomor_hp;

                                            if (servis[i].estimasi_selesai != 0)
                                            {
                                                cout << "| " << servis[i].estimasi_selesai << setw(11) << " jam";
                                            }
                                            else
                                            {
                                                cout << "|" << setw(13) << " ";
                                            }

                                            if (i == 0)
                                            {
                                                cout << "| " << setw(14) << servis[1].status_servis;
                                            }
                                            else if (i > 0 && servis[i].estimasi_selesai != 0)
                                            {
                                                cout << "| " << setw(14) << servis[0].status_servis;
                                            }
                                            else
                                            {
                                                cout << "| " << setw(14) << " ";
                                            }
                                            cout << "|" << endl;
                                        }

                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                        sleep(10);

                                        system("clear || cls");
                                        cout << "Motor telah selesai diservis" << endl;

                                        // Header tabel
                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                        cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       | Lama Servis | Status Servis |" << endl;
                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                        // Looping untuk isi tabel
                                        for (int i = 0; i < MAX_MOTOR; i++)
                                        {
                                            cout << "| " << setw(3) << left << i + 1;

                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nama_motor;
                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.plat_nomor;
                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nomor_hp;

                                            if (servis[i].estimasi_selesai != 0)
                                            {
                                                cout << "| " << servis[i].estimasi_selesai << setw(11) << " jam";
                                            }
                                            else
                                            {
                                                cout << "|" << setw(13) << " ";
                                            }

                                            if (i == 0)
                                            {
                                                cout << "| " << setw(14) << servis[2].status_servis;
                                            }
                                            else if (i > 0 && servis[i].estimasi_selesai != 0)
                                            {
                                                cout << "| " << setw(14) << servis[0].status_servis;
                                            }
                                            else
                                            {
                                                cout << "| " << setw(14) << " ";
                                            }
                                            cout << "|" << endl;
                                        }

                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                        cout << "Sedang update antrean" << endl;

                                        sleep(5);

                                        system("clear || cls");

                                        int index = 1;
                                        if (index > 0 && index <= panjang_antrean)
                                        {
                                            for (int i = index - 1; i < panjang_antrean; i++)
                                            {
                                                isi_bengkel[i].detailAntrean.nama_motor = isi_bengkel[i + 1].detailAntrean.nama_motor; // Ngegeser elemen ke kiri kek nimpa jadinya
                                                isi_bengkel[i].detailAntrean.plat_nomor = isi_bengkel[i + 1].detailAntrean.plat_nomor;
                                                isi_bengkel[i].detailAntrean.nomor_hp = isi_bengkel[i + 1].detailAntrean.nomor_hp;
                                                servis[i].estimasi_selesai = servis[i + 1].estimasi_selesai;
                                            }
                                        }

                                        panjang_antrean--;

                                        // Header tabel
                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                        cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       | Lama Servis | Status Servis |" << endl;
                                        cout << "+----+-----------------+------------------+------------------+-------------+---------------+" << endl;

                                        // Looping untuk isi tabel
                                        for (int i = 0; i < MAX_MOTOR; i++)
                                        {
                                            cout << "| " << setw(3) << left << i + 1;

                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nama_motor;
                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.plat_nomor;
                                            cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nomor_hp;

                                            if (servis[i].estimasi_selesai != 0)
                                            {
                                                cout << "| " << servis[i].estimasi_selesai << setw(11) << " jam";
                                            }
                                            else
                                            {
                                                cout << "|" << setw(13) << " ";
                                            }

                                            if (i == 0)
                                            {
                                                cout << "| " << setw(14) << servis[0].status_servis;
                                            }
                                            else if (i > 0 && servis[i].estimasi_selesai != 0)
                                            {
                                                cout << "| " << setw(14) << servis[0].status_servis;
                                            }
                                            else
                                            {
                                                cout << "| " << setw(14) << " ";
                                            }
                                            cout << "|" << endl;
                                        }

                                        cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                        if (panjang_antrean == 0)
                                        {
                                            system("clear || cls");
                                            cout << "Servis dihentikan, karena tidak ada antrean motor lagi" << endl;
                                        }
                                    }

                                    else
                                    {
                                        cout << "\nProses servis motor dihentikan" << endl;
                                    }
                                } while (mulai[1] == 'y' && panjang_antrean != 0);
                            }

                            cin.ignore();
                            cout << "Tekan enter untuk lanjut...";
                            cin.get();
                        }

                        else if (pilihan == 2 && panjang_antrean < MAX_MOTOR)
                        {
                            system("clear || cls");

                            cin.ignore();
                            cout << "Input nama motor : ";
                            getline(cin, isi_bengkel[panjang_antrean].detailAntrean.nama_motor);
                            cout << "Input plat nomor : ";
                            getline(cin, isi_bengkel[panjang_antrean].detailAntrean.plat_nomor);
                            cout << "Input nomor hp   : ";
                            getline(cin, isi_bengkel[panjang_antrean].detailAntrean.nomor_hp);
                            cout << "Input lama servis: (1-5) : ";
                            cin >> servis[panjang_antrean].estimasi_selesai;

                            panjang_antrean++;
                            cout << endl;

                            cin.ignore();
                            cout << "Motor berhasil ditambah ke antrean" << endl;
                            cout << "Tekan enter untuk lanjut...";
                            cin.get();
                        }

                        else if (pilihan == 3)
                        {
                            system("clear || cls");

                            if (panjang_antrean == 0)
                            {
                                cout << "Belum ada antrean motor untuk diubah." << endl;
                            }
                            else
                            {
                                for (int i = 0; i < panjang_antrean; i++)
                                {
                                    cout << "+----+------------------+------------------+------------------+" << endl;
                                    cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       |" << endl;
                                    cout << "+----+------------------+------------------+------------------+" << endl;

                                    // Looping untuk isi tabel
                                    for (int i = 0; i < MAX_MOTOR; i++)
                                    {
                                        cout << "| " << setw(3) << left << i + 1;

                                        cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nama_motor;
                                        cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.plat_nomor;
                                        cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nomor_hp;

                                        cout << "|" << endl;
                                    }

                                    cout << "+----+------------------+------------------+------------------+" << endl;
                                }
                                cout << "Masukkan nomor antrean, motor yang akan diubah: ";
                                cin >> index;
                                if (index > 0 && index <= panjang_antrean)
                                {
                                    cin.ignore();
                                    cout << "Masukkan nama motor baru: ";
                                    getline(cin, isi_bengkel[index - 1].detailAntrean.nama_motor);
                                    cout << "Nama motor berhasil diubah" << endl;

                                    cout << "\nMasukkan plat nomor baru: ";
                                    getline(cin, isi_bengkel[index - 1].detailAntrean.plat_nomor);
                                    cout << "Plat nomor berhasil diubah" << endl;

                                    cout << "\nMasukkan nomor hp baru: ";
                                    getline(cin, isi_bengkel[index - 1].detailAntrean.nomor_hp);
                                    cout << "nomor hp berhasil diubah" << endl;
                                }
                                else
                                {
                                    cout << "Nomor antrean tidak valid" << endl;
                                }
                            }

                            cin.ignore();
                            cout << "\nTekan enter untuk lanjut...";
                            cin.get();
                        }

                        else if (pilihan == 4)
                        {
                            system("clear || cls");

                            if (panjang_antrean == 0)
                            {
                                cout << "Belum ada antrean motor untuk dihapus." << endl;
                            }
                            else
                            {

                                cout << "+----+------------------+------------------+------------------+" << endl;
                                cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       |" << endl;
                                cout << "+----+------------------+------------------+------------------+" << endl;

                                // Looping untuk isi tabel
                                for (int i = 0; i < MAX_MOTOR; i++)
                                {
                                    cout << "| " << setw(3) << left << i + 1;

                                    cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nama_motor;
                                    cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.plat_nomor;
                                    cout << "| " << setw(17) << left << isi_bengkel[i].detailAntrean.nomor_hp;

                                    cout << "|" << endl;
                                }

                                cout << "+----+------------------+------------------+------------------+" << endl;

                                cout << "Masukkan nomor antrean, motor yang akan dihapus: ";
                                cin >> index;
                                if (index > 0 && index <= panjang_antrean)
                                {
                                    for (int i = index - 1; i < panjang_antrean - 1; i++)
                                    {
                                        isi_bengkel[i].detailAntrean.nama_motor = isi_bengkel[i + 1].detailAntrean.nama_motor; // Ngegeser elemen ke kiri kek nimpa jadinya
                                        isi_bengkel[i].detailAntrean.plat_nomor = isi_bengkel[i + 1].detailAntrean.plat_nomor;
                                        isi_bengkel[i].detailAntrean.nomor_hp = isi_bengkel[i + 1].detailAntrean.nomor_hp;
                                    }
                                    panjang_antrean--;
                                    cout << "Antrean berhasil dihapus" << endl;
                                }
                                else
                                {
                                    cout << "Nomor antrean tidak valid" << endl;
                                }
                            }

                            cin.ignore();
                            cout << "\nTekan enter untuk lanjut...";
                            cin.get();
                        }

                        else if (pilihan > 5 || pilihan < 1)
                        {
                            cout << "Hanya bisa memilih (1-5)" << endl;

                            cin.ignore();
                            cout << "\nTekan enter untuk lanjut...";
                            cin.get();
                        }

                    } while (pilihan != 5);
                }
                else
                {
                    chance--;
                    if (chance == 0)
                    {
                        cout << "\nMaaf, anda terlalu banyak mencoba, silahkan coba lagi nanti" << endl;
                    }
                    else
                    {
                        cout << "\nUsername atau Password salah, coba lagi" << endl;
                    }
                }
            };
        }
        else
        {
            system("clear || cls");
            cout << "Hanya bisa memilih (1/2)!\n" << endl;
        }
    } while (pilihan_awal != 1 || pilihan_awal != 2);

    return 0;
}