#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Person {
public:
    virtual void tampilkan() const = 0;  
    virtual ~Person() = default;
};


class Daftar_Buku {
private:
    int id_buku;
    string judul_buku;
public:
    Daftar_Buku(int id, string judul) : id_buku(id), judul_buku(judul) {}

    void tampilkan(bool ringkas = false) const {
        if (ringkas)
            cout << "[" << setw(3) << setfill('0') << id_buku << "] " << judul_buku << endl;
        else
            cout << "ID Buku: " << setw(3) << setfill('0') << id_buku
                 << ", Judul Buku: " << judul_buku << endl;
    }

    static void IsiDaftarBuku(vector<Daftar_Buku> &daftar_buku) {
        daftar_buku.push_back({1, "Bumi"});
        daftar_buku.push_back({2, "Bulan"});
        daftar_buku.push_back({3, "Matahari"});
        daftar_buku.push_back({4, "Bintang"});
        daftar_buku.push_back({5, "Ceros & Batozar"});
        daftar_buku.push_back({6, "Komet"});
        daftar_buku.push_back({7, "Komet Minor"});
        daftar_buku.push_back({8, "Selena"});
        daftar_buku.push_back({9, "Nebula"});
        daftar_buku.push_back({10, "Si Putih"});
        daftar_buku.push_back({11, "Lumpu"});
        daftar_buku.push_back({12, "Bibi Gill"});
        daftar_buku.push_back({13, "Sagaras"});
        daftar_buku.push_back({14, "Janji"});
        daftar_buku.push_back({15, "Hujan"});
        daftar_buku.push_back({16, "Rembulan Tenggelam di Wajahmu"});
        daftar_buku.push_back({17, "Pulang"});
        daftar_buku.push_back({18, "Pergi"});
        daftar_buku.push_back({19, "Negeri di Ujung Tanduk"});
        daftar_buku.push_back({20, "Negeri Para Bedebah"});
        daftar_buku.push_back({21, "Bedebah di Ujung Tanduk"});
        daftar_buku.push_back({22, "Tanah Para Bandit"});
        daftar_buku.push_back({23, "Ayahku (bukan) Pembohong"});
        daftar_buku.push_back({24, "Tentang Kamu"});
        daftar_buku.push_back({25, "Rasa"});
    }

    static void tampilkanDaftarBuku(const vector<Daftar_Buku> &daftar_buku) {
        for (const auto &buku : daftar_buku)
            buku.tampilkan(); 
    }
};

class Daftar_Pegawai : public Person {  
    int id_pegawai;
    string nama_pegawai;
public:
    Daftar_Pegawai(int id, string nama) : id_pegawai(id), nama_pegawai(nama) {}


    void tampilkan() const override {
        cout << "ID Pegawai: " << id_pegawai
             << ", Nama Pegawai: " << nama_pegawai << endl;
    }
};

class Daftar_Member : public Person {
private:
    int id_member;
    string nama_member;
public:
    int jumlah_peminjaman = 0;
    Daftar_Member(int id, string nama) : id_member(id), nama_member(nama) {}

    void tampilkan() const override {
        cout << "ID Member: " << id_member
             << ", Nama Member: " << nama_member << endl;
        cout << "Jumlah Peminjaman: " << jumlah_peminjaman << endl;
    }

    void tambahpeminjaman() {
        jumlah_peminjaman++;
        if (jumlah_peminjaman >= 27)
            cout << "Status Member: Level 3 (free pinjam 5x)\n";
        else if (jumlah_peminjaman >= 9)
            cout << "Status Member: Level 2 (free pinjam 3x)\n";
        else if (jumlah_peminjaman >= 3)
            cout << "Status Member: Level 1 (free pinjam 1x)\n";
    }

    int getIDMember() { return id_member; }
};


struct Tanggal { int hari, bulan, tahun; };

Tanggal FormatTanggal(const string &tgl) {
    Tanggal t{};
    sscanf(tgl.c_str(), "%d-%d-%d", &t.hari, &t.bulan, &t.tahun);
    return t;
}

class form_peminjaman {
private:
    int ID_Member;
    int ID_Buku;
    string ID_Tanggal_Pinjam;
public:
    form_peminjaman(int id_member, int id_buku, string id_tanggal_pinjam)
        : ID_Member(id_member), ID_Buku(id_buku), ID_Tanggal_Pinjam(id_tanggal_pinjam) {}

    void tampilkan() const {
        cout << "ID Member: " << ID_Member
             << ", ID Buku: " << ID_Buku
             << ", Tanggal Pinjam: " << ID_Tanggal_Pinjam << endl;
    }

    string TanggalPinjam() const { return ID_Tanggal_Pinjam; }
    int IDMember() const { return ID_Member; }
    int IDBuku() const { return ID_Buku; }
};

class form_pengembalian {
private:
    int ID_Member;
    int ID_Buku;
    string ID_Tanggal_Kembali;
    string ID_Tanggal_Pinjam;
    int biaya_pinjam;
public:
    form_pengembalian(int id_member, int id_buku,
                      string id_tanggal_kembali, string id_tanggal_pinjam, int biaya)
        : ID_Member(id_member), ID_Buku(id_buku),
          ID_Tanggal_Kembali(id_tanggal_kembali), ID_Tanggal_Pinjam(id_tanggal_pinjam),
          biaya_pinjam(biaya) {}

    void biayapinjam(int biaya) {
        Tanggal t1 = FormatTanggal(ID_Tanggal_Pinjam);
        Tanggal t2 = FormatTanggal(ID_Tanggal_Kembali);
        int lama = (t2.hari + t2.bulan * 30 + t2.tahun * 365) -
                   (t1.hari + t1.bulan * 30 + t1.tahun * 365);
        biaya_pinjam = biaya * lama;
    }

    void tampilkan() const {
        cout << "ID Member: " << ID_Member
             << ", ID Buku: " << ID_Buku
             << ", Tanggal Kembali: " << ID_Tanggal_Kembali
             << ", Tanggal Pinjam: " << ID_Tanggal_Pinjam << endl;
        cout << "Biaya Peminjaman: " << biaya_pinjam << endl;
    }

    int biaya() const { return biaya_pinjam; }
};

class report {
public:
    void report_peminjaman(const form_peminjaman &pinjam,
                           const form_pengembalian &pengembalian) {
        cout << "\n=== Laporan Peminjaman & Pengembalian Buku ===\n";
        pinjam.tampilkan();
        pengembalian.tampilkan();
    }

    void report_peminjaman(const form_peminjaman &pinjam) {
        cout << "\n=== Laporan Peminjaman Saja ===\n";
        pinjam.tampilkan();
    }

    void report_status_member(const Daftar_Member &member) {
        cout << "\n=== Laporan Status Member ===\n";
        member.tampilkan();
    }
    void report_pendapatan(int totalPendapatan) {
        cout << "\n=== Laporan Pendapatan ===\n";
        cout << "Total Pendapatan: " << totalPendapatan << endl;
    }
};

int main() {
    vector<Daftar_Buku> daftar_buku;
    vector<Daftar_Member> members;
    vector<Daftar_Pegawai> pegawai_list;
    vector<form_peminjaman> peminjaman;
    vector<form_pengembalian> pengembalian;

    string tgl_pinjam, tgl_kembali;
    Daftar_Buku::IsiDaftarBuku(daftar_buku);

    int pilihan;
    do {
        cout << "\n===== Sistem Informasi Perpustakaan =====\n";
        cout << "1. Daftar Buku\n2. Daftar Member\n3. Daftar Pegawai\n";
        cout << "4. Form Peminjaman\n5. Form Pengembalian\n6. Laporan\n7. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            int sub;
            cout << "1. Lihat Daftar Buku\n2. Tambah Buku Baru\nPilihan: ";
            cin >> sub;
            if (sub == 1)
                Daftar_Buku::tampilkanDaftarBuku(daftar_buku);
            else if (sub == 2) {
                int id; string judul;
                cout << "ID Buku: "; cin >> id;
                cout << "Judul: "; cin.ignore(); getline(cin, judul);
                daftar_buku.push_back(Daftar_Buku(id, judul));
            }
            break;
        }
        case 2: {
            int id; string nama;
            cout << "ID Member: "; cin >> id;
            cout << "Nama Member: "; cin.ignore(); getline(cin, nama);
            members.emplace_back(id, nama);
            members.back().tampilkan();
            break;
        }
        case 3: {
            int id; string nama;
            cout << "ID Pegawai: "; cin >> id;
            cout << "Nama Pegawai: "; cin.ignore(); getline(cin, nama);
            pegawai_list.emplace_back(id, nama);
            pegawai_list.back().tampilkan();
            break;
        }
        case 4: {
            int idm, idb;
            cout << "ID Member: "; cin >> idm;
            cout << "ID Buku: "; cin >> idb;
            cout << "Tanggal Pinjam (dd-mm-yy): "; cin >> tgl_pinjam;
            peminjaman.emplace_back(idm, idb, tgl_pinjam);
            peminjaman.back().tampilkan();
            for (auto &m : members)
                if (m.getIDMember() == idm) m.tambahpeminjaman();
            break;
        }
        case 5: {
            int idm, idb;
            cout << "ID Member: "; cin >> idm;
            cout << "ID Buku: "; cin >> idb;
            cout << "Tanggal Kembali (dd-mm-yy): "; cin >> tgl_kembali;
            pengembalian.emplace_back(idm, idb, tgl_kembali, tgl_pinjam, 1000);
            pengembalian.back().biayapinjam(1000);
            pengembalian.back().tampilkan();
            break;
        }
        case 6: {
            report r;
            if (!peminjaman.empty())
                r.report_peminjaman(peminjaman.back()); 
            if (!pengembalian.empty())
                r.report_peminjaman(peminjaman.back(), pengembalian.back());
            break;
        }
        }
    } while (pilihan != 7);

    return 0;
}
