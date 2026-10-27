#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class tabungan {
    private:
        double saldo;
        double IDRconversion(int jumlahuang, string matauang){
            if(matauang == "USD") return jumlahuang * 15000;
            else if(matauang == "YUAN") return jumlahuang * 3000;
            else{
                return jumlahuang;
            };
    }
    public:
        tabungan(double s){
            saldo = s;
        }
        double tampilkansaldo(string matauang){
            return IDRconversion(saldo, matauang);
        }
        void simpanuang(double jumlah, string matauang){
            saldo += IDRconversion(jumlah, matauang);
            cout << "berhasil menyimpan " << fixed << setprecision(2) << jumlah << " " << matauang << " ke tabungan" << endl;
        }
        void ambiluang(double jumlah, string matauang){
            double jumlahIDR = IDRconversion(jumlah, matauang);
            if(jumlahIDR > saldo){
                cout << "saldo tidak mencukupi" << endl;
            } else {
                saldo -= jumlahIDR;
                cout << "berhasil mengambil " << jumlah << " " << matauang << " dari tabungan" << endl;
            }

        }
    };

int main() {
    tabungan t(0); 
    int pilihan;
    
    do{
        cout << "Menu:" << endl;
        cout << "1. Simpan Uang" << endl;
        cout << "2. Ambil Uang" << endl;
        cout << "3. Tampilkan Saldo" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch(pilihan){
            case 1: {
                double jumlah;
                string matauang;
                cout << "Masukkan jumlah uang: ";
                cin >> jumlah;
                cout << "Masukkan mata uang (IDR/USD/YUAN): ";
                cin >> matauang;
                t.simpanuang(jumlah, matauang);
                break;
            }
            case 2: {
                double jumlah;
                string matauang;
                cout << "Masukkan jumlah uang: ";
                cin >> jumlah;
                cout << "Masukkan mata uang (IDR/USD/YUAN): ";
                cin >> matauang;
                t.ambiluang(jumlah, matauang);
                break;
            }
            case 3: {
                cout << "Saldo dalam IDR: Rp " << fixed << setprecision(2) << t.tampilkansaldo("IDR") << endl;
                break;
            }
        }
    } while (pilihan != 4);


    return 0;
}