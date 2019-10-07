/*Beispiel 10007.c*/

#include <stdio.h>

float u_faktor, betrag;

main(){
    printf("\n\tW a e h r u n g s r e c h n e n\n");
    printf("\nBitte Umrechnungsfaktor eingeben: ");
    scanf("%f", &u_faktor);
    printf("\nBitte DM-Betrag eingeben: ");
    scanf("%f", &betrag);
    printf("\n%.2f DM entsprechen ", betrag);
    printf("%.2f in der Fremdwahrung.", betrag*u_faktor);
}