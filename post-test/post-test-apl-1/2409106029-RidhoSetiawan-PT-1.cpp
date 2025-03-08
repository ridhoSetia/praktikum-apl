#include <iostream>
using namespace std;

string username = "ridho";
string password = "029";

string inputUsername;
string inputPassword;

int main()
{
    system("clear");
    cout << endl;
    cout << "░█░░░█▀█░█▀▀░▀█▀░█▀█" << endl;
    cout << "░█░░░█░█░█░█░░█░░█░█" << endl;
    cout << "░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀" << endl;
    cout << endl;

    int chance = 3;
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

        if (username == inputUsername && password == inputPassword)
        {
            do
            {
                system("clear");
                cout << endl;
                cout << "░█▄█░█▀▀░█▀█░█░█░" << endl;
                cout << "░█░█░█▀▀░█░█░█░█░" << endl;
                cout << "░▀░▀░▀▀▀░▀░▀░▀▀▀░" << endl;
                cout << endl;

                cout << "1. Konversi Celcius ke Fahrenheit, Reamur, dan Kelvin" << endl;
                cout << "2. Konversi Fahrenheit ke Celcius, Reamur, dan Kelvin" << endl;
                cout << "3. Konversi Reamur ke Celcius, Fahrenheit, dan Kelvin" << endl;
                cout << "4. Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur" << endl;
                cout << "5. Keluar" << endl;

                cout << "\nPilih: ";
                cin >> pilihan;
                cout << endl;

                if (pilihan == 1)
                {
                    system("clear");

                    float celcius;
                    cout << "Input Celcius: ";
                    cin >> celcius;
                    cout << endl;

                    float F = (celcius * 9 / 5) + 32;
                    float R = celcius * 4 / 5;
                    float K = celcius + 273.15;

                    cout << "Fahrenheit : " << F << " °F" << endl;
                    cout << "Reamur     : " << R << " °R" << endl;
                    cout << "Kelvin     : " << K << " K" << endl;

                    cin.ignore(); // Membersihkan karakter newline dari buffer
                    cout << "Tekan enter untuk lanjut...";
                    cin.get();
                }

                else if (pilihan == 2)
                {
                    system("clear");

                    float fahrenheit;
                    cout << "Input Fahrenheit: ";
                    cin >> fahrenheit;
                    cout << endl;

                    float C = (fahrenheit - 32) * 5 / 9;
                    float R = (fahrenheit - 32) * 4 / 9;
                    float K = (fahrenheit - 32) * 5 / 9 + 273.15;

                    cout << "Celcius : " << C << " °C" << endl;
                    cout << "Reamur  : " << R << " °R" << endl;
                    cout << "Kelvin  : " << K << " K" << endl;

                    cin.ignore(); // Membersihkan karakter newline dari buffer
                    cout << "Tekan enter untuk lanjut...";
                    cin.get();
                }

                else if (pilihan == 3)
                {
                    system("clear");

                    float reamur;
                    cout << "Input Reamur: ";
                    cin >> reamur;
                    cout << endl;

                    float C = reamur * 5 / 4;
                    float F = (reamur * 9 / 4) + 32;
                    float K = (reamur * 5 / 4) + 273.15;

                    cout << "Celcius    : " << C << " °C" << endl;
                    cout << "Fahrenheit : " << F << " °F" << endl;
                    cout << "Kelvin     : " << K << " K" << endl;

                    cin.ignore(); // Membersihkan karakter newline dari buffer
                    cout << "Tekan enter untuk lanjut...";
                    cin.get();
                }

                else if (pilihan == 4)
                {
                    system("clear");

                    float kelvin;
                    cout << "Input Kelvin: ";
                    cin >> kelvin;
                    cout << endl;

                    float C = kelvin - 273.15;
                    float F = (kelvin - 273.15) * 9 / 5 + 32;
                    float R = (kelvin - 273.15) * 4 / 5;

                    cout << "Celcius    : " << C << " °C" << endl;
                    cout << "Fahrenheit : " << F << " °F" << endl;
                    cout << "Reamur     : " << R << " °R" << endl;

                    cin.ignore(); // Membersihkan karakter newline dari buffer
                    cout << "Tekan enter untuk lanjut...";
                    cin.get();
                }

                else if (pilihan > 5)
                {
                    cout << "Hanya bisa memilih (1-5)" << endl;

                    cin.ignore(); // Membersihkan karakter newline dari buffer
                    cout << "Tekan enter untuk lanjut...";
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
