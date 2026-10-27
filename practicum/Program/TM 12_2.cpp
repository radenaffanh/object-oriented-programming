#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

string konversiNilai(float nilai) {
    if (nilai < 0 || nilai > 100)
        throw out_of_range("Nilai harus antara 0 - 100!");

    if (nilai >= 75) return "A (4.0)";
    else if (nilai >= 70) return "AB (3.5)";
    else if (nilai >= 65) return "B (3.0)";
    else if (nilai >= 60) return "BC (2.5)";
    else if (nilai >= 55) return "C (2.0)";
    else if (nilai >= 40) return "D (1.0)";
    else return "E (0.0)";
}

int main() {
    string mataKuliah, nama, nim;
    float nilai;

    cout << "=== Konversi Nilai Mahasiswa ===" << endl;
    cout << "Masukkan Mata kuliah : ";
    getline(cin, mataKuliah);
    cout << "Masukkan Nama Mahasiswa : ";
    getline(cin, nama);
    cout << "Masukkan NIM Mahasiswa  : ";
    getline(cin, nim);

    while (true) {
        try {
            cout << "\nMasukkan nilai (0-100): ";
            cin >> nilai;

            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka!");
            }

            string hasil = konversiNilai(nilai);

            cout << "\n=== HASIL KONVERSI ===" << endl;
            cout << "Mata Kuliah : " << mataKuliah << endl;
            cout << "Nama : " << nama << endl;
            cout << "NIM  : " << nim << endl;
            cout << "Nilai Angka : " << nilai << endl;
            cout << "Nilai Huruf : " << hasil << endl;
            break; 
        }
        catch (invalid_argument &e) {
            cerr << "Kesalahan input: " << e.what() << endl;
        }
        catch (out_of_range &e) {
            cerr << "Kesalahan rentang nilai: " << e.what() << endl;
        }
        catch (...) {
            cerr << "Terjadi kesalahan yang tidak diketahui." << endl;
        }
        cout << "Silakan coba lagi.\n" << endl;
    }

    return 0;
}
