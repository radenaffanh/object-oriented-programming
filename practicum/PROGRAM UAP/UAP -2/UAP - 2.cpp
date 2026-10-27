#include <bits/stdc++.h>
using namespace std;

class Kamar {
protected:
    int malam;
    string nama;

public:
    void setMalam(int night) {
        malam = night;
    }
    void setNama(string name) {
        nama = name;
    }
    virtual int hitungHarga() {
        return 0;
    }
    virtual void infoKamar() {
        cout << "Guest Name : " << nama << endl;
        cout << "Night(s) : " << malam << endl;
    }
    virtual ~Kamar() {}
};

class Standard : public Kamar {
public:
    int hitungHarga() override {
        return 300000 * malam;
    }
    void infoKamar() override {
        Kamar::infoKamar();
        cout << "Room type : Standard" << endl;
        cout << "per Night charge : Rp300.000,-" << endl;
    }
};

class Deluxe : public Kamar {
public:
    int hitungHarga() override {
        return 500000 * malam;
    }
    void infoKamar() override {
        Kamar::infoKamar();
        cout << "Room type : Deluxe" << endl;
        cout << "per Night charge : Rp500.000,-" << endl;
    }
};

class Suite : public Kamar {
public:
    int hitungHarga() override {
        return 800000 * malam;
    }
    void infoKamar() override {
        Kamar::infoKamar();
        cout << "Room type : Suite" << endl;
        cout << "per Night charge : Rp800.000,-" << endl;
    }
};

int main() {
    int pilihan, malam;
    string nama;
    Kamar* kamar;

    cout << "--- Ritz Carlton's Hotel Services ---" << endl;
    cout << "Guest Name : ";
    getline(cin, nama);

    cout << "1. Standard" << endl;
    cout << "2. Deluxe" << endl;
    cout << "3. Suite" << endl;
    cout << "Room Type (1-3): ";
    cin >> pilihan;

    cout << "Night(s) to stay: ";
    cin >> malam;

    if (pilihan == 1) {
        kamar = new Standard();
    } else if (pilihan == 2) {
        kamar = new Deluxe();
    } else if (pilihan == 3) {
        kamar = new Suite();
    } else {
        cout << "Invalid room type. Reservation not valid" << endl;
        return 0;
    }

    kamar->setNama(nama);
    kamar->setMalam(malam);
    cout << "----------------------------------" << endl;
    cout << "your reservation details:" << endl;
    kamar->infoKamar();

    cout << "Total: Rp" << kamar->hitungHarga() << ",-" << endl;

    delete kamar;
    return 0;
}


