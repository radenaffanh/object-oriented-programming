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

    virtual ~Kendaraan() {}

    virtual string getJenis() const {
        return "Kendaraan Reguler";
    }

    int durasi() const {
        int d = jamKeluar - jamMasuk;
        if (d <= 0) d = 1;
        return d;
    }

    virtual int hitungBiaya() const {
        return durasi() * tarifPerJam;
    }
};

class KendaraanEV : public Kendaraan {
private:
    int persenDiskon;

public:
    KendaraanEV(string plat, int masuk, int keluar, int tarif, int diskon = 20) : Kendaraan(plat, masuk, keluar, tarif), persenDiskon(diskon) {}

    int hitungBiaya() const override {
        int biayaDasar = Kendaraan::hitungBiaya();
        int biayaAkhir = biayaDasar - (biayaDasar * persenDiskon / 100);
        return biayaAkhir;
    }

    string getJenis() const override {
        return "Kendaraan Listrik (EV)";
    }
};

class KendaraanNiaga : public Kendaraan {
private:
    int biayaMuatanPerJam;

public:
    KendaraanNiaga(string plat, int masuk, int keluar, int tarif, int muatan = 2000)
        : Kendaraan(plat, masuk, keluar, tarif), biayaMuatanPerJam(muatan) {}

    int hitungBiaya() const override {
        int biayaDasar = Kendaraan::hitungBiaya();
        int biayaTambahan = durasi() * biayaMuatanPerJam;
        int biayaAkhir = biayaDasar + biayaTambahan;
        return biayaAkhir;
    }

    string getJenis() const override {
        return "Kendaraan Niaga";
    }
};

void tampilkanRincian(const Kendaraan& kendaraan) {
    cout << "Jenis: " << kendaraan.getJenis() << endl 
         << "Plat: " << kendaraan.getPlatNomor()
         << " | Durasi: " << kendaraan.durasi()
         << " jam | Biaya: Rp" << kendaraan.hitungBiaya() << endl;
}

int main() {
    cout << fixed << setprecision(0);

    vector<Kendaraan*> kendaraanList;

    kendaraanList.push_back(new Kendaraan("L 1234 AA", 8, 11, 5000));
    kendaraanList.push_back(new KendaraanEV("L 5678 EV", 9, 12, 5000, 20));
    kendaraanList.push_back(new KendaraanNiaga("L 9012 NV", 10, 14, 5000, 2000));

    cout << "== RINCIAN PARKIR ==\n\n";
    int totalPendapatan = 0;

    for (const auto& kendaraan : kendaraanList) {
        tampilkanRincian(*kendaraan);
        totalPendapatan += kendaraan->hitungBiaya();
    }

    cout << "\nTotal Pendapatan Hari Ini: Rp" << totalPendapatan << endl;


    return 0;
}
