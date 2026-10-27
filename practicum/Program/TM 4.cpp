#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Karyawan {
protected:
    string nama;
    string jabatan;
    int jam_lembur;
    int jumlah_dinas;
    int jumlah_presensi;

public:
    Karyawan(string n, string j, int lembur, int dinas, int presensi) {
        nama = n;
        jabatan = j;
        jam_lembur = lembur;
        jumlah_dinas = dinas;
        jumlah_presensi = presensi;
    }

    long gajiPokok() {
        if (jabatan == "Teknisi" || jabatan == "teknisi") return 1800000;
        else if (jabatan == "RnD" || jabatan == "rnd") return 2400000;
        else if (jabatan == "Kepala Divisi" || jabatan == "kepala divisi") return 2900000;
        else return 0;
    }
  
    long hitung_gaji(int presensi) {
        return gajiPokok() + (presensi * 60000);
    }

    long hitung_gaji(int presensi, int lembur) {
        return gajiPokok() + (presensi * 60000) + (lembur * 25000);
    }

    
    long hitung_gaji(int presensi, int lembur, int dinas) {
        if (jabatan == "Kepala Divisi" || jabatan == "kepala divisi") {
            return gajiPokok() + (presensi * 60000) + (lembur * 25000) + (dinas * 600000);
        } else {
            return hitung_gaji(presensi, lembur); 
        }
    }

    void tampilkangaji(long total) {
        cout << "Nama   : " << nama << endl;
        cout << "Jabatan: " << jabatan << endl;
        cout << "Total Gaji: Rp " << total << endl;
        cout << "==========================" << endl;
    }
};

int main() {
    Karyawan k1("Kairi", "Teknisi", 5, 0, 20);
    long total1 = k1.hitung_gaji(20); 
    k1.tampilkangaji(total1);

    Karyawan k2("Kiboyyyy", "RnD", 10, 0, 22);
    long total2 = k2.hitung_gaji(22, 10); 
    k2.tampilkangaji(total2);

    Karyawan k3("Sanzzz", "Kepala Divisi", 15, 2, 25);
    long total3 = k3.hitung_gaji(25, 15, 2); 
    k3.tampilkangaji(total3);

   //tunggu keyboard baru return 0
    cin.get();
    return 0; 
}
