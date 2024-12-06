#ifndef RUTEWISATA_H_INCLUDED
#define RUTEWISATA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct ruteWisata{
   string nama;
    string lokasi;
    double jarak;
};


double hitungJarakTotal(ruteWisata rute[], int n);
double hitungWaktuPerjalanan(double totalJarak, double kecepatan);
bool validasiInput(double jarak);
void cariTempatWisata(ruteWisata rute[], int n, string nama);
double estimasiWakti(double jarak, double kecepatan);
void rekomendasiTempatWisata(ruteWisata rute[], int n);


#endif // RUTEWISATA_H_INCLUDED