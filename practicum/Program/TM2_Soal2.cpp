#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama;
    string nim;
    double nilai;

public:
    void isidata(string n, string NIM, double nli) {
        nama = n;
        nim = NIM;
        nilai = nli;
    }

    void lihatdata() {
        cout << "\n=== Data Mahasiswa ===" << endl;
        cout << "Nama : " << nama << endl;
        cout << "NIM  : " << nim << endl;
        cout << "Nilai: " << nilai << endl;
    }
    void ubahnilai(double score) {
        nilai = score;
        cout << "Nilai berhasil diubah menjadi: " << nilai << endl;
    }
};

int main() {
    Mahasiswa mhs;
    int pilihan;
    string nama, nim;
    double nilai;

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Isi Data Mahasiswa" << endl;
        cout << "2. Lihat Data Mahasiswa" << endl;
        cout << "3. Ubah Nilai" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan Nama : ";
            cin.ignore(); 
            getline(cin, nama);
            cout << "Masukkan NIM  : ";
            getline(cin, nim);
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            mhs.isidata(nama, nim, nilai);
            break;
        case 2:
            mhs.lihatdata();
            break;
        case 3:
            cout << "Masukkan Nilai Baru: ";
            cin >> nilai;
            mhs.ubahnilai(nilai);
            break;
        case 4:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
