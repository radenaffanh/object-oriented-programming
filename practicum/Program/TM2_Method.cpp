#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class menu {
private:
  

public:
    int jumlahayambakar;
    int jumlahayamgoreng;
    int jumlahsteak;
    int jumlahikan;
    int jumlahpasta;
    int jumlahnasigoreng;
    int jumlahsushi;
    int jumlahpizza;
    int jumlahburger;
    int jumlahesteh;
    int jumlahsodagembira;
    int jumlahmatchalatte;
    int jumlahamericano;
    int jumlahcappucino;
    int jumlahmangosplash;

    menu(int ab, int ag, int s, int i, int p, int n, int s2, int p2, int b, int e, int sg, int m, int a, int c, int ms) {
        jumlahayambakar = ab;
        jumlahayamgoreng = ag;
        jumlahsteak = s;
        jumlahikan = i;
        jumlahpasta = p;
        jumlahnasigoreng = n;
        jumlahsushi = s2;
        jumlahpizza = p2;
        jumlahburger = b;
        jumlahesteh = e;
        jumlahsodagembira = sg;
        jumlahmatchalatte = m;
        jumlahamericano = a;
        jumlahcappucino = c;
        jumlahmangosplash = ms;
    }

    long hitungtotalharga() {
        int hargaayambakar = 35000 * jumlahayambakar;
        int hargaayamgoreng = 35000 * jumlahayamgoreng;
        int hargasteak = 105000 * jumlahsteak;
        int hargaikan = 60000 * jumlahikan;
        int hargapasta = 42000 * jumlahpasta;
        int harganasigoreng = 35000 * jumlahnasigoreng;
        int hargasushi = 70000 * jumlahsushi;
        int hargapizza = 55000 * jumlahpizza;
        int hargaburger = 40000 * jumlahburger;
        int hargaesteh = 10000 * jumlahesteh;
        int hargasodagembira = 15000 * jumlahsodagembira;
        int hargamatchalatte = 20000 * jumlahmatchalatte;
        int hargaamericano = 21000 * jumlahamericano;
        int hargacappucino = 21000 * jumlahcappucino;
        int hargamangosplash = 21000 * jumlahmangosplash;

        return hargaayambakar + hargaayamgoreng + hargasteak + hargaikan + hargapasta + harganasigoreng + hargasushi + hargapizza + hargaburger + hargaesteh + hargasodagembira + hargamatchalatte + hargaamericano + hargacappucino + hargamangosplash;
    }

    long hitungkembalian(){
        long totalharga = hitungtotalharga();
        long uangDibayar;
        cout << "Masukkan jumlah uang yang dibayarkan: ";
        cin >> uangDibayar;
        return uangDibayar - totalharga;
    }

    void tampilkanpesanandanharga() {
        cout << "Jumlah Ayam Bakar : " << jumlahayambakar << endl;
        cout << "Jumlah Ayam Goreng: " << jumlahayamgoreng << endl;
        cout << "Jumlah Steak      : " << jumlahsteak << endl;
        cout << "Jumlah Ikan       : " << jumlahikan << endl;
        cout << "Jumlah Pasta      : " << jumlahpasta << endl;
        cout << "Jumlah Nasi Goreng: " << jumlahnasigoreng << endl;
        cout << "Jumlah Sushi      : " << jumlahsushi << endl;
        cout << "Jumlah Pizza      : " << jumlahpizza << endl;
        cout << "Jumlah Burger     : " << jumlahburger << endl;
        cout << "Jumlah Esteh      : " << jumlahesteh << endl;
        cout << "Jumlah Soda Gembira: " << jumlahsodagembira << endl;
        cout << "Jumlah Matcha Latte: " << jumlahmatchalatte << endl;
        cout << "Jumlah Americano   : " << jumlahamericano << endl;
        cout << "Jumlah Cappucino   : " << jumlahcappucino << endl;
        cout << "Jumlah Mango Splash: " << jumlahmangosplash << endl;
        cout << "Total Harga       : Rp " << hitungtotalharga() << endl;
    }


};

int main() {
    cout << "-----------------------------------" << endl;
    cout << "--------------menu-----------------" << endl;
    cout << "1. Ayam Bakar" << endl;
    cout << "2. Ayam Goreng" << endl;
    cout << "3. Steak" << endl;
    cout << "4. Ikan" << endl;
    cout << "5. Pasta" << endl;
    cout << "6. Nasi Goreng" << endl;
    cout << "7. Sushi" << endl;
    cout << "8. Pizza" << endl;
    cout << "9. Burger" << endl;
    cout << "Minuman" << endl;
    cout << "1. Esteh" << endl;
    cout << "2. Soda Gembira" << endl;
    cout << "3. Matcha Latte" << endl;
    cout << "4. Americano" << endl;
    cout << "5. Cappucino" << endl;
    cout << "6. Mango Splash" << endl;
    cout << "-----------------------------------" << endl;

    int ab, ag, s, i, p, n, s2, p2, b, e, sg, m, a, c, ms;
    cout << "silahkan tentukan pesanan anda" << endl;
    cout << "Ayam Bakar: ";
    cin >> ab;
    cout << "Ayam Goreng: ";
    cin >> ag;
    cout << "Steak: ";
    cin >> s;
    cout << "Ikan: ";
    cin >> i;
    cout << "Pasta: ";
    cin >> p;
    cout << "Nasi Goreng: ";
    cin >> n;
    cout << "Sushi: ";
    cin >> s2;
    cout << "Pizza: ";
    cin >> p2;
    cout << "Burger: ";
    cin >> b;
    cout << "Esteh: ";
    cin >> e;
    cout << "Soda Gembira: ";
    cin >> sg;
    cout << "Matcha Latte: ";
    cin >> m;
    cout << "Americano: ";
    cin >> a;
    cout << "Cappucino: ";
    cin >> c;
    cout << "Mango Splash: ";
    cin >> ms;

    menu menu1(ab, ag, s, i, p, n, s2, p2, b, e, sg, m, a, c, ms);
    menu1.tampilkanpesanandanharga();

    long kembalian = menu1.hitungkembalian();
    if (kembalian < 0) {
        cout << "Uang yang dibayarkan tidak cukup." << endl;
    } else {
        cout << "Kembalian: Rp " << kembalian << endl;
    }

    return 0;
}
