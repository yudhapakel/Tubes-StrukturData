#include <iostream>
#include "ruteWisata.h" // Include header file
using namespace std;

void tampilkanMenu() {
    cout << "\n==== MENU RUTE WISATA ====\n";
    cout << "1. Tampilkan Semua Tempat Wisata\n";
    cout << "2. Validasi Input Tempat Wisata\n";
    cout << "3. Hitung Jarak Terpendek\n";
    cout << "4. Hitung Total Jarak Rute\n";
    cout << "5. Estimasi Waktu Perjalanan\n";
    cout << "6. Rekomendasi Tempat Wisata\n";
    cout << "7. Traveling Salesman Problem (TSP)\n";
    cout << "8. Keluar\n";
    cout << "Pilih menu: ";
} 
 
int main() {
    // Data tempat wisata
    ruteWisata wisata[MAX_TEMPAT] = {
        {"A", "Lokasi 1", 0},
        {"B", "Lokasi 2", 10},
        {"C", "Lokasi 3", 15},
        {"D", "Lokasi 4", 20}
    };
    int jumlahTempatWisata = 4;

    // Matriks jarak antar tempat wisata
    double graph[MAX_TEMPAT][MAX_TEMPAT] = {
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
            for (int i = 0; i < jumlahTempatWisata; i++) {
                cout << wisata[i].nama << " - " << wisata[i].lokasi << "\n";
            }
            break;
        }
        case 2: { // Validasi Input Tempat Wisata
            string nama;
            cout << "Masukkan nama tempat wisata untuk validasi: ";
            cin >> nama;
            cariTempatWisata(wisata, jumlahTempatWisata, nama);
            break;
        }
        case 3: { // Hitung Jarak Terpendek
            int start, end;
            cout << "Masukkan indeks tempat awal (0-3): ";
            cin >> start;
            cout << "Masukkan indeks tempat tujuan (0-3): ";
            cin >> end;
            hitungJarakTerpendek(graph, jumlahTempatWisata, start, end);
            break;
        }
        case 4: { // Hitung Total Jarak Rute
            double totalJarak = hitungJarakTotal(wisata, jumlahTempatWisata);
            cout << "\nTotal jarak rute: " << totalJarak << " km\n";
            break;
        }
        case 5: { // Estimasi Waktu Perjalanan
            double kecepatan;
            cout << "Masukkan kecepatan rata-rata (km/jam): ";
            cin >> kecepatan;
            if (!validasiInput(kecepatan)) {
                cout << "Kecepatan tidak valid.\n";
                break;
            }
            double totalJarak = hitungJarakTotal(wisata, jumlahTempatWisata);
            double waktu = hitungWaktuPerjalanan(totalJarak, kecepatan);
            cout << "Estimasi waktu perjalanan: " << waktu << " jam\n";
            break;
        }
        case 6: { // Rekomendasi Tempat Wisata
            rekomendasiTempatWisata(wisata, jumlahTempatWisata);
            break;
        }
        case 7: { // Traveling Salesman Problem (TSP)
            cout << "\nMenghitung rute terbaik untuk Traveling Salesman Problem...\n";
            salesmanProblem(graph, jumlahTempatWisata);
            break;
        }
        case 8: {
            cout << "Terima kasih telah menggunakan program ini!\n";
            break;
        }
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 8);

    return 0;
}
