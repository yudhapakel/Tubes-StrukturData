#include "ruteWIsata.h"
#include <climits>
#include <cstring>

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

double estimasiWakti(double jarak, double kecepatan) {
    return jarak / kecepatan;
}

void rekomendasiTempatWisata(ruteWisata rute[], int n) {
    cout << "Rekomendasi Tempat wisata terdekat dari tempat anda: " << endl;
    double minJarak = rute[0].jarak;
    string namaWisata = rute[0].nama;
    for (int i = 0; i < n; i++) {
        if (rute[i].jarak < minJarak) {
            minJarak = rute[i].jarak;
            namaWisata = rute[i].nama;
        }
    }
    cout << "Nama Tempat Wisata: " << namaWisata << endl;
}

void hitungJarakTerpendek(double graph[MAX_TEMPAT], int n, int start, int end) {
    bool visited[MAX_TEMPAT] = {false};
    double jarak[MAX_TEMPAT];
    int prev[MAX_TEMPAT];

    for (int i = 0; i < n; i++) {
        jarak[i] = DBL_MAX;
        prev[i] = -1;
    }
    jarak[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        double minJarak = DBL_MAX;
        int minIndex = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && jarak[v] < minJarak) {
                minJarak = jarak[v];
                minIndex = v;
        }
    }

    int u = minIndex;
    visited[u] = true;

    for (int v = 0; v < n; v++) {
        if(!visited[v] && graph[u][v] && jarak[u] != DBL_MAX && jarak[u] + graph[u][v] < jarak[v]) {
            jarak[v] = jarak[u] + graph[u][v];
            prev[v] = u;
        }
    }
}

    cout << "jarak terpendek: " << start << "ke" << end << "adalah" << jarak[end] << "km";
    cout << "melalui jalur: ";
    int crawl = end;
    while (/* condition */)
    {
        /* code */
    }
    

}


void salesmanProblem(double graph[MAX_TEMPAT], int n);