#include <stdio.h>

int main() {
    double totalBelanja;
    char belanjaLagi;
    int jumlahTransaksi = 0;
    double totalBelanjaAkhir = 0.0;
    double diskonTotalBelanja = 0.0;
    double diskonJumlahTransaksi = 0.0;

    printf("**PROGRAM UNTUK MENGHITUNG DISKON BELANJA**\n");
    printf("\n------------------------------------------\n");

    do {
        printf("\nMasukkan nilai total belanja (rupiah):Rp. ");
        scanf("%lf", &totalBelanja);

        totalBelanjaAkhir += totalBelanja;
        jumlahTransaksi++;

        printf("Belanja lagi? (Y/N): ");
        scanf(" %c", &belanjaLagi);
    } while (belanjaLagi == 'Y' || belanjaLagi == 'y');

    // Menghitung diskon dari total belanja
    if (totalBelanjaAkhir >= 200000 && totalBelanjaAkhir < 500000) {
        diskonTotalBelanja = 0.1 * totalBelanjaAkhir; // 10% diskon
    } else if (totalBelanjaAkhir >= 550000 && totalBelanjaAkhir <= 1000000) {
        diskonTotalBelanja = 0.2 * totalBelanjaAkhir; // 20% diskon
    }else if (totalBelanjaAkhir > 1000000) {
        diskonTotalBelanja = 0.3 * totalBelanjaAkhir; // 30% diskon
    }

    // Menghitung diskon dari jumlah transaksi
    if (jumlahTransaksi >= 4) {
        diskonJumlahTransaksi = 0.2 * totalBelanjaAkhir; // 20% diskon
    }

    // Menampilkan harga akhir
    double hargaAkhir = totalBelanjaAkhir - diskonTotalBelanja - diskonJumlahTransaksi;
    printf("\n\nHarga akhir : Rp. %.0lf\n", hargaAkhir);

    // Menampilkan rekap transaksi
    printf("\nRekap Transaksi\n");
    printf("Total belanja              : Rp. %.0lf\n", totalBelanjaAkhir);
    printf("Diskon dari total belanja  : Rp. %.0lf\n", diskonTotalBelanja);
    printf("Diskon dari jumlah (4x transaksi/bln): Rp. %.0lf\n", diskonJumlahTransaksi);

    return 0;
}

