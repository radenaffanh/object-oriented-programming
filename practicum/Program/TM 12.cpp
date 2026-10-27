#include <bits/stdc++.h>
using namespace std;

struct Barang {
    string nama;
    double hargaPerKg;
};

int main() {
    vector<Barang> daftarBarang = {
        {"Mangga", 15500}, {"Apel", 34300}, {"Nanas", 12300},
        {"Anggur", 43000}, {"Semangka", 20000}, {"Salak", 26800},
        {"Duku", 8500}, {"Buah Naga", 21700}
    };

    cout << "=== DAFTAR HARGA BUAH PER KILOGRAM ===\n";
    cout << left << setw(15) << "Nama Buah" << "Harga (IDR)\n";
    cout << "---------------------------------------\n";
    for (auto &b : daftarBarang)
        cout << left << setw(15) << b.nama << fixed << setprecision(0) << b.hargaPerKg << endl;

    int n;
    while (true) {
        try {
            cout << "\nMasukkan jumlah jenis buah yang dibeli: ";
            if (!(cin >> n)) throw runtime_error("Input bukan angka!");
            if (n <= 0) throw runtime_error("Jumlah harus > 0!");
            break;
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore();
    vector<pair<Barang, double>> keranjang;

    for (int i = 0; i < n; ++i) {
        Barang barangDitemukan;
        string nama;
        double berat;
        bool validNama = false;

        while (!validNama) {
            try {
                cout << "\nMasukkan nama buah ke-" << i + 1 << ": ";
                getline(cin, nama);

                bool ditemukan = false;
                for (auto &b : daftarBarang) {
                    string input = nama, daftar = b.nama;
                    transform(input.begin(), input.end(), input.begin(), ::tolower);
                    transform(daftar.begin(), daftar.end(), daftar.begin(), ::tolower);
                    if (input == daftar) {
                        barangDitemukan = b;
                        ditemukan = true;
                        break;
                    }
                }

                if (!ditemukan)
                    throw runtime_error("Nama buah tidak ada dalam daftar!");
                validNama = true;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << " Coba lagi.\n";
            }
        }

        while (true) {
            try {
                cout << "Masukkan berat (kg): ";
                if (!(cin >> berat)) throw runtime_error("Input bukan angka!");
                if (berat <= 0) throw runtime_error("Berat harus lebih dari 0!");
                break;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << " Coba lagi.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        cin.ignore();

        keranjang.push_back({barangDitemukan, berat});
    }

    double total = 0;
    cout << "\n\n===== STRUK PEMBAYARAN =====\n";
    cout << left << setw(15) << "Nama Buah"
         << setw(10) << "Berat(kg)"
         << setw(12) << "Harga/kg"
         << "Subtotal\n";

    for (auto &item : keranjang) {
        double subtotal = item.second * item.first.hargaPerKg;
        total += subtotal;
        cout << left << setw(15) << item.first.nama
             << setw(10) << item.second
             << setw(12) << item.first.hargaPerKg
             << subtotal << endl;
    }

    cout << "---------------------------------------\n";
    cout << "TOTAL : IDR " << fixed << setprecision(0) << total << endl;
    cout << "=======================================\n";
}
