#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Karyawan {
private:
    string nama;
    string jabatan;
    int jam_lembur;
    int dinas_luar;
    int jumlah_presensi;
    long gaji_pokok;

public:
    Karyawan(string n, string j, int lembur, int dinas, int presensi) {
        nama = n;
        jabatan = j;
        jam_lembur = lembur;
        dinas_luar = dinas;
        jumlah_presensi = presensi;
        gaji_pokok = hitungGajiPokok(jabatan);
    }

    long hitungGajiPokok(string j) {
        if (j == "Teknisi" || j == "teknisi") return 1800000;
        else if (j == "RnD" || j == "rnd") return 2300000;
        else if (j == "Kepala Divisi" || j == "kepala divisi") return 2700000;
        else return 0; 
    }

    long hitungTotalGaji() {
        return gaji_pokok + (jam_lembur * 20000) + (dinas_luar * 400000) + (jumlah_presensi * 50000);
    }

    void tampilkanGaji() {
        cout << "Nama Karyawan     : " << nama << endl;
        cout << "Jabatan           : " << jabatan << endl;
        cout << "Jumlah Presensi   : " << jumlah_presensi << endl;
        cout << "Jumlah Dinas Luar : " << dinas_luar << endl;
        cout << "Jumlah Jam Lembur : " << jam_lembur << endl;
        cout << "Total Gaji        : Rp " << hitungTotalGaji() << endl;
    }
};

int main() {
    string nama, jabatan;
    int lembur, dinas, presensi;

    cout << "Masukkan Nama Karyawan: ";
    getline(cin, nama);
    cout << "Masukkan Jabatan (Teknisi/RnD/Kepala Divisi): ";
    getline(cin, jabatan);
    cout << "Masukkan Jumlah Jam Lembur: ";
    cin >> lembur;
    cout << "Masukkan Jumlah Dinas Luar: ";
    cin >> dinas;
    cout << "Masukkan Jumlah Presensi: ";
    cin >> presensi;

    // buat object Karyawan
    Karyawan k(nama, jabatan, lembur, dinas, presensi);

    // tampilkan hasil
    k.tampilkanGaji();

    return 0;
}
