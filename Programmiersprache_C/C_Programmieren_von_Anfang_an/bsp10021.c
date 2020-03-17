#include <stdio.h>

main(){
    int x, anzahl;
    double zahl, summe =0.0, mittelw;

    printf("\n\t Statistik\n");
    printf("\nWieviel Werte wollen Sie eingeben: ");
    scanf("%i", &anzahl);
    printf("\n");
    for (x=1; x <= anzahl; x++)
    {
        printf("\nGeben Sie den %i . Wert ein: ", x);
        scanf("%lf", &zahl);
        summe = summe + zahl;
    }
    mittelw = summe / anzahl;
    printf("\n\nSumme der Zahlen = %f", summe);
    printf("\nMittelwert der Zahlen = %f", mittelw);
        
    
    
}