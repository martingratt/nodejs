/*Aufgabe 7*/

#include <stdio.h>

double benzin, kilometer, verbrauchkm;
main(){

printf("\nVerbrauchten Benzin in Liter eingeben: ");
scanf("%lf", &benzin);
printf("\nGefahrene Kilometer eingeben : ");
scanf("%lf", &kilometer);
printf("\nDer Verbrauch pro Kilometer betraegt ");
verbrauchkm = benzin * 100 / kilometer;
printf("%.2lf Liter pro 100 km.", verbrauchkm);
}

