#include <stdio.h>

// Definisi union
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    // Deklarasi variabel union
    union Data data;

    // Menyimpan nilai ke dalam variabel union
    data.i = 10;
    printf("Data.i: %d\n", data.i);

    data.f = 220.5;
    printf("Data.f: %f\n", data.f);

    strcpy(data.str, "C Programming");
    printf("Data.str: %s\n", data.str);

    return 0;
}
