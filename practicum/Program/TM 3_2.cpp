#include <bits/stdc++.h>
using namespace std;

struct Rekening{
    private:
        string no_rekening;
        string nama;
        double saldo;
    public:
        Rekening(string norek, string n, double s){
            this->no_rekening = norek;
            this->nama = n;
            if(s<0){
                cout << "Error:Saldo tidak boleh negatif, set ke 0" << endl;
                this->saldo = 0;
            } else {
                this->saldo = s;
            }
        }

    
        void setnama(string n){
            this->nama = n;
        }

        void setsaldo(double s){
            if(s < 0){
                cout << "Error:Saldo tidak boleh negatif, set ke 0" << endl;
                this->saldo = 0;
            } else {
                this->saldo = s;
                cout << "Setor uang berhasil. Saldo sekarang: " << fixed << setprecision(2) << this->saldo << endl;
            }
        }
        void tarik(double jumlah){
            if(jumlah > this->saldo){
                cout << "Saldo tidak cukup." << endl;
            } else {
                this->saldo -= jumlah;
                cout << "Ambil uang berhasil. Saldo sekarang: " << fixed << setprecision(2) << this->saldo << endl;
            }
        }

        void setor(double jumlah){
            if(jumlah < 0){
                cout << "Error: Jumlah setor tidak boleh negatif." << endl;
            } else {
                this->saldo += jumlah;
                cout << "Setor uang berhasil. Saldo sekarang: " << this->saldo << fixed << setprecision(2) << endl;
            }
        }

        void tampilkanSaldo(){
            cout << "No. Rekening \t:" << this->no_rekening << endl
            << "Nama Pemilik: \t:" << this->nama << endl
            << "Saldo: \t\t:" << fixed << setprecision(2) << this->saldo << endl;
        }
         double getSaldo(){
                return this->saldo;
            }
};

int main(){
    Rekening r1("1234567890", "Affan", 1000000);

    r1.tampilkanSaldo();
    r1.tarik(200000);
    r1.tampilkanSaldo();
    r1.setor(2000000);

    Rekening r2("0987654321", "Budi", -500000);
    r2.tampilkanSaldo();
    r2.setor(300000);
    r2.tarik(100000);
    r2.tampilkanSaldo();

    cout << "Saldo akhir: " << r1.getSaldo() << endl;
    return 0;
}