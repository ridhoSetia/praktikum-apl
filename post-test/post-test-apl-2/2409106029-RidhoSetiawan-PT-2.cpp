#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std;

#define MAX_MOTOR 5
int panjang = 0;

// Akun login
string akun[2] = {"ridho", "029"};

string inputUsername;
string inputPassword;

// Kapasitas Bengkel (Merek, Plat, Nomor HP)
string isi_bengkel[MAX_MOTOR][3] = {};

// Status servis motor (Menunggu, Dikerjakan, Selesai)
string status_servis[4] = {"Menunggu", "Dikerjakan", "Selesai", " "};

// Estimasi waktu selesai dalam jam
int estimasi_selesai[MAX_MOTOR] = {};

int main()
{
    system("clear");
    cout << endl;
    cout << "░█░░░█▀█░█▀▀░▀█▀░█▀█" << endl;
    cout << "░█░░░█░█░█░█░░█░░█░█" << endl;
    cout << "░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀" << endl;
    cout << endl;

    int chance = 3;
    int index = 0;
    int pilihan;

    while (chance != 0)
    {
        if (pilihan == 5)
        {
            cout << "Program berhenti" << endl;
            break;
        }

        else
        {
            cout << "Username: ";
            cin >> inputUsername;

            cout << "Password: ";
            cin >> inputPassword;
        }

        if (akun[0] == inputUsername && akun[1] == inputPassword)
        {
            cout << "Login Berhasil" << endl;
            sleep(2);
            do
            {
                system("clear");

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
                    system("clear");

                    if (panjang == 0)
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
                            for (int j = 0; j < 3; j++)
                            {
                                cout << "| " << setw(17) << left << isi_bengkel[i][j];
                            }
                            if (estimasi_selesai[i] != 0)
                            {
                                cout << "| " << estimasi_selesai[i] << setw(11) << " jam";
                            }
                            else
                            {
                                cout << "|" << setw(13) << " ";
                            }

                            if (i == 0)
                            {
                                cout << "| " << setw(14) << status_servis[0];
                            }
                            else if (i > 0 && estimasi_selesai[i] != 0)
                            {
                                cout << "| " << setw(14) << status_servis[0];
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
                                system("clear");

                                cout << "Proses servis motor " << isi_bengkel[0][0] << " sedang dilakukan" << endl;

                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       | Lama Servis | Status Servis |" << endl;
                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                // Looping untuk isi tabel
                                for (int i = 0; i < MAX_MOTOR; i++)
                                {
                                    cout << "| " << setw(3) << left << i + 1;
                                    for (int j = 0; j < 3; j++)
                                    {
                                        cout << "| " << setw(17) << left << isi_bengkel[i][j];
                                    }
                                    if (estimasi_selesai[i] != 0)
                                    {
                                        cout << "| " << estimasi_selesai[i] << setw(11) << " jam";
                                    }
                                    else
                                    {
                                        cout << "|" << setw(13) << " ";
                                    }

                                    if (i == 0)
                                    {
                                        cout << "| " << setw(14) << status_servis[1];
                                    }
                                    else if (i > 0 && estimasi_selesai[i] != 0)
                                    {
                                        cout << "| " << setw(14) << status_servis[0];
                                    }
                                    else
                                    {
                                        cout << "| " << setw(14) << " ";
                                    }
                                    cout << "|" << endl;
                                }

                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                sleep(10);

                                system("clear");
                                cout << "Motor telah selesai diservis" << endl;

                                // Header tabel
                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       | Lama Servis | Status Servis |" << endl;
                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;

                                // Looping untuk isi tabel
                                for (int i = 0; i < MAX_MOTOR; i++)
                                {
                                    cout << "| " << setw(3) << left << i + 1;
                                    for (int j = 0; j < 3; j++)
                                    {
                                        cout << "| " << setw(17) << left << isi_bengkel[i][j];
                                    }
                                    if (estimasi_selesai[i] != 0)
                                    {
                                        cout << "| " << estimasi_selesai[i] << setw(11) << " jam";
                                    }
                                    else
                                    {
                                        cout << "|" << setw(13) << " ";
                                    }

                                    if (i == 0)
                                    {
                                        cout << "| " << setw(14) << status_servis[2];
                                    }
                                    else if (i > 0 && estimasi_selesai[i] != 0)
                                    {
                                        cout << "| " << setw(14) << status_servis[0];
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

                                system("clear");

                                int index = 1;
                                if (index > 0 && index <= panjang)
                                {
                                    for (int i = index - 1; i < panjang; i++)
                                    {
                                        isi_bengkel[i][0] = isi_bengkel[i + 1][0]; // Ngegeser elemen ke kiri kek nimpa jadinya
                                        isi_bengkel[i][1] = isi_bengkel[i + 1][1];
                                        isi_bengkel[i][2] = isi_bengkel[i + 1][2];
                                        estimasi_selesai[i] = estimasi_selesai[i + 1];
                                    }
                                }

                                panjang--;

                                // Header tabel
                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       | Lama Servis | Status Servis |" << endl;
                                cout << "+----+-----------------+------------------+------------------+-------------+---------------+" << endl;

                                // Looping untuk isi tabel
                                for (int i = 0; i < MAX_MOTOR; i++)
                                {
                                    cout << "| " << setw(3) << left << i + 1;
                                    for (int j = 0; j < 3; j++)
                                    {
                                        cout << "| " << setw(17) << left << isi_bengkel[i][j];
                                    }
                                    if (estimasi_selesai[i] != 0)
                                    {
                                        cout << "| " << estimasi_selesai[i] << setw(11) << " jam";
                                    }
                                    else
                                    {
                                        cout << "|" << setw(13) << " ";
                                    }

                                    if (i == 0)
                                    {
                                        cout << "| " << setw(14) << status_servis[0];
                                    }
                                    else if (i > 0 && estimasi_selesai[i] != 0)
                                    {
                                        cout << "| " << setw(14) << status_servis[0];
                                    }
                                    else
                                    {
                                        cout << "| " << setw(14) << " ";
                                    }
                                    cout << "|" << endl;
                                }

                                cout << "+----+------------------+------------------+------------------+-------------+---------------+" << endl;
                                if (panjang == 0)
                                {
                                    system("clear");
                                    cout << "Servis dihentikan, karena tidak ada antrean motor lagi" << endl;
                                }
                            }

                            else
                            {
                                cout << "\nProses servis motor dihentikan" << endl;
                            }
                        } while (mulai[1] == 'y' && panjang != 0);
                    }

                    cin.ignore();
                    cout << "Tekan enter untuk lanjut...";
                    cin.get();
                }

                else if (pilihan == 2 && panjang < MAX_MOTOR)
                {
                    system("clear");

                    cin.ignore();
                    cout << "Input nama motor : ";
                    getline(cin, isi_bengkel[panjang][0]);
                    cout << "Input plat nomor : ";
                    getline(cin, isi_bengkel[panjang][1]);
                    cout << "Input nomor hp   : ";
                    getline(cin, isi_bengkel[panjang][2]);
                    cout << "Input lama servis: (1-5) : ";
                    cin >> estimasi_selesai[panjang];

                    cout << panjang << endl;
                    panjang++;
                    cout << endl;

                    cin.ignore();
                    cout << "Motor berhasil ditambah ke antrean" << endl;
                    cout << "Tekan enter untuk lanjut...";
                    cin.get();
                }

                else if (pilihan == 3)
                {
                    system("clear");

                    if (panjang == 0)
                    {
                        cout << "Belum ada antrean motor untuk diubah." << endl;
                    }
                    else
                    {
                        for (int i = 0; i < panjang; i++)
                        {
                            cout << "+----+------------------+------------------+------------------+" << endl;
                            cout << "| No |    Nama Motor    |    Plat Nomor    |      No HP       |" << endl;
                            cout << "+----+------------------+------------------+------------------+" << endl;

                            // Looping untuk isi tabel
                            for (int i = 0; i < MAX_MOTOR; i++)
                            {
                            cout << "| " << setw(3) << left << i + 1;
                                for (int j = 0; j < 3; j++)
                                {
                                    cout << "| " << setw(17) << left << isi_bengkel[i][j];
                                }
                                cout << "|" << endl;
                            }

                            cout << "+----+------------------+------------------+------------------+" << endl;
                        }
                        cout << "Masukkan nomor antrean, motor yang akan diubah: ";
                        cin >> index;
                        if (index > 0 && index <= panjang)
                        {
                            cin.ignore();
                            cout << "Masukkan nama motor baru: ";
                            getline(cin, isi_bengkel[index - 1][0]);
                            cout << "Nama motor berhasil diubah" << endl;

                            cout << "\nMasukkan plat nomor baru: ";
                            getline(cin, isi_bengkel[index - 1][1]);
                            cout << "Plat nomor berhasil diubah" << endl;

                            cout << "\nMasukkan nomor hp baru: ";
                            getline(cin, isi_bengkel[index - 1][2]);
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
                    system("clear");

                    if (panjang == 0)
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
                                for (int j = 0; j < 3; j++)
                                {
                                    cout << "| " << setw(17) << left << isi_bengkel[i][j];
                                }
                                cout << "|" << endl;
                            }

                            cout << "+----+------------------+------------------+------------------+" << endl;
                
                        cout << "Masukkan nomor antrean, motor yang akan dihapus: ";
                        cin >> index;
                        if (index > 0 && index <= panjang)
                        {
                            for (int i = index - 1; i < panjang - 1; i++)
                            {
                                isi_bengkel[i][0] = isi_bengkel[i + 1][0]; // Ngegeser elemen ke kiri kek nimpa jadinya
                                isi_bengkel[i][1] = isi_bengkel[i + 1][1];
                                isi_bengkel[i][2] = isi_bengkel[i + 1][2];
                            }
                            panjang--;
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

    return 0;
}
