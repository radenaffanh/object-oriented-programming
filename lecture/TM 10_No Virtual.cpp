#include <bits/stdc++.h>
using namespace std;

class Buku {
private:
    string id;
    string judul;
    string penerbit;

public:
    Buku(string id, string judul, string penerbit) {
        this->id = id;
        this->judul = judul;
        this->penerbit = penerbit;
    }

    string getId() { return id; }
    string getJudul() { return judul; }
    string getPenerbit() { return penerbit; }

    // Tidak ada keyword "virtual"
    int lamaPinjam() { return 7; }
    double denda(int hariTerlambat) const { return 1000 * hariTerlambat; }
    string tipe() const { return "Buku"; }
};

class BukuReferensi : public Buku {
public:
    BukuReferensi(string id, string judul, string penerbit)
        : Buku(id, judul, penerbit) {}

    int lamaPinjam() { return 0; }
    double denda(int) const { return 0.0; }
    string tipe() const { return "Referensi"; }
};

class BukuReguler : public Buku {
public:
    BukuReguler(string id, string judul, string penerbit)
        : Buku(id, judul, penerbit) {}

    int lamaPinjam() { return 7; }
    double denda(int hariTerlambat) const { return 1000 * hariTerlambat; }
    string tipe() const { return "Reguler"; }
};

class BukuLangka : public Buku {
private:
    bool izinKhusus;

public:
    BukuLangka(string id, string judul, string penerbit)
        : Buku(id, judul, penerbit), izinKhusus(true) {}

    int lamaPinjam() { return 3; }
    double denda(int hariTerlambat) const { return 2500 * hariTerlambat; }
    string tipe() const { return "Langka"; }
};

void printInfoPinjam(Buku &b, int hariDipinjam) {       
    cout << "ID: \t" << b.getId() << endl;
    cout << "Judul: \t" << b.getJudul() << endl;
    cout << "Tipe: \t" << b.tipe() << endl;
    cout << "Penerbit: \t" << b.getPenerbit() << endl;
    cout << "Lama Pinjam: " << hariDipinjam << " hari" << endl;
    cout << "Hari pinjam: " << hariDipinjam << endl;

    int lama = b.lamaPinjam();
    if (lama == 0) {
        cout << "Tidak dapat dipinjam" << endl;
        return;
    }

    int terlambat = hariDipinjam - lama;
    if (terlambat > 0) {
        cout << "Terlambat: " << terlambat << " hari" << endl;
        cout << "Denda: " << b.denda(terlambat) << endl;
    } else {
        cout << "Terlambat: Tidak ada" << endl;
        cout << "Denda: Tidak ada" << endl;
    }
}

int main() {
    vector<unique_ptr<Buku>> koleksi;
    koleksi.push_back(make_unique<BukuReferensi>("B001", "PKI Jaya", "Produksi Buku Kiri"));
    koleksi.push_back(make_unique<BukuReguler>("B002", "Ternak Bitcoin", "Academy"));
    koleksi.push_back(make_unique<BukuReguler>("B003", "Langit", "Mizan"));
    koleksi.push_back(make_unique<BukuLangka>("B004", "Miyamoto Mushashi", "Gramedia"));
    koleksi.push_back(make_unique<BukuLangka>("B005", "Sakai Jin", "Sony Entertainment"));


    int hariDipinjam[] = {2, 4, 8, 10, 8};
    for (int i = 0; i < koleksi.size(); i++) {
        cout << "Buku " << i + 1 << endl;
        printInfoPinjam(*koleksi[i], hariDipinjam[i]);
        cout << endl;
    }
    return 0;

}
