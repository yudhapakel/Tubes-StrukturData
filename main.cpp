#include <iostream>
#include "ruteWisata.h" 
using namespace std;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n==== MENU RUTE WISATA ====\n";
    cout << "1. Tampilkan Semua Tempat Wisata\n";
    cout << "2. Validasi Input Tempat Wisata\n";
    cout << "3. Hitung Jarak Terpendek (TSP)\n";
    cout << "4. Hitung Total Jarak Rute\n";
    cout << "5. Estimasi Waktu Perjalanan\n";
    cout << "6. Rekomendasi Tempat Wisata\n";
    cout << "7. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    // Data tempat wisata
    TempatWisata wisata[MAX_TEMPAT] = {
        {"A", "Lokasi 1", 0},
        {"B", "Lokasi 2", 0},
        {"C", "Lokasi 3", 0},
        {"D", "Lokasi 4", 0}
    };
    int jumlahTempatWisata = 4;

    // Matriks jarak antar tempat wisata
    int graph[MAX_WISATA][MAX_WISATA] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: { // Tampilkan Semua Tempat Wisata
            cout << "\nDaftar Tempat Wisata:\n";
            tampilkanTempatWisata(wisata, jumlahTempatWisata);
            break;
        }
        case 2: { // Validasi Input Tempat Wisata
            string nama;
            cout << "Masukkan nama tempat wisata untuk validasi: ";
            cin >> nama;
            if (validasiTempatWisata(nama, wisata, jumlahTempatWisata)) {
                cout << "Tempat wisata ditemukan!\n";
            } else {
                cout << "Tempat wisata tidak ditemukan.\n";
            }
            break;
        }
        case 3: { // Hitung Jarak Terpendek (TSP)
            cout << "\nMenghitung jarak terpendek menggunakan algoritma TSP...\n";
            int shortestDistance = travelingSalesman(graph, jumlahTempatWisata);
            cout << "Jarak terpendek: " << shortestDistance << " km\n";
            break;
        }
        case 4: { // Hitung Total Jarak Rute
            cout << "\nMenghitung total jarak rute...\n";
            double totalJarak = hitungTotalJarak(wisata, jumlahTempatWisata);
            cout << "Total jarak rute: " << totalJarak << " km\n";
            break;
        }
        case 5: { // Estimasi Waktu Perjalanan
            cout << "\nEstimasi waktu perjalanan...\n";
            double waktu = estimasiWaktu(wisata, jumlahTempatWisata, 60); // Kecepatan rata-rata 60 km/jam
            cout << "Estimasi waktu perjalanan: " << waktu << " jam\n";
            break;
        }
        case 6: { // Rekomendasi Tempat Wisata
            cout << "\nRekomendasi Tempat Wisata:\n";
            rekomendasiTempatWisata(wisata, jumlahTempatWisata);
            break;
        }
        case 7: {
            cout << "Terima kasih telah menggunakan program ini!\n";
            break;
        }
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 7);

    return 0;
}
