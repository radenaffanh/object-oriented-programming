#include <bits/stdc++.h>
using namespace std;

class hewan{
    protected:
        string nama;
        string jenis;

    public:
        hewan(string n, string j){
            nama = n;
            jenis = j;
        }

        void tampilkan(){
            cout << "Nama: " << nama << endl;
            cout << "Jenis: " << jenis << endl;
        }
};

class mamalia : public hewan {
    private:
        string ciri;

    public:
        mamalia(string n, string j, string c) : hewan(n, j) {
            ciri = c;
        }

        void tampilkan() {
            hewan::tampilkan();
            cout << "Ciri: " << ciri << endl;
        }
};

int main(){
    mamalia m("Kucing", "Mamalia", "Bulu Halus");
    mamalia m2("Anjing", "Mamalia", "Suka menggongong");
    m.tampilkan();
    m2.tampilkan();
}
