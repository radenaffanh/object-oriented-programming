#include <bits/stdc++.h>
using namespace std;

class Buku{
    private:
    string id;
    string judul;
    string penerbit;

    public:
    Buku(string id, string judul, string penerbit){
        this->id = id;
        this->judul = judul;
        this->penerbit = penerbit;
    }
    string getId(){
        return id;
    }
    string getJudul(){
        return judul;
    }
    string getPenerbit(){
        return penerbit;
    }

    virtual int lamaPinjam() const{return 7;}
    virtual double denda(int hariTerlambat) const { return 1000 * hariTerlambat; }
    virtual string tipe() const {return "Buku";}

    virtual ~Buku() = default;

};

class BukuReferensi : public Buku{
    public:
    BukuReferensi(string id, string judul, string penerbit) : Buku(id, judul, penerbit) {}

    int lamaPinjam() const override {
        return 0; // Buku referensi tidak boleh dipinjam
    }
    double denda(int hariTerlambat) const override {
        return 0.0; // Tidak ada denda karena tidak boleh dipinjam
    }
    string tipe() const override {
        return "Referensi";
    }
    
};

class BukuReguler : public Buku{
    public:
    BukuReguler(string id, string judul, string penerbit) : Buku(id, judul, penerbit) {}

    int lamaPinjam() const override {
        return 7; // default 7 hari
    }
    double denda(int hariTerlambat) const override {
        return 1000 * hariTerlambat; // Denda 1000 per hari terlambat
    }
    string tipe() const override {
        return "Reguler";
    }
    
};

class BukuLangka : public Buku{
    private:
    bool izinKhusus;

    public:
    BukuLangka(string id, string judul, string penerbit) : Buku(id, judul, penerbit), izinKhusus(true) {}

    int lamaPinjam() const override {
        return 3; //default 3 hari
    }
    double denda(int hariTerlambat) const override {
        return 2500 * hariTerlambat; // Denda 2500 per hari terlambat
    }
    bool perluIzinKhusus() const {
        return izinKhusus;
    }
    string tipe() const override {
        return "Langka";
    }
    
};

void printInfoPinjam(Buku &b, int hariDipinjam){
    cout << "ID: \t" << b.getId() << endl;
    cout << "Judul: \t" << b.getJudul() << endl;
    cout << "Tipe: \t" << b.tipe() << endl;
    cout << "Penerbit: \t" << b.getPenerbit() << endl;
    cout << "Lama Pinjam: " << b.lamaPinjam() << endl;
    cout << "Hari pinjam: " << hariDipinjam << endl;
    
    int lama = b.lamaPinjam();
    if (lama == 0) {
        cout << "Tidak dapat dipinjam." << endl;
        return;
    } 

    int terlambat = hariDipinjam - lama;
    if (terlambat > 0) {
        cout << "Terlambat  : " << terlambat << endl;
        cout << "Denda      : " << b.denda(terlambat) << endl;
    } else {
        cout << "Terlambat  : Tidak ada\n";
        cout << "Denda      : Tidak ada\n";
    }
}

int main(){
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
