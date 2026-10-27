#include <bits/stdc++.h>
using namespace std;

class PenilaianPBO{
    public:
        virtual double kriteria_penilaian() = 0;
        virtual void tampilkan() = 0;
        virtual ~PenilaianPBO() = default;
};

class Penilaian : public PenilaianPBO{
    private:
        int presensi;
        double persentasepresensi;
        int totalpertemuan = 14;
        double NilaiTugas, NilaiQuiz, NilaiSoftskill, NilaiUTS, NilaiUAS;
    public:
        Penilaian(int presensi, double NilaiTugas, double NilaiQuiz, double NilaiSoftskill, double NilaiUTS, double NilaiUAS){
            this->presensi = presensi;
            this->NilaiTugas = NilaiTugas;
            this->NilaiQuiz = NilaiQuiz;
            this->NilaiSoftskill = NilaiSoftskill;
            this->NilaiUTS = NilaiUTS;
            this->NilaiUAS = NilaiUAS;
            this->persentasepresensi = 0.0;
        }
        
        Penilaian(double persentase, double NilaiTugas, double NilaiQuiz, double NilaiSoftskill, double NilaiUTS, double NilaiUAS){
            this->persentasepresensi = persentase;
            this->presensi = -1; 
            this->NilaiTugas = NilaiTugas;
            this->NilaiQuiz = NilaiQuiz;
            this->NilaiSoftskill = NilaiSoftskill;
            this->NilaiUTS = NilaiUTS;
            this->NilaiUAS = NilaiUAS;
        }
        double presensimahasiswa(){
            if(presensi >= 0) return (static_cast<double>(presensi)/totalpertemuan)*100.0;
            return persentasepresensi; 
        }

        double kriteria_penilaian() override {
            double absen = presensimahasiswa();
            if(absen < 75.0){
                double nilaiAkhir = (0.2 * NilaiTugas) + (0.2 * NilaiQuiz) + (0.1 * NilaiSoftskill) + (0.25 * NilaiUTS);
                cout << "Presensi " << fixed << setprecision(2) << absen << "% < 75%, Anda tidak diizinkan mengikuti UAS." << endl;
                return nilaiAkhir;
            }else{
                double nilaiAkhir = (0.2 * NilaiTugas) + (0.2 * NilaiQuiz) + (0.1 * NilaiSoftskill) + (0.25 * NilaiUTS) + (0.25 * NilaiUAS);
                return nilaiAkhir;
            }
        }   
        string hitung_grade(double nilaiAkhir){
            if(nilaiAkhir >= 86.0 && nilaiAkhir <= 100.0) return "A";
            else if(nilaiAkhir >= 78.0) return "AB";
            else if(nilaiAkhir >= 70.0) return "B";
            else if(nilaiAkhir >= 62.0) return "BC";
            else if(nilaiAkhir >= 54.0) return "C";
            else if(nilaiAkhir >= 40.0) return "D";
            else return "E";
        }
        void tampilkan() override {
            double absen = presensimahasiswa();
            cout << "Persentase Presensi: " << fixed << setprecision(2) << absen << "%" << endl;
            double akhir = kriteria_penilaian();
            cout << "Nilai Akhir: " << fixed << setprecision(2) << akhir << endl;
            cout << "Grade: " << hitung_grade(akhir) << endl;
        }
};

int main(){
    int presensi;
    double NilaiTugas, NilaiQuiz, NilaiSoftskill, NilaiUTS, NilaiUAS;
    cout << "Masukkan Jumlah Presensi: ";
    cin >> presensi;
    cout << "Masukkan Nilai Tugas: ";
    cin >> NilaiTugas;
    cout << "Masukkan Nilai Quiz: ";
    cin >> NilaiQuiz;
    cout << "Masukkan Nilai Softskill: ";
    cin >> NilaiSoftskill;
    cout << "Masukkan Nilai UTS: ";
    cin >> NilaiUTS;
    cout << "Masukkan Nilai UAS: ";
    cin >> NilaiUAS;

    Penilaian p(presensi, NilaiTugas, NilaiQuiz, NilaiSoftskill, NilaiUTS, NilaiUAS);
    p.tampilkan();

    return 0;
}