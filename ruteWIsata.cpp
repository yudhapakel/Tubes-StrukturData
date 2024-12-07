#include "ruteWIsata.h"

using namespace std;

double hitungJarakTotal(ruteWisata rute[], int n)
{
    double totalJarak = 0;
    for (int i = 0; i < n; i++)
    {
        totalJarak += rute[i].jarak;
    }
    return totalJarak;
}
double hitungWaktuPerjalanan(double totalJarak, double kecepatan) {
    return totalJarak / kecepatan;
}
bool validasiInput(double jarak) {
    if (jarak >= 0) {
        return true;
    }
    return false;  
}
void cariTempatWisata(ruteWisata rute[], int n, string nama) {
    bool ditemukan = false;
    for(int i = 0; i < n; i++) {
        if (rute[i].nama == nama) {
            cout << "Nama Tempat Wisata: " << rute[i].nama << "di" << rute->lokasi[i] << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Nama Tempat Wisata tidak ditemukan" << endl;
    }
}
double estimasiWakti(double jarak, double kecepatan);
void rekomendasiTempatWisata(ruteWisata rute[], int n);