#include <stdio.h>

main(){

    double flaeche, gesamt = 0;
    int anzahl = 0;
    printf("\n\t\tBerechnung der Wohnflache\n");
    printf("\nBeender der Eingabe mit '0'.\n\n");
    printf("Zimmergroesse in qm > ");
    scanf("%lf", &flaeche);
    while (flaeche > 0.0)
    {
        
        gesamt = gesamt + flaeche;
        anzahl = anzahl + 1;
        printf("Zimmergroesse in qm > ");
        scanf("%lf", &flaeche);

    }
    printf("\nAnzahl der Zimmer = %i", anzahl);
    printf("\nGesamtflaeche = %.2lf qm", gesamt);
    printf("\nDurchschnittliche flaeche = ");
    printf("%.2lf", gesamt/anzahl);
    


}