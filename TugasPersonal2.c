#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Month {
    char name[20];
};

int countVowels(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'e' || str[i] == 'o' || str[i] == 'A' || str[i] == 'I' || str[i] == 'U' || str[i] == 'E' || str[i] == 'O') {
            count++;
        }
    }
    return count;
}

int main() {

    struct Month months[12] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"}, {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}};

    char input;
    int validInput = 0;
    int found = 0;

    printf("=======================================\n");
    printf("===== Program Hitung Huruf V & C ======\n");
    printf("=======================================\n");

    do {
        printf("\nMasukkan huruf (A-Z atau a-z): ");
        scanf(" %c", &input);

        if (!isalpha(input)) {
            printf("Input harus berupa huruf.\n");
        } else {
            validInput = 1;
            input = toupper(input);
            printf("Bulan yang dimulai dengan huruf %c adalah: \n", input);
            int count = 1;
            for (int i = 0; i < 12; i++) {
                if (months[i].name[0] == input) {
                    printf("%d. %s\n", count, months[i].name);
                    count++;
                    found = 1;
                }
            }

            if (!found) {
                printf("Tidak ada bulan yang dimulai dengan huruf %c.\n", input);
                validInput = 0;
            }
        }
    } while (!validInput);

    char selectedMonth[20];
    int validMonth = 0;

    do {
        printf("Masukkan nama bulan yang dipilih (atau nomor urut): ");
        scanf("%s", selectedMonth);

        if (isdigit(selectedMonth[0])) {
            int monthIndex = atoi(selectedMonth);
            if (monthIndex >= 1 && monthIndex < 13) {
                strcpy(selectedMonth, months[monthIndex - 1].name);
                validMonth = 1;
            }
        } else {
            for (int i = 0; i < 12; i++) {
                if (strcasecmp(selectedMonth, months[i].name) == 0) {
                    validMonth = 1;
                    break;
                }
            }
        }

        if (!validMonth) {
            printf("Nama bulan tidak valid. Silakan coba lagi.\n");
        }

    } while (!validMonth);

    int vowels = countVowels(selectedMonth);
    int nonVowels = strlen(selectedMonth) - vowels;

    printf("Jumlah vokal: %d\n", vowels);
    printf("Jumlah non-vokal: %d\n", nonVowels);

    return 0;
}
