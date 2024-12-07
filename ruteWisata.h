#ifndef RUTEWISATA_H_INCLUDED
#define RUTEWISATA_H_INCLUDED

#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

const int MAX_TEMPAT = 100;

typedef namaWisata;

struct ruteWisata{
   namaWisata nama;
    string lokasi;
    double jarak;
};


double hitungJarakTotal(ruteWisata rute[], int n);
double hitungWaktuPerjalanan(double totalJarak, double kecepatan);
bool validasiInput(double jarak);
void cariTempatWisata(ruteWisata rute[], int n, string nama);
double estimasiWakti(double jarak, double kecepatan);
void rekomendasiTempatWisata(ruteWisata rute[], int n);
void hitungJarakTerpendek(double graph[MAX_TEMPAT], int n, int start, int end);
void salesmanProblem(double graph[MAX_TEMPAT], int n);


#endif // RUTEWISATA_H_INCLUDED