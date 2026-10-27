#include <iostream>
#include <stdio.h>
using namespace std;

class Balok {
private:
    double panjang, lebar, tinggi;

public:
    Balok(double p, double l, double t) {
        panjang = p;
        lebar = l;
        tinggi = t;
    }

    double volume() {
        return panjang * lebar * tinggi;
    }

    double luas_permukaan() {
        return 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
    }

    void tampilkan_data() {
        cout << "Panjang: " << panjang << endl;
        cout << "Lebar  : " << lebar << endl;
        cout << "Tinggi : " << tinggi << endl;
    }
};

int main() {
    double p, l, t;
    cout << "Masukkan panjang: ";
    cin >> p;
    cout << "Masukkan lebar  : ";
    cin >> l;
    cout << "Masukkan tinggi : ";
    cin >> t;

    Balok balok1(p, l, t);

    cout << "\nData Balok:\n";
    balok1.tampilkan_data();

    cout << "Volume Balok        : " << balok1.volume() << endl;
    cout << "Luas Permukaan Balok: " << balok1.luas_permukaan() << endl;

    return 0;
}
