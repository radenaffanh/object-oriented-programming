#include <stdio.h>
#include <iostream>
using namespace std;

class karyawan{
    public:
        string nama;
        string jabatan;
        int jam_lembur;
        int jumlah_dinas;
        int jumlah_presensi;
        long gaji_pokok;
        
        karyawan(){
            nama = "";
            jabatan = "";
            jam_lembur = 0;
            jumlah_dinas = 0;
            jumlah_presensi = 0;
        }
        karyawan(string n, string j, int jamlembur, int dinas, int presensi){
            nama = n;
            jabatan = j;
            jam_lembur = jamlembur;
            jumlah_dinas = dinas;
            jumlah_presensi = presensi;
        }
        
        long gaji_pokok(string j){
            if(jabatan == "Teknisi" || jabatan == "teknisi") return 1800000;
            else if (jabatan == "RnD" || jabatan == "rnd") return 2300000;
            else if (jabatan == "Kepala Divisi" || jabatan == "kepala divisi") return 2700000;
            else return 0;
        }

        void hitung_gaji(){
            int uang_lembur = 20000;
            int uang_presensi = 50000;
            int uang_dinas = 400000;
            int total;
            total = gaji_pokok + (uang_lembur*jam_lembur) + (uang_presensi*jumlah_presensi) + (uang_dinas*jumlah_dinas);
            cout << total;
        }
};

int main(){
    karyawan k;
    cout << "Nama :";
    cin >> k.nama;

    cout << "Jabatan (Teknisi, RnD, Kepala Divisi) :";
    cin >> k.jabatan;

    cout << "Jam Lembur :";
    cin >> k.jam_lembur;

    cout << "Jumlah Dinas :";
    cin >> k.jumlah_dinas;

    cout << "Jumlah presensi :";
    cin >> k.jumlah_presensi;
}