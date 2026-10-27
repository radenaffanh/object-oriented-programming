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
        void setTahun(int t) {
            tahun = t;
        }
        int getTahun() {
            return tahun;
        }
        void setJumlah(int j) {
            jumlah = j;
        }
        int getJumlah() {
            return jumlah;
        }
        void setHarga(int h){
            harga = h;
        }
        int getHarga() {
            return harga;
        }
};

class sepatu : public fashion {
    private:
        string merk;
        float ukuran;
    public :
        sepatu(int year, int amount, float price, string m, float u) : fashion(year, amount, price){
            merk = m;
            ukuran = u;
        }
        void setMerk(string brand){
            merk = brand;
        }
        string getMerk(){
            return merk;
        }
        void setUkuran(float size){
            ukuran = size;
        }
        float getUkuran(){
            return ukuran;
        }


};

class pakaian : public fashion {
    private :
        string gender;
        string model;
        string warna;
    public :
        pakaian(int year, int amount, float price, string g, string m, string w) : fashion(year, amount, price){
            gender = g;
            model = m;
            warna = w;
        }
        void setGender(string g){
            gender = g;
        }
        string getGender(){
            return gender;
        }
        void setModel(string m){
            model = m;
        }
        string getModel(){
            return model;
        }
        void setWarna(string w){
            warna = w;
        }
        string getWarna(){
            return warna;
        }
};

class aksesoris : public fashion {
    private :
        string jenis;
        string bahan;
    public :
        aksesoris(int year, int amount, float price, string j, string b) : fashion(year, amount, price){
            jenis = j;
            bahan = b;
        }
        void setJenis(string j){
            jenis = j;
        }
        string getJenis(){
            return jenis;
        }
        void setBahan(string b){
            bahan = b;
        }
        string getBahan(){
            return bahan;
        }

};

int main(){
    // Data pakaian
    pakaian p1(2020, 123, 120000, "L", "Jaket", "Hitam");
    pakaian p2(2021, 330, 320000, "P", "Dress", "Merah");
    pakaian p3(2020, 24, 120000, "L", "Kemaja", "Biru");
    pakaian p4(2021, 33, 120000, "L", "Kaos", "Putih");
    // Data sepatu
    sepatu s1(2022, 10, 1400000, "Nike", 38);
    sepatu s2(2017, 8, 3000000, "Adidas", 42);
    // Data aksesoris
    aksesoris a1(2022, 56, 120000, "Sabuk", "Kain");
    aksesoris a2(2019, 34, 80000, "Topi", "Kulit");

    cout << "Data Pakaian:\n";
    cout << "Data Pakaian:\n";
    cout << "1. Harga " << p1.getHarga() 
        << ", Tahun " << p1.getTahun() 
        << ", Jumlah " << p1.getJumlah()
        << ", Gen " << p1.getGender()
        << ", Model " << p1.getModel()
        << ", Warna " << p1.getWarna()
        << endl;

    cout << "2. Harga " << p2.getHarga() 
        << ", Tahun " << p2.getTahun() 
        << ", Jumlah " << p2.getJumlah()
        << ", Gen " << p2.getGender()
        << ", Model " << p2.getModel()
        << ", Warna " << p2.getWarna()
        << endl;

    cout << "3. Harga " << s1.getHarga() 
        << ", Tahun " << s1.getTahun()
        << ", Jumlah " << s1.getJumlah()
        << ", Merk " << s1.getMerk()
        << ", Ukuran " << s1.getUkuran()
        << endl;

    cout << "4. Harga " << s2.getHarga() 
        << ", Tahun " << s2.getTahun()
        << ", Jumlah " << s2.getJumlah()
        << ", Merk " << s2.getMerk()
        << ", Ukuran " << s2.getUkuran()
        << endl;

    cout << "5. Harga " << a1.getHarga() 
        << ", Tahun " << a1.getTahun()
        << ", Jumlah " << a1.getJumlah()
        << ", Jenis " << a1.getJenis()
        << ", Bahan " << a1.getBahan()
        << endl;

    cout << "6. Harga " << a2.getHarga() 
        << ", Tahun " << a2.getTahun()
        << ", Jumlah " << a2.getJumlah()
        << ", Jenis " << a2.getJenis()
        << ", Bahan " << a2.getBahan()
        << endl;


    return 0;
}
