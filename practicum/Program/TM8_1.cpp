#include <bits/stdc++.h>
using namespace std;

class fashion {
    protected:
        int tahun, jumlah;
        float harga;
 
    public:
        fashion(int year, int amount, float price){
            tahun = year;
            jumlah = amount;
            harga = price;
        }
        virtual void tampilkan(){ // fungsi virtual agar bisa di-override oleh subclass
            cout << "Tahun : " << tahun << endl;
            cout << "Jumlah : " << jumlah << endl;
            cout << "Harga : IDR " << fixed << setprecision(0) << harga << endl;
        }
};

// ===================== Kelas Turunan =====================

class pakaian : public fashion {
    private :
        string gender;
        string model;
        string warna;
    public :
        pakaian(int year, int amount, float price, string g, string m, string w)
        : fashion(year, amount, price){
            gender = g;
            model = m;
            warna = w;
        }

        void tampilkan() override {
            cout << left << setw(6) << tahun << setw(10) << jumlah 
                 << "IDR " << setw(12) << fixed << setprecision(0) << harga 
                 << setw(5) << gender << setw(12) << model 
                 << setw(10) << warna << setw(10) << "-" 
                 << setw(10) << "-" << setw(10) << "-" << endl;
        }
};

class sepatu : public fashion {
    private:
        string merk;
        float ukuran;
    public :
        sepatu(int year, int amount, float price, string m, float u)
        : fashion(year, amount, price){
            merk = m;
            ukuran = u;
        }

        void tampilkan() override {
            cout << left << setw(6) << tahun << setw(10) << jumlah 
                 << "IDR " << setw(12) << fixed << setprecision(0) << harga 
                 << setw(5) << "-" << setw(12) << "-" 
                 << setw(10) << "-" << setw(10) << merk 
                 << setw(10) << "-" << setw(10) << ukuran << endl;
        }
};

class aksesoris : public fashion {
    private :
        string jenis;
        string bahan;
    public :
        aksesoris(int year, int amount, float price, string j, string b)
        : fashion(year, amount, price){
            jenis = j;
            bahan = b;
        }

        void tampilkan() override {
            cout << left << setw(6) << tahun << setw(10) << jumlah 
                 << "IDR " << setw(12) << fixed << setprecision(0) << harga 
                 << setw(5) << "-" << setw(12) << "-" 
                 << setw(10) << "-" << setw(10) << "-" 
                 << setw(10) << jenis << setw(10) << bahan << endl;
        }
};

// ===================== MAIN =====================

int main(){
    // Sesuai urutan tabel (No. 1–8)
    pakaian p1(2020, 123, 120000, "L", "Jaket", "Hitam");
    pakaian p2(2021, 330, 320000, "P", "Dress", "Merah");
    sepatu s1(2022, 10, 1400000, "Nike", 38);
    pakaian p3(2020, 24, 120000, "L", "Kemaja", "Biru");
    pakaian p4(2021, 33, 120000, "L", "Kaos", "Putih");
    aksesoris a1(2022, 56, 120000, "Sabuk", "Kain");
    aksesoris a2(2019, 34, 80000, "Topi", "Kulit");
    sepatu s2(2017, 8, 3000000, "Adidas", 42);

    // Header tabel
    cout << left
         << setw(6)  << "Tahun"
         << setw(10) << "Jumlah"
         << setw(16) << "Harga"
         << setw(5)  << "Gen"
         << setw(12) << "Model"
         << setw(10) << "Warna"
         << setw(10) << "Merk"
         << setw(10) << "Jenis"
         << setw(10) << "Bahan"
         << setw(10) << "Ukuran" << endl;

    cout << string(90, '=') << endl;

    // Urutan tampil sama seperti tabel
    p1.tampilkan();
    p2.tampilkan();
    s1.tampilkan();
    p3.tampilkan();
    p4.tampilkan();
    a1.tampilkan();
    a2.tampilkan();
    s2.tampilkan();

    return 0;
}
