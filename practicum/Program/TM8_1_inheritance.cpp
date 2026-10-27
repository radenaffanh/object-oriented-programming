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
    int pilihan;
    cout << "Pilih kategori fashion:\n";
    cout << "1. Sepatu \n2. Pakaian \n3. Aksesoris \n4. Keluar\n";
    cout << "Masukkan pilihan (1-3): ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan){
        case 1: {
            string merk;
            float ukuran;
            int tahun, jumlah;
            float harga;
            cout << "Masukkan tahun produksi: ";
            cin >> tahun;
            cout << "Masukkan jumlah sepatu: ";
            cin >> jumlah;
            cout << "Masukkan harga sepatu: ";
            cin >> harga;
            cout << "Masukkan merk sepatu: ";
            cin.ignore();
            getline(cin, merk);
            cout << "Masukkan ukuran sepatu: ";
            cin >> ukuran;
            sepatu s(tahun, jumlah, harga, merk, ukuran);
            cout << "\nDetail Sepatu:\n";
            cout << "Merk: " << s.getMerk() << endl;
            cout << "Ukuran: " << s.getUkuran() << endl;
            cout << "Tahun Produksi: " << s.getTahun() << endl;
            cout << "Jumlah Stok: " << s.getJumlah() << endl;
            cout << "Harga: " << s.getHarga() << endl;
            break;
        }
        case 2: {
            string gender;
            string model;
            string warna;
            int tahun, jumlah;
            float harga;
            cout << "Masukkan tahun produksi: ";
            cin >> tahun;
            cout << "Masukkan jumlah stok: ";
            cin >> jumlah;
            cout << "Masukkan harga pakaian: ";
            cin >> harga;
            cout << "Masukkan gender pakaian: ";
            cin.ignore();
            getline(cin, gender);
            cout << "Masukkan model pakaian: ";
            getline(cin, model);
            cout << "Masukkan warna pakaian: ";
            getline(cin, warna);
            pakaian p(tahun, jumlah, harga, gender, model, warna);
            cout << "\nDetail Pakaian:\n";
            cout << "Gender: " << p.getGender() << endl;
            cout << "Model: " << p.getModel() << endl;
            cout << "Warna: " << p.getWarna() << endl;
            cout << "Tahun Produksi: " << p.getTahun() << endl;
            cout << "Jumlah Stok: " << p.getJumlah() << endl;
            cout << "Harga: " << p.getHarga() << endl;
            break;
        }
        case 3: {
            string jenis;
            string bahan;
            int tahun, jumlah;
            float harga;
            cout << "Masukkan tahun produksi: ";
            cin >> tahun;
            cout << "Masukkan jumlah stok: ";
            cin >> jumlah;
            cout << "Masukkan harga aksesoris: ";
            cin >> harga;
            cout << "Masukkan jenis aksesoris: ";
            getline(cin, jenis);
            cout << "Masukkan bahan aksesoris: ";
            getline(cin, bahan);
            aksesoris a(tahun, jumlah, harga, jenis, bahan);
            cout << "\nDetail Aksesoris:\n";
            cout << "Jenis: " << a.getJenis() << endl;
            cout << "Bahan: " << a.getBahan() << endl;
            cout << "Tahun Produksi: " << a.getTahun() << endl;
            cout << "Jumlah Stok: " << a.getJumlah() << endl;
            cout << "Harga: " << a.getHarga() << endl;
            break;
        }
        case 4: {
            cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
        }
        default: {
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    }
}