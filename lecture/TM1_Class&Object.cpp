#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class mahasiswa{
private:
    string nama;
    string nim;
    double ipk;
public :
    //constructor
    mahasiswa(string n, string NIM, double IPK){
        nama = n;
        nim = NIM;
        ipk = IPK;
    }

    string getNama(){
        return nama;
    }

    string getNim(){
        return nim;
    }

    double getIpk(){
        return ipk;
    }

    void tampilkandata(){
        cout << "Nama: " << getNama() << endl;
        cout << "NIM: " << getNim() << endl;
        cout << "IPK: " << getIpk() << endl;
        cout << "Predikat: " << hitungpredikat() << endl;
    }

    string hitungpredikat(){
        if(ipk >= 3.5) return "Cumlaude";
        else if(ipk >= 3.0) return "Sangat Baik";
        else if(ipk >= 2.5) return "Baik";
        else return "Cukup";
    }
};


int main(){
    string nama, nim;
    double ipk;

    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    cout << "Masukkan IPK: ";
    cin >> ipk;

    mahasiswa mhs1(nama, nim, ipk);
    mahasiswa mhs2("Raden Affan Harits", "163241037", 3.75);
    cout << "\nInformasi Mahasiswa 1:" << endl;
    mhs1.tampilkandata();
    cout << "\nInformasi Mahasiswa 2:" << endl;
    mhs2.tampilkandata();

    return 0;
}