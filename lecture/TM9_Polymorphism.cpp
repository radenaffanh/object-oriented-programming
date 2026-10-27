#include <bits/stdc++.h>
using namespace std;

// Kelas dasar 
class Pegawai {
protected:
    string nama;
    int golongan;
    double gaji_pokok;

public:
    Pegawai(string n, int g) {
        nama = n;
        golongan = g;
        gaji_pokok = 1800000; // Gaji pokok tetap
    }

    // Fungsi virtual murni
    virtual double hitunggaji() = 0;

    // Fungsi virtual menampilkan data
    virtual void tampilkaninfo() {
        cout << "Nama      : " << nama << endl;
        cout << "Golongan  : " << golongan << endl;
    }

    virtual ~Pegawai() {} // destructor virtual
};

// Kelas turunan
class PNS : public Pegawai {
public:
    PNS(string n, int g) : Pegawai(n, g) {}

    double hitunggaji() override {
        double tunjangan = 0;
        switch (golongan) {
            case 1: tunjangan = 200000; break;
            case 2: tunjangan = 300000; break;
            case 3: tunjangan = 400000; break;
            case 4: tunjangan = 500000; break;
            default: tunjangan = 0; break;
        }
        return gaji_pokok + tunjangan;
    }

    void tampilkaninfo() override {
        Pegawai::tampilkaninfo();
        cout << fixed << setprecision(0);
        cout << "Total Gaji : Rp " << hitunggaji() << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    // Polimorfisme: pointer kelas dasar menunjuk ke objek kelas turunan
    Pegawai *pegawai1 = new PNS("Andi", 1);
    Pegawai *pegawai2 = new PNS("Budi", 3);
    Pegawai *pegawai3 = new PNS("Citra", 4);

    cout << "=== Data Gaji Pegawai Negeri Sipil ===" << endl;
    pegawai1->tampilkaninfo();
    pegawai2->tampilkaninfo();
    pegawai3->tampilkaninfo();

    return 0;
}
