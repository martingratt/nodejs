/*Beispiel 10008.c*/

#include <stdio.h>

main(){
    double summe = 0.0;
    double zahl;
    printf("\n1. Zahl : ");
    scanf("%lf", &zahl);
    summe = summe + zahl;
    printf("2. Zahl : ");
    scanf("%lf", &zahl);
    summe = summe + zahl;
    printf("3. Zahl : ");
    scanf("%lf", &zahl);
    summe = summe + zahl;
    printf("\nEndergebnis = %.17f", summe);
}