#include <bits/stdc++.h>

using namespace std;

class motor {
private:
    string platnomor;
    string nim;

public:
    motor(string p, string n) {
        platnomor = p;
        nim = n;
    }

    void tampilkan() const {
        cout << "NIM: " << nim << " || Plat Nomor: " << platnomor << endl;
    }

    string getNIM() const { return nim; }
    string getplat() const { return platnomor; }

    static void databaseNIMmahasiswa(vector<motor>& dataplat) {
        dataplat.push_back(motor("B 3579 ENL", "163241037"));
        dataplat.push_back(motor("L 2345 DEF", "987654321"));
        dataplat.push_back(motor("B 3456 GHI", "164251099"));
        dataplat.push_back(motor("L 4567 JKL", "176329832"));
        dataplat.push_back(motor("B 5678 MNO", "123456789"));
        dataplat.push_back(motor("AE 6789 EOR", "987654321"));
        dataplat.push_back(motor("L 1234 EBF", "163241041"));
    }

    static void tampilkandata(const vector<motor>& dataplat) {
        cout << "\n=== DATA MAHASISWA TERDAFTAR ===" << endl;
        for (const auto& m : dataplat) {
            m.tampilkan();
        }
        cout << "================================" << endl;
    }

    static void verifikasi(const vector<motor>& dataplat, const string& nim, const string& plat) {
        bool ditemukan = false;
        for (const auto& m : dataplat) {
            if (m.getNIM() == nim && m.getplat() == plat) {
                cout << "Verifikasi berhasil. Hati Hati dijalan " << nim << "!" << endl;
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Verifikasi gagal. NIM atau plat nomor tidak ditemukan." << endl;
        }
    }
};

int main() {
    vector<motor> dataplat;
    motor::databaseNIMmahasiswa(dataplat);

    string nimInput, platInput;

    cout << "Masukkan Plat Nomor: ";
    getline(cin, platInput); 
    cin.ignore(); 

    cout << "Masukkan NIM: ";
    cin >> nimInput;
    
    motor::verifikasi(dataplat, nimInput, platInput);

    return 0;
}