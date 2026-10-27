#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Daftar_Buku{
    private:
        int id_buku;
        string judul_buku;
    
    public: 
        Daftar_Buku(int id, string judul){
            id_buku = id;
            judul_buku = judul;
        }

        void tampilkan() const{
            cout << "ID Buku: " << setw(3) << setfill('0') << id_buku << ", Judul Buku: " << judul_buku << endl;
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
            };

        static void tampilkanDaftarBuku(const vector<Daftar_Buku> &daftar_buku) {
            for(const auto &buku : daftar_buku) {
                buku.tampilkan();
            }
        };
};

class Daftar_Pegawai{
    private:
        int id_pegawai;
        string nama_pegawai;
    
    public:
        Daftar_Pegawai(int id, string nama){
            id_pegawai = id;
            nama_pegawai = nama;
        }

        void tampilkan(){
            cout << "ID Pegawai: " << id_pegawai << ", Nama Pegawai: " << nama_pegawai << endl;
        }
};

class Daftar_Member{
    private:
        int id_member;
        string nama_member;
        string status_member = "Non Member";
    
    public:
        int jumlah_peminjaman = 0;
        Daftar_Member(int id, string nama){
            id_member = id;
            nama_member = nama;
        }
        
        void tambahpeminjaman() {
            jumlah_peminjaman++;
            if (jumlah_peminjaman >= 27) {
                status_member = "Level 3 (Free pinjam 5x)";
            } else if (jumlah_peminjaman >= 9) {
                status_member = "Level 2 (Free pinjam 3x)";
            } else if (jumlah_peminjaman >= 3) {
                status_member = "Level 1 (Free pinjam 1x)";
            }
            cout << "Status Member: " << status_member << endl;
        }

        int getIDMember() {
            return id_member; 
        }

        void tampilkan(){
            cout << "ID Member: " << id_member << ", Nama Member: " << nama_member << endl;
            cout << "Jumlah Peminjaman: " << jumlah_peminjaman << ", Status Member: " << status_member << endl;
        }
};

struct Tanggal {
    int hari, bulan, tahun;
};

Tanggal FormatTanggal(const string &tgl) {
    Tanggal t{};
    sscanf(tgl.c_str(), "%d-%d-%d", &t.hari, &t.bulan, &t.tahun);
    return t;
}

class form_peminjaman{  
    private:
        int ID_Member;
        int ID_Buku;
        string ID_Tanggal_Pinjam;

    
    public:
        int peminjaman = 0;
        form_peminjaman(int id_member, int id_buku, string id_tanggal_pinjam){
            ID_Member = id_member;
            ID_Buku = id_buku;
            ID_Tanggal_Pinjam = id_tanggal_pinjam;
        }

        void tampilkan(){
            cout << "ID Member: " << ID_Member 
            << ", ID Buku: " << ID_Buku 
            << ", Tanggal Pinjam: " << ID_Tanggal_Pinjam << endl;
        }

        string TanggalPinjam() { return ID_Tanggal_Pinjam; }
        int IDMember() { return ID_Member; }
        int IDBuku() { return ID_Buku; }
};  

class form_pengembalian{
    private:
        int ID_Member;
        int ID_Buku;
        string ID_Tanggal_Kembali;
        string ID_Tanggal_Pinjam; 
        int biaya_pinjam = 1000;
    
    public:
        form_pengembalian(int id_member, int id_buku, string id_tanggal_kembali, string id_tanggal_pinjam, int biaya){
            ID_Member = id_member;
            ID_Buku = id_buku;
            ID_Tanggal_Kembali = id_tanggal_kembali;
            ID_Tanggal_Pinjam = id_tanggal_pinjam; 
            biaya_pinjam = biaya;
        }

        void biayapinjam(int biaya) {
        Tanggal t1 = FormatTanggal(ID_Tanggal_Pinjam);
        Tanggal t2 = FormatTanggal(ID_Tanggal_Kembali);
        int lamapeminjaman = (t2.hari + t2.bulan * 30 + t2.tahun * 365) -
                             (t1.hari + t1.bulan * 30 + t1.tahun * 365);
        biaya_pinjam = biaya * lamapeminjaman ;
        }

        void tampilkan() {
        cout << "ID Member: " << ID_Member 
             << ", ID Buku: " << ID_Buku 
             << ", Tanggal Pinjam: " << ID_Tanggal_Pinjam 
             << ", Tanggal Kembali: " << ID_Tanggal_Kembali << endl;
        cout << "Biaya Peminjaman: " << biaya_pinjam << endl;
    }

    int biaya() const { return biaya_pinjam; }
};

class report{
    public:
        void report_peminjaman(form_peminjaman &pinjam, form_pengembalian &pengembalian) {
            cout << "\n=== Laporan Peminjaman & Pengembalian Buku ===" << endl;
            pengembalian.tampilkan();
        }
        void report_status_member(Daftar_Member &member) {
            cout << "\n=== Laporan Status Member ===" << endl;
            member.tampilkan();
        }
        void report_pendapatan(int totalPendapatan) {
            cout << "\n=== Laporan Pendapatan ===" << endl;
            cout << "Total Pendapatan: " << totalPendapatan << endl;
        }
};

int main(){
    vector<Daftar_Buku> daftar_buku;
    vector<Daftar_Member> members;
    vector<Daftar_Pegawai> list_pegawai;
    vector<form_peminjaman> peminjaman;
    vector<form_pengembalian> pengembalian;


    string tgl_pinjam, tgl_kembali;

    Daftar_Buku::IsiDaftarBuku(daftar_buku);
    int pilihan;
    do {
        cout << "\n===== Sistem Informasi Perpustakaan =====" << endl;
        cout << "1. Daftar Buku" << endl;
        cout << "2. Daftar Member" << endl;
        cout << "3. Daftar Pegawai" << endl;
        cout << "4. Form Peminjaman" << endl;
        cout << "5. Form Pengembalian" << endl;
        cout << "6. Laporan" << endl;
        cout << "7. Keluar" << endl;
        cout << "=========================================" << endl;
        cout << "Masukkan pilihan Menu(1-7): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            int subpilihan;
            cout << "\n--- Menu Daftar Buku ---" << endl;
            cout << "1. Lihat Daftar Buku" << endl;
            cout << "2. Tambah Buku Baru" << endl;
            cout << "Masukkan pilihan(1-2): ";
            cin >> subpilihan;

            switch (subpilihan) {
            case 1: {
                Daftar_Buku::tampilkanDaftarBuku(daftar_buku);
                break;
            }
            case 2: {
                int id;
                string judul;
                cout << "Masukkan ID Buku: "; cin >> id;
                cout << "Masukkan Judul Buku: ";
                cin.ignore();
                getline(cin, judul);
                daftar_buku.push_back(Daftar_Buku(id, judul));
                cout << "Proses penambahan buku berhasil." << endl;
            }
            break;
            }
            break;
        }
        case 2: {
            int id_member;
            string nama_member;
            cout << "Masukkan ID Member: "; cin >> id_member;
            cout << "Masukkan Nama Member: ";
            cin.ignore();
            getline(cin, nama_member);
            members.push_back(Daftar_Member(id_member, nama_member));
            members.back().tampilkan();
            break;
        }
        case 3: {
             int id_pegawai;
            string nama_pegawai;
            cout << "Masukkan ID Pegawai: "; cin >> id_pegawai;
            cout << "Masukkan Nama Pegawai: ";
            cin.ignore();
            getline(cin, nama_pegawai);
            list_pegawai.push_back(Daftar_Pegawai(id_pegawai, nama_pegawai));
            list_pegawai.back().tampilkan();
            break;
        }
        case 4: {
            int id_member, id_buku;
            cout << "Masukkan ID Member: "; cin >> id_member;
            cout << "Masukkan ID Buku: "; cin >> id_buku;
            cout << "Masukkan Tanggal Pinjam (dd-mm-yy): "; cin >> tgl_pinjam;
            peminjaman.push_back(form_peminjaman(id_member, id_buku, tgl_pinjam));
            peminjaman.back().tampilkan();
            if (!members.empty()) {
                for (auto &m : members) {
                    if (m.getIDMember() == id_member) {
                        m.tambahpeminjaman();
                        break;
                    }
                }
            }
            break;
        }
        case 5: {
            int id_member, id_buku;
            string  tgl_kembali;
            cout << "Masukkan ID Member: "; cin >> id_member;
            cout << "Masukkan ID Buku: "; cin >> id_buku;
            cout << "Masukkan Tanggal Kembali (dd-mm-yy): "; cin >> tgl_kembali;
            pengembalian.push_back(form_pengembalian(id_member, id_buku, tgl_kembali, tgl_pinjam, 1000));
            pengembalian.back().biayapinjam(1000);
            pengembalian.back().tampilkan();
            break;
        }
        case 6: {
            cout << "\n--- Menu Laporan ---" << endl;
            cout << "1. Laporan Peminjaman & Pengembalian" << endl;
            cout << "2. Laporan Status Member" << endl;
            cout << "3. Laporan Pendapatan" << endl;
            cout << "Masukkan pilihan(1-3): ";
            int laporanPilihan;
            cin >> laporanPilihan;

            report r;
            switch (laporanPilihan) {
                case 1: {
                    if (peminjaman.empty() || pengembalian.empty()) {
                        cout << "Belum ada data peminjaman/pengembalian." << endl;
                    } else {
                        for (size_t i = 0; i < min(peminjaman.size(), pengembalian.size()); i++) {
                            r.report_peminjaman(peminjaman[i], pengembalian[i]);
                        }
                    }
                    break;
                }
                case 2: {
                    if (members.empty()) {
                        cout << "Belum ada data member." << endl;
                    } else {
                        for (auto &m : members) {
                            r.report_status_member(m);
                        }
                    }
                    break;
                }
                case 3: {
                    if (pengembalian.empty()) {
                        cout << "Belum ada data pengembalian." << endl;
                    } else {
                        int totalPendapatan = 0;
                        for (auto &p : pengembalian) {
                            totalPendapatan += p.biaya();
                        }
                        r.report_pendapatan(totalPendapatan);
                    }
                    break;
                }
                default:
                    cout << "Pilihan laporan tidak valid!" << endl;
            }
            break;
        }
        case 7: {
            cout << "Keluar dari sistem. Terima kasih!" << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 7);

    return 0;
}


