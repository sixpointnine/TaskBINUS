#include <stdio.h>

int main() {
    int inputedDistance; // in kilometre
    int distanceInMetre;
    int distanceInCentiMetre;
    
    printf("*Program Pengkonversi Jarak*\n");

    printf("Masukan jarak dalam KM dan tekan enter: ");
    scanf("%d", &inputedDistance);

    distanceInMetre = inputedDistance*1000; // 1 km = 1000m
    distanceInCentiMetre = inputedDistance*100000; // 1km = 100000m

    printf("\n%d km = %d m = %d cm\n", inputedDistance, distanceInMetre, distanceInCentiMetre);
    return 0;
}

