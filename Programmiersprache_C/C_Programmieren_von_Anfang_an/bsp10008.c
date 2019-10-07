/*Beispiel 10008.c*/

#include <stdio.h>

main(){
    float summe = 0.0;
    float zahl;
    printf("\n1. Zahl : ");
    scanf("%f", &zahl);
    summe = summe + zahl;
    printf("2. Zahl : ");
    scanf("%f", &zahl);
    summe = summe + zahl;
    printf("3. Zahl : ");
    scanf("%f", &zahl);
    summe = summe + zahl;
    printf("\nEndergebnis = %.17f", summe);
}