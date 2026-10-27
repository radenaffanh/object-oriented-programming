#include <bits/stdc++.h>
using namespace std;

class Kendaraan {
private:
    string platNomor;
    int jamMasuk;
    int jamKeluar;
    int tarifPerJam;

public:
    Kendaraan(string plat, int masuk, int keluar, int tarif) : platNomor(plat), jamMasuk(masuk), jamKeluar(keluar), tarifPerJam(tarif) {}

    void setPlatNomor(string p) { platNomor = p; }
    void setJamMasuk(int j) { jamMasuk = j; }
    void setJamKeluar(int j) { jamKeluar = j; }
    void setTarifPerJam(int t) { tarifPerJam = t; }

    string getPlatNomor() const { return platNomor; }
    int getJamMasuk() const { return jamMasuk; }
    int getJamKeluar() const { return jamKeluar; }
    int getTarifPerJam() const { return tarifPerJam; }

    int durasi() const {
        int d = jamKeluar - jamMasuk;
        if (d <= 0) d = 1;
        return d;
    }

    int hitungBiaya() const {
        return durasi() * tarifPerJam;
    }
};

class KendaraanEV : public Kendaraan {
private:
    int persenDiskon;

public:
    KendaraanEV(string plat, int masuk, int keluar, int tarif, int diskon = 20) : Kendaraan(plat, masuk, keluar, tarif), persenDiskon(diskon) {}

    int hitungBiaya() {
        int biayaDasar = Kendaraan::hitungBiaya();
        int biayaAkhir = biayaDasar - (biayaDasar * persenDiskon / 100);
        return biayaAkhir;
    }
};

class KendaraanNiaga : public Kendaraan {
private:
    int biayaMuatanPerJam;

public:
    KendaraanNiaga(string plat, int masuk, int keluar, int tarif, int muatan = 2000)
        : Kendaraan(plat, masuk, keluar, tarif), biayaMuatanPerJam(muatan) {}


    int hitungBiaya() {
        int biayaDasar = Kendaraan::hitungBiaya();
        int biayaTambahan = durasi() * biayaMuatanPerJam;
        int biayaAkhir = biayaDasar + biayaTambahan;
        return biayaAkhir;
    }
};

int main() {
    cout << fixed << setprecision(0);

    Kendaraan k1("L 1234 AA", 8, 11, 5000);              
    KendaraanEV k2("L 5678 EV", 9, 12, 5000, 20);        
    KendaraanNiaga k3("L 9012 NV", 10, 14, 5000, 2000); 

    cout << "=== RINCIAN PARKIR ===\n";
    int totalPendapatan = 0;

    // Kendaraan biasa
    cout << "Plat: " << k1.getPlatNomor()
         << " | Durasi: " << k1.durasi()
         << " jam | Biaya: Rp" << k1.hitungBiaya() << endl;
    totalPendapatan += k1.hitungBiaya();

    // Kendaraan EV
    cout << "Plat: " << k2.getPlatNomor()
         << " | Durasi: " << k2.durasi()
         << " jam | Biaya: Rp" << k2.hitungBiaya() << endl;
    totalPendapatan += k2.hitungBiaya();

    // Kendaraan Niaga
    cout << "Plat: " << k3.getPlatNomor()
         << " | Durasi: " << k3.durasi()
         << " jam | Biaya: Rp" << k3.hitungBiaya() << endl;
    totalPendapatan += k3.hitungBiaya();

    cout << "\nTotal Pendapatan Hari Ini: Rp" << totalPendapatan << endl;

    return 0;
}
