#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

void binary_search(const char arr[], int size, char cari) {
    int awal = 0;
    int akhir = size - 1;
    bool found = false;

    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;
        if (arr[tengah] == cari) {
            found = true;
            cout << "\nHuruf '" << cari << "' ditemukan pada indeks ke-" << tengah << endl;
            break;
        } else if (arr[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (!found) {
        cout << "\nHuruf '" << cari << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main() {
    string kalimat = "anitA";
    char cari;

    cout << "Kata: anitA" << endl;
    kalimat.erase(remove(kalimat.begin(), kalimat.end(), ' '), kalimat.end());

    int size = kalimat.length();
    char* array = new char[size];
    strncpy(array, kalimat.c_str(), size);

    cout << "Masukkan huruf yang ingin Anda cari: ";
    cin >> cari;

    binary_search(array, size, cari);

    delete[] array;

    return 0;
}
