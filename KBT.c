#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerString(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char jenis_tiket[50];
    char hari[20];
    char waktu[20];
    char jam[20];
    int jumlah_tiket;
    double harga_dasar = 0.0;
    double faktor_hari = 1.0;
    double faktor_waktu = 1.0;
    double harga_per_tiket_final;
    double total_harga;

    // Judul program yang sudah diperbaiki
    printf("Program Pemesanan Tiket KBT\n");
    printf("----------------------------------\n");

    printf("Masukkan jenis tiket (Eksekutif, Bisnis, Ekonomi): ");
    fgets(jenis_tiket, sizeof(jenis_tiket), stdin);
    strtok(jenis_tiket, "\n");
    toLowerString(jenis_tiket);

    printf("Masukkan hari keberangkatan (Senin, Selasa, dst.): ");
    fgets(hari, sizeof(hari), stdin);
    strtok(hari, "\n");
    toLowerString(hari);

    printf("Masukkan kategori waktu keberangkatan (Pagi, Siang, Malam): ");
    fgets(waktu, sizeof(waktu), stdin);
    strtok(waktu, "\n");
    toLowerString(waktu);

    printf("Masukkan jam keberangkatan (misal: 09.00, 14.00): ");
    fgets(jam, sizeof(jam), stdin);
    strtok(jam, "\n");

    printf("Masukkan jumlah tiket: ");
    if (scanf("%d", &jumlah_tiket) != 1 || jumlah_tiket <= 0) {
        printf("Jumlah tiket tidak valid. Program berhenti.\n");
        return 1;
    }

    if (strcmp(jenis_tiket, "eksekutif") == 0) {
        harga_dasar = 200000.0;
    } else if (strcmp(jenis_tiket, "bisnis") == 0) {
        harga_dasar = 150000.0;
    } else if (strcmp(jenis_tiket, "ekonomi") == 0) {
        harga_dasar = 100000.0;
    } else {
        printf("Jenis tiket tidak valid. Program berhenti.\n");
        return 1;
    }

    if (strcmp(hari, "senin") == 0) {
        faktor_hari = 0.90;
    } else if (strcmp(hari, "jumat") == 0) {
        faktor_hari = 1.05;
    } else if (strcmp(hari, "sabtu") == 0 || strcmp(hari, "minggu") == 0) {
        faktor_hari = 1.10;
    }

    if (strcmp(waktu, "pagi") == 0) {
        faktor_waktu = 0.95;
    } else if (strcmp(waktu, "malam") == 0) {
        faktor_waktu = 1.05;
    }

    harga_per_tiket_final = harga_dasar * faktor_hari * faktor_waktu;

    total_harga = harga_per_tiket_final * jumlah_tiket;

    printf("\n--- Detail Pemesanan Tiket ---\n");
    printf("Jenis Tiket: %s\n", jenis_tiket);
    printf("Hari: %s\n", hari);
    printf("Waktu: %s\n", waktu);
    printf("Jam: %s\n", jam);
    printf("Banyak Tiket: %d\n", jumlah_tiket);
    printf("Harga per Tiket: Rp %.2f\n", harga_per_tiket_final);
    printf("Total Harga: Rp %.2f\n", total_harga);
    printf("------------------------------\n");

    return 0;
}
