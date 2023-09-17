#include <stdio.h>
#include <stdlib.h> // Untuk menggunakan fungsi system

int main() {
    while (1) { // Loop tak terbatas
        float mulaiMain;
        float selesaiMain;
        float lamaMain;
        float hargaPerJam = 10000.0;
        float diskon = 0.0;

        // Membersihkan layar
        #ifdef _WIN32
        system("cls"); // Untuk Windows
        #else
        system("clear"); // Untuk Unix/Linux
        #endif
		
		 printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    	printf("-=- Program Billing JCCA Gaming Store -=-\n");
    	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        // Input waktu mulai pemakaian dan waktu selesai pemakaian
        printf("Masukkan waktu mulai pemakaian dalam jam (00.00:24.00): ");
        scanf("%f", &mulaiMain);
        printf("Masukkan waktu selesai pemakaian dalam jam (00.00:24.00): ");
        scanf("%f", &selesaiMain);

        // Validasi waktu mulai dan waktu selesai dalam rentang 00.00-24.00
        if (mulaiMain < 0 || mulaiMain > 24 || selesaiMain < 0 || selesaiMain > 24 || mulaiMain > selesaiMain) {
            printf("Waktu pemakaian tidak valid.\n");
            continue; // Mengulangi loop jika input tidak valid
        }

        // Menghitung lama pemakaian
        lamaMain = selesaiMain - mulaiMain;

        // Validasi lama pemakaian harus lebih dari 0 jam
        if (lamaMain <= 0) {
            printf("Lama pemakaian tidak valid.\n");
            continue; // Mengulangi loop jika input tidak valid
        }

        // Menghitung diskon berdasarkan lama pemakaian
        if (lamaMain > 10) {
            diskon = 0.25; // Diskon 25% untuk lebih dari 8 jam
        } else if (lamaMain > 8) {
            diskon = 0.20; // Diskon 20% untuk lebih dari 6 jam
        } else if (lamaMain > 6) {
            diskon = 0.15; // Diskon 15% untuk lebih dari 4 jam
        } else if (lamaMain > 4) {
            diskon = 0.10; // Diskon 15% untuk lebih dari 4 jam
        }else {
            diskon = 0; // Tidak ada diskon untuk waktu bermain kurang dari 8 jam 
        }

        // Menghitung jumlah yang harus dibayarkan
        float totalHarga = hargaPerJam * lamaMain;
        float totalDiskon = totalHarga * diskon;
        float totalBayar = totalHarga - totalDiskon;

        // Menampilkan informasi tagihan
        printf("Lama pemakaian: %.2f jam\n", lamaMain);
        printf("Harga per jam: Rp %.2f\n", hargaPerJam);
        printf("Diskon: %.0f%%\n", diskon * 100);
        printf("Total harga: Rp %.2f\n", totalHarga);
        printf("Total diskon: Rp %.2f\n", totalDiskon);
        printf("Total yang harus dibayarkan: Rp %.2f\n", totalBayar);

        // Membersihkan newline (\n) dari stdin
        while (getchar() != '\n');

        // Menanyakan apakah pengguna ingin menginput data lagi
        char pilihan;
        printf("\nApakah Anda ingin menginput data lagi (Y/N)? ");
        scanf(" %c", &pilihan);

        if (pilihan != 'y' && pilihan != 'Y' ) {
            break; // Keluar dari loop utama jika pengguna menjawab bukan 'yes' atau 'Y'
        }
    }

    return 0;
}

