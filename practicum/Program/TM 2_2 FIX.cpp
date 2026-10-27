#include <bits/stdc++.h>
using namespace std;

struct Rekening{
    private:
        string no_rekening;
        string nama;
        double saldo;
    public:
        void setno_rekening(string norek){
            this->no_rekening = norek;
        }
        string getnorekening(){
            return this->no_rekening;
        }

        void setnama(string n){
            this->nama = n;
        }
        string getnama(){
            return this->nama;
        }

        void setsaldo(double s){
            
                this->saldo = s;
        }
        double getsaldo(){
            if(this->saldo < 0){
                cout << "(Error: Saldo tidak boleh negatif, set ke 0) ; " ;
                this->saldo = 0;
            }
            return this->saldo;
        }
    };
        

int main(){
    Rekening r1,r2;

    r1.setno_rekening("73198713");
    r1.setnama("Kairi");
    r1.setsaldo(25000000);

    r2.setno_rekening("87318973");
    r2.setnama("Sanz");
    r2.setsaldo(-500000);

    cout << fixed << setprecision(2);
    
    cout << "Data Rekening 1" << endl;
    cout << "No Rekening \t: " << r1.getnorekening() << endl;
    cout << "Nama \t\t: " << r1.getnama() << endl;
    cout << "Saldo \t\t: " << r1.getsaldo() << endl << endl;

    cout << "data Rekening 2" << endl;
    cout << "No Rekening \t: " << r2.getnorekening() << endl;
    cout << "Nama \t\t: " << r2.getnama() << endl;
    cout << "Saldo \t\t: " << r2.getsaldo() << endl;

    return 0;
}