#include <bits/stdc++.h>
#include <cctype>
using namespace std;

bool tandabaca(const string& s) {
    for (unsigned char ch : s) {
        if (ispunct(ch)) return true;
    }
    return false;
}

int main() {
    string username;
    string password;
    string inputUsername;
    string inputPassword;

    cout << "Hebat E-learning Unair Login\n\n";

    username = "163241037";
    password = "bismillah PBO dapet A";

    try{
        cout << "Enter username: ";
        getline(cin,inputUsername);
        cout << "Enter password: ";
        getline(cin,inputPassword);

        if (tandabaca(inputUsername) || tandabaca(inputPassword)) {
            throw runtime_error("error : username/password tidak boleh mengandung tanda baca");
        }

        if (inputUsername != username || inputPassword != password) {
            throw runtime_error("Password or username incorrect!");
        }
        cout << "Login successful!" << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }
}           

