#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

class pengiriman{
    protected :
    double berat;

    public :
    pengiriman (double weight){
        this->berat = weight;
    }

    virtual double hitungbiaya(){
        return 0;
    }
    virtual double hitungbiaya(double jarak){
        return 0;
    }
};

class pengirimanUdara : public pengiriman{
    private :
    double biayaperKg = 20000;
    double biayaperKm = 1000;

    public :
    pengirimanUdara(double weight) : pengiriman(weight) {}

    double hitungbiaya() override {
        return berat * biayaperKg;
    }
    double hitungbiaya(double jarak) override {
        return (berat * biayaperKg) + (jarak * biayaperKm);
    }
};

class pengirimandarat : public pengiriman{
    private :
    double biayaperKg = 10000;
    double biayaperKm = 500;

    public :
    pengirimandarat(double weight) : pengiriman(weight) {}

    double hitungbiaya() override {
        return berat * biayaperKg;
    }

    double hitungbiaya(double jarak) override {
        return (berat * biayaperKg) + (jarak * biayaperKm);
    }
};

int main() {
    double beratbarang = 5;
    double jaraktempuh = 100;

    pengirimanUdara udara(beratbarang);
    pengirimandarat darat(beratbarang);

    cout << "--- Pengiriman Darat ---" << std::endl;
    cout << "Berat: " << beratbarang << " kg" << std::endl;
    cout << "Biaya (berdasarkan berat saja): Rp" << darat.hitungbiaya() << std::endl;
    cout << "Biaya (berdasarkan berat & jarak " << jaraktempuh << " km): Rp" << darat.hitungbiaya(jaraktempuh) << std::endl;
    cout << "--- Pengiriman Udara ---" << std::endl;
    cout << "Berat: " << beratbarang << " kg" << std::endl;
    cout << "Biaya (berdasarkan berat saja): Rp" << udara.hitungbiaya() << std::endl;
    cout << "Biaya (berdasarkan berat & jarak " << jaraktempuh << " km): Rp" << udara.hitungbiaya(jaraktempuh) << std::endl;

    return 0;
}
