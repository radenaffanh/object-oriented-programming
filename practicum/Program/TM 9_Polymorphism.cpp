#include <bits/stdc++.h>
using namespace std;

class Karyawan{
    public:
    int makanHari = 0;
    int transportHari = 0;
    int lemburJam = 0;

    virtual int gajiPokok()=0;
    virtual int uangMakan()=0;
    virtual int uangTransport()=0;
    virtual int uangLembur()=0;

    virtual int makanPerHari() { return makanHari; }
    virtual int transportPerHari() { return transportHari; }
    virtual int lemburPerJam() { return lemburJam; }
};

class Direktur : public Karyawan{
    public:
    int gajiPokok(){
        return 5400000;
    }
    int uangMakan(){
        return 120000;
    }
    int uangTransport(){
        return 50000;
    }
    int uangLembur(){
        return 50000;
    }
    void hitungGaji(){
        int totalGaji = gajiPokok() + uangMakan()*makanPerHari() + uangTransport()*transportPerHari() + uangLembur()*lemburPerJam();
        cout << "Total Gaji Direktur: " << totalGaji << endl;
    }
}; 

class Manager : public Karyawan{
    public:
    int gajiPokok(){
        return 4500000;
    }
    int uangMakan(){
        return 100000;
    }
    int uangTransport(){
        return 30000;
    }
    int uangLembur(){
        return 40000;
    }
    void hitungGaji(){
        int totalGaji = gajiPokok() + uangMakan()*makanPerHari() + uangTransport()*transportPerHari() + uangLembur()*lemburPerJam();
        cout << "Total Gaji Manager: " << totalGaji << endl;
    }
};

class Teknisi : public Karyawan{
    public:
    int gajiPokok(){
        return 3200000;
    }
    int uangMakan(){
        return 60000;
    }
    int uangTransport(){
        return 20000;
    }
    int uangLembur(){
        return 15000;
    }
    void hitungGaji(){
        int totalGaji = gajiPokok() + uangMakan()*makanPerHari() + uangTransport()*transportPerHari() + uangLembur()*lemburPerJam();
        cout << "Total Gaji Teknisi: " << totalGaji << endl;
    }
};

class Operator : public Karyawan{
    public:
    int gajiPokok(){
        return 2400000;
    }
    int uangMakan(){
        return 60000;
    }
    int uangTransport(){
        return 20000;
    }
    int uangLembur(){
        return 10000;
    }
    void hitungGaji(){
        int totalGaji = gajiPokok() + uangMakan()*makanPerHari() + uangTransport()*transportPerHari() + uangLembur()*lemburPerJam();
        cout << "Total Gaji Operator: " << totalGaji << endl;
    }
};

int main(){
    int pilihan;
    cout << "Masukkan Jenis Karyawan:\n 1.Direktur\n 2.Manager\n 3.Teknisi\n 4.Operator \nPilihan: ";
    cin >> pilihan;
    switch(pilihan){
        case 1:{
            Direktur d;
            cout << "Masukkan Jumlah Hari untuk reimburse Makan: ";
            cin >> d.makanHari;
            cout << "Masukkan Jumlah Hari untuk reimburse Transport: ";
            cin >> d.transportHari;
            cout << "Masukkan Jumlah Jam Lembur: ";
            cin >> d.lemburJam;
            d.hitungGaji();
            break;
        }
        case 2:{
            Manager m;
            cout << "Masukkan Jumlah Hari untuk reimburse Makan: ";
            cin >> m.makanHari;
            cout << "Masukkan Jumlah Hari untuk reimburse Transport: ";
            cin >> m.transportHari;
            cout << "Masukkan Jumlah Jam Lembur: ";
            cin >> m.lemburJam;
            m.hitungGaji();
            break;
        }
        case 3:{
            Teknisi t;
            cout << "Masukkan Jumlah Hari untuk reimburse Makan: ";
            cin >> t.makanHari;
            cout << "Masukkan Jumlah Hari untuk reimburse Transport: ";
            cin >> t.transportHari;
            cout << "Masukkan Jumlah Jam Lembur: ";
            cin >> t.lemburJam;
            t.hitungGaji();
            break;
        }
        case 4:{
            Operator o;
            cout << "Masukkan Jumlah Hari untuk reimburse Makan: ";
            cin >> o.makanHari;
            cout << "Masukkan Jumlah Hari untuk reimburse Transport: ";
            cin >> o.transportHari;
            cout << "Masukkan Jumlah Jam Lembur: ";
            cin >> o.lemburJam;
            o.hitungGaji();
            break;
        }
        default:
            cout << "Pilihan Tidak Valid!" << endl;
    }
    
}

