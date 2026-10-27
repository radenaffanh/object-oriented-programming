#include <iostream>
#include <string>
using namespace std;

class menu {
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

    menu() {
        jumlahayambakar = 0;
        jumlahayamgoreng = 0;
        jumlahsteak = 0;
        jumlahikan = 0;
        jumlahpasta = 0;
        jumlahnasigoreng = 0;
        jumlahsushi = 0;
        jumlahpizza = 0;
        jumlahburger = 0;
        jumlahesteh = 0;
        jumlahsodagembira = 0;
        jumlahmatchalatte = 0;
        jumlahamericano = 0;
        jumlahcappucino = 0;
        jumlahmangosplash = 0;
    }

    // method pesan
    void pesan(string nama, int jumlah) {
        if (nama == "ayam bakar") jumlahayambakar += jumlah;
        else if (nama == "ayam goreng") jumlahayamgoreng += jumlah;
        else if (nama == "steak") jumlahsteak += jumlah;
        else if (nama == "ikan") jumlahikan += jumlah;
        else if (nama == "pasta") jumlahpasta += jumlah;
        else if (nama == "nasi goreng") jumlahnasigoreng += jumlah;
        else if (nama == "sushi") jumlahsushi += jumlah;
        else if (nama == "pizza") jumlahpizza += jumlah;
        else if (nama == "burger") jumlahburger += jumlah;
        else if (nama == "esteh") jumlahesteh += jumlah;
        else if (nama == "soda gembira") jumlahsodagembira += jumlah;
        else if (nama == "matcha latte") jumlahmatchalatte += jumlah;
        else if (nama == "americano") jumlahamericano += jumlah;
        else if (nama == "cappucino") jumlahcappucino += jumlah;
        else if (nama == "mango splash") jumlahmangosplash += jumlah;
        else cout << "Menu \"" << nama << "\" tidak tersedia." << endl;
    }

    long hitungtotalharga() {
        return 35000 * jumlahayambakar +
               35000 * jumlahayamgoreng +
              105000 * jumlahsteak +
               60000 * jumlahikan +
               42000 * jumlahpasta +
               35000 * jumlahnasigoreng +
               70000 * jumlahsushi +
               55000 * jumlahpizza +
               40000 * jumlahburger +
               10000 * jumlahesteh +
               15000 * jumlahsodagembira +
               20000 * jumlahmatchalatte +
               21000 * jumlahamericano +
               21000 * jumlahcappucino +
               21000 * jumlahmangosplash;
    }

    void tampilkanpesanandanharga() {
        cout << "\n--- Pesanan Anda ---" << endl;
        if (jumlahayambakar) cout << "Ayam Bakar : " << jumlahayambakar << endl;
        if (jumlahayamgoreng) cout << "Ayam Goreng: " << jumlahayamgoreng << endl;
        if (jumlahsteak) cout << "Steak      : " << jumlahsteak << endl;
        if (jumlahikan) cout << "Ikan       : " << jumlahikan << endl;
        if (jumlahpasta) cout << "Pasta      : " << jumlahpasta << endl;
        if (jumlahnasigoreng) cout << "Nasi Goreng: " << jumlahnasigoreng << endl;
        if (jumlahsushi) cout << "Sushi      : " << jumlahsushi << endl;
        if (jumlahpizza) cout << "Pizza      : " << jumlahpizza << endl;
        if (jumlahburger) cout << "Burger     : " << jumlahburger << endl;
        if (jumlahesteh) cout << "Esteh      : " << jumlahesteh << endl;
        if (jumlahsodagembira) cout << "Soda Gembira : " << jumlahsodagembira << endl;
        if (jumlahmatchalatte) cout << "Matcha Latte : " << jumlahmatchalatte << endl;
        if (jumlahamericano) cout << "Americano    : " << jumlahamericano << endl;
        if (jumlahcappucino) cout << "Cappucino    : " << jumlahcappucino << endl;
        if (jumlahmangosplash) cout << "Mango Splash : " << jumlahmangosplash << endl;

        cout << "Total Harga : Rp " << hitungtotalharga() << endl;
    }
};

int main() {
    cout << "-----------------------------------" << endl;
    cout << "-------------- MENU ---------------" << endl;
    cout << "1. Ayam Bakar" << endl;
    cout << "2. Ayam Goreng" << endl;
    cout << "3. Steak" << endl;
    cout << "4. Ikan" << endl;
    cout << "5. Pasta" << endl;
    cout << "6. Nasi Goreng" << endl;
    cout << "7. Sushi" << endl;
    cout << "8. Pizza" << endl;
    cout << "9. Burger" << endl;
    cout << "\nMinuman:" << endl;
    cout << "10. Esteh" << endl;
    cout << "11. Soda Gembira" << endl;
    cout << "12. Matcha Latte" << endl;
    cout << "13. Americano" << endl;
    cout << "14. Cappucino" << endl;
    cout << "15. Mango Splash" << endl;
    cout << "-----------------------------------" << endl;

    menu menu1;
    string nama;
    int jumlah;

    cout << "\nSilahkan tentukan pesanan anda (ketik 'selesai' untuk berhenti)\n";

    while (true) {
        cout << "Nama menu: ";
        getline(cin, nama);
        if (nama == "selesai") break;

        cout << "Jumlah: ";
        cin >> jumlah;
        cin.ignore(); // supaya getline bisa dipakai lagi

        menu1.pesan(nama, jumlah);
    }

    menu1.tampilkanpesanandanharga();

    long bayar;
    cout << "\nMasukkan jumlah uang dibayar: Rp ";
    cin >> bayar;

    long kembalian = bayar - menu1.hitungtotalharga();
    if (kembalian < 0) {
        cout << "Uang tidak cukup. Kurang Rp " << -kembalian << endl;
    } else {
        cout << "Kembalian: Rp " << kembalian << endl;
    }

    return 0;
}
