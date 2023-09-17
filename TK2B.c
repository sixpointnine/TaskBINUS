#include <stdio.h>
#include <string.h>

int main() {
    int JumlahMahasiswa;

    // Meminta jumlah mahasiswa hingga jumlahnya minimal 10
    do {
        printf("Masukkan jumlah mahasiswa (minimal 10): ");
        scanf("%d", &JumlahMahasiswa);
        if (JumlahMahasiswa < 10) {
            printf("Jumlah mahasiswa harus minimal 10. Coba lagi.\n");
        }
    } while (JumlahMahasiswa < 10);

    char Nama[JumlahMahasiswa][100];
    int NIM[JumlahMahasiswa];
    int Tugas[JumlahMahasiswa];
    int Quiz[JumlahMahasiswa];
    int UAS[JumlahMahasiswa];
    int Praktek[JumlahMahasiswa];
    int Absensi[JumlahMahasiswa];
    char Grade[JumlahMahasiswa][3];
    double RataRata[JumlahMahasiswa];

    double RataRataKeseluruhan = 0.0;

    for (int i = 0; i < JumlahMahasiswa; i++) {
        printf("\n-------------------------\n");
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Masukkan nama: ");
        scanf("%s", Nama[i]);
        printf("Masukkan NIM: ");
        scanf("%d", &NIM[i]);
        printf("Masukkan nilai tugas: ");
        scanf("%d", &Tugas[i]);
        printf("Masukkan nilai Quiz: ");
        scanf("%d", &Quiz[i]);
        printf("Masukkan nilai UAS: ");
        scanf("%d", &UAS[i]);
        printf("Masukkan nilai Praktek: ");
        scanf("%d", &Praktek[i]);
        printf("Masukkan nilai Absensi: ");
        scanf("%d", &Absensi[i]);
        
        int NilaiAkhir = (Tugas[i] + Quiz[i] + UAS[i] + Praktek[i] + Absensi[i]) / 5;

        if (NilaiAkhir >= 85) {
            strcpy(Grade[i], "A");
        } else if (NilaiAkhir >= 75) {
            strcpy(Grade[i], "B");
        } else if (NilaiAkhir >= 65) {
            strcpy(Grade[i], "C");
        } else if (NilaiAkhir >= 55) {
            strcpy(Grade[i], "D");
        } else {
            strcpy(Grade[i], "E");
        }

        RataRata[i] = NilaiAkhir;
        RataRataKeseluruhan += NilaiAkhir;

        printf("Grade Mahasiswa ke-%d: %s\n", i + 1, Grade[i]);
        printf("Average Score Mahasiswa ke-%d: %.2lf\n", i + 1, RataRata[i]);

        // Tampilkan pesan "Tidak Lulus" jika Grade adalah D atau E
        if (strcmp(Grade[i], "D") == 0 || strcmp(Grade[i], "E") == 0) {
            printf("Status: Tidak Lulus\n");
        }
    }

    RataRataKeseluruhan /= JumlahMahasiswa;

    printf("\n-------------------------\n");
    printf("Rata-rata keseluruhan nilai mahasiswa: %.2lf\n", RataRataKeseluruhan);

    return 0;
}

