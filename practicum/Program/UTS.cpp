#include <bits/stdc++.h>
using namespace std;

class Penilaian{
    private:
        int presensi;
        double NilaiTugas, NilaiQuiz, NilaiSoftskill, NilaiUTS, NilaiUAS;
    public:
        Penilaian(int p, double tugas, double quiz, double soft, double uts, double uas) {
            presensi = p;
            NilaiTugas = tugas;
            NilaiQuiz = quiz;
            NilaiSoftskill = soft;
            NilaiUTS = uts;
            NilaiUAS = uas;
        }
        
        double hitungNilaiAkhir() {
            double nilaiUAS = (presensi >= 75) ? NilaiUAS * 0.25 : 0;
            return (NilaiTugas * 0.2) + (NilaiQuiz * 0.2) + (NilaiSoftskill * 0.1) + (NilaiUTS * 0.25) + nilaiUAS;
        }
        
        char konversiNilai(double nilai) {
            if (nilai >= 86) return 'A';
            else if (nilai >= 78) return 'B';
            else if (nilai >= 70) return 'C';
            else if (nilai >= 62) return 'D';
            else if (nilai >= 54) return 'E';
            else return 'F';
        }
        
        void tampilkanHasil() {
            double nilaiAkhir = hitungNilaiAkhir();
            char huruf = konversiNilai(nilaiAkhir);
            cout << "Nilai Akhir: " << nilaiAkhir << endl;
            cout << "Grade: " << huruf << endl;
        }
};

int main() {
    int presensi;
    double tugas, quiz, softskill, uts, uas;
    
    cout << "=== SISTEM PENILAIAN PBO ===" << endl;
    cout << "Masukkan Presensi (%): ";
    cin >> presensi;
    cout << "Masukkan Nilai Tugas: ";
    cin >> tugas;
    cout << "Masukkan Nilai Quiz: ";
    cin >> quiz;
    cout << "Masukkan Nilai Softskill: ";
    cin >> softskill;
    cout << "Masukkan Nilai UTS: ";
    cin >> uts;
    cout << "Masukkan Nilai UAS: ";
    cin >> uas;
    
    Penilaian mahasiswa(presensi, tugas, quiz, softskill, uts, uas);
    cout << "\n=== HASIL PENILAIAN ===" << endl;
    mahasiswa.tampilkanHasil();
    
    return 0;
}