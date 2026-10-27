#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

class DifferentialDriveRobot {
private:
    double x;
    double y;
    double theta;
    double r;
    double L;

public:
    DifferentialDriveRobot(double x0 = 0.0, double y0 = 0.0, double theta0 = 0.0,
                           double jarijari = 0.05, double jarakantarroda = 0.20) {
        x = x0; y = y0; theta = theta0;
        r = jarijari; L = jarakantarroda;
    }

    void update(float wL, float wR, float dt) {
        double v = (r / 2.0) * (wR + wL);
        double omega = (r / L) * (wR - wL);

        double vx = v * cos(theta);
        double vy = v * sin(theta);

        double dx = vx * dt;
        double dy = vy * dt;
        double dtheta = omega * dt;

        x += dx;
        y += dy;
        theta += dtheta;

        while (theta > M_PI) theta -= 2.0 * M_PI;
        while (theta <= -M_PI) theta += 2.0 * M_PI;
    }


    double getX() const { return x; }
    double getY() const { return y; }
    double getTheta() const { return theta; }
};

int main() {
    const double dt = 0.1;
    const double durasiPerPerintah = 5.0;
    const int langkahPerPerintah = static_cast<int>(durasiPerPerintah / dt);
    const int langkahCetak = static_cast<int>(1.0 / dt);
    DifferentialDriveRobot robot(0.0, 0.0, 0.0, 0.05, 0.20);

    cout << fixed << setprecision(4);
    cout << "Simulasi Differential Drive Robot (multi-input user)\n";
    cout << "Perintah tersedia: maju, mundur, kiri, kanan, stop, selesai\n";

    string command;
    while (true) {
        cout << "\nMasukkan perintah: ";
        if (!(cin >> command)) break;


        for (auto &c : command) c = tolower(c);

        if (command == "selesai") {
            cout << "Program dihentikan oleh user.\n";
            break;
        }

        float wL = 0.0f, wR = 0.0f;
        const float w_lin = 10.0f;
        const float w_turn = 8.0f;

        if (command == "maju") {
            wL = w_lin;
            wR = w_lin;
        } else if (command == "mundur") {
            wL = -w_lin;
            wR = -w_lin;
        } else if (command == "kiri") {
            wL = -w_turn;
            wR = w_turn;
        } else if (command == "kanan") {
            wL = w_turn;
            wR = -w_turn;
        } else if (command == "stop") {
            wL = 0.0f;
            wR = 0.0f;
        } else {
            cout << "Perintah tidak dikenal. Gunakan: maju, mundur, kiri, kanan, stop, selesai\n";
            continue;
        }

        double waktu = 0.0;
        for (int langkah = 0; langkah < langkahPerPerintah; ++langkah) {
            robot.update(wL, wR, dt);
            waktu += dt;
            if ((langkah + 1) % langkahCetak == 0) {
                cout << "t = " << setw(5) << waktu << " s"
                     << " | x = " << setw(8) << robot.getX()
                     << " m, y = " << setw(8) << robot.getY()
                     << " m, theta = " << setw(8) << robot.getTheta() << " rad\n";
            }
        }

        cout << "Perintah '" << command << "' selesai dieksekusi selama " << durasiPerPerintah << " s.\n";
    }

    cout << "Akhir simulasi.\n";
    return 0;
}
