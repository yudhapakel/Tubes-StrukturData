#include "ruteWIsata.h"
#include <climits>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <float.h>

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

double hitungWaktuPerjalanan(double totalJarak, double kecepatan)
{
    return totalJarak / kecepatan;
}

bool validasiInput(double jarak)
{ 
    if (jarak >= 0)
    {
        return true;
    }
    return false;
}

void cariTempatWisata(ruteWisata rute[], int n, string nama)
{
    bool ditemukan = false;
    for (int i = 0; i < n; i++)
    {
        if (rute[i].nama == nama)
        {
            cout << "Nama Tempat Wisata: " << rute[i].nama << endl;
            cout << "Lokasi: " << rute[i].lokasi[0] << endl; // Misal lokasi lebih detail
            cout << "Jarak: " << rute[i].jarak << " km" << endl; // Tambahkan jarak
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Nama Tempat Wisata \"" << nama << "\" tidak ditemukan." << endl; // Lebih spesifik
    }
}

int cariIndeksTempatWisata(const ruteWisata wisata[], int jumlahTempatWisata, const string& nama) {
    for (int i = 0; i < jumlahTempatWisata; i++) {
        if (wisata[i].nama == nama) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika nama tidak ditemukan
}


void estimasiWaktuPerjalanan(ruteWisata wisata[], int jumlahTempatWisata, double graph[MAX_TEMPAT][MAX_TEMPAT]) {
    string asal, tujuan;
    cout << "\n=== Estimasi Waktu Perjalanan ===\n";
    cout << "Masukkan nama tempat asal: ";
    cin.ignore(); // Membersihkan buffer
    getline(cin, asal);
    cout << "Masukkan nama tempat tujuan: ";
    getline(cin, tujuan);

    // Cari indeks asal dan tujuan
    int indeksAsal = cariIndeksTempatWisata(wisata, jumlahTempatWisata, asal);
    int indeksTujuan = cariIndeksTempatWisata(wisata, jumlahTempatWisata, tujuan);

    if (indeksAsal == -1 || indeksTujuan == -1) {
        cout << "Tempat wisata tidak ditemukan.\n";
        return;
    }

    double jarak = graph[indeksAsal][indeksTujuan];
    double kecepatan;

    cout << "Masukkan kecepatan rata-rata (km/jam): ";
    cin >> kecepatan;

    if (kecepatan <= 0) {
        cout << "Kecepatan tidak valid.\n";
        return;
    }

    double waktu = jarak / kecepatan;
    cout << "Estimasi waktu perjalanan dari " << asal << " ke " << tujuan << ": " << waktu << " jam.\n";
}

void rekomendasiTempatWisata(ruteWisata rute[], int n)
{
    cout << "Rekomendasi Tempat wisata terdekat dari tempat anda: " << endl;
    double minJarak = rute[0].jarak;
    string namaWisata = rute[0].nama;
    for (int i = 0; i < n; i++)
    {
        if (rute[i].jarak < minJarak)
        {
            minJarak = rute[i].jarak;
            namaWisata = rute[i].nama;
        }
    }
    cout << "Nama Tempat Wisata: " << namaWisata << endl;
}

void hitungJarakTerpendek(double graph[MAX_TEMPAT][MAX_TEMPAT], int n, int start, int end)
{
    bool visited[MAX_TEMPAT] = {false};
    double jarak[MAX_TEMPAT];
    int prev[MAX_TEMPAT];

    for (int i = 0; i < n; i++)
    {
        jarak[i] = DBL_MAX;
        prev[i] = -1;
    }
    jarak[start] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        double minJarak = DBL_MAX;
        int minIndex = -1;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && jarak[v] < minJarak)
            {
                minJarak = jarak[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != DBL_MAX && jarak[u] != DBL_MAX && jarak[u] + graph[u][v] < jarak[v])
            {
                jarak[v] = jarak[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    cout << "Jarak terpendek antara tempat " << start << " dan " << end << " adalah " << jarak[end] << " km." << endl;
    cout << "Jalur yang dilalui: ";
    int crawl = end;
    while (crawl != -1)
    {
        cout << crawl << (crawl == start ? "" : " <- ");
        crawl = prev[crawl];
    }
    cout << endl;
}


void salesmanProblem(double graph[MAX_TEMPAT][MAX_TEMPAT], int n, double biayaPerKm)
{
    int perm[MAX_TEMPAT];
    double minCost = DBL_MAX;
    int bestPath[MAX_TEMPAT];

    
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }

    
    do
    {
        double currentCost = 0;
        
        for (int j = 0; j < n - 1; j++)
        {
            currentCost += graph[perm[j]][perm[j + 1]];
        }

        currentCost += graph[perm[n - 1]][perm[0]];

        if (currentCost < minCost)
        {
            minCost = currentCost;
            for (int i = 0; i < n; i++)
            {
                bestPath[i] = perm[i];
            }
        }
    } while (next_permutation(perm, perm + n));

    // Konversi jarak menjadi biaya
    double totalCost = minCost * biayaPerKm;

    // Menampilkan jalur optimal
    cout << "Jalur terbaik dengan biaya total terendah adalah: ";
    for (int i = 0; i < n; i++)
    {
        cout << bestPath[i] << (i == n - 1 ? "" : " -> ");
    }
    cout << "\nTotal biaya: Rp" << totalCost << endl;
}

