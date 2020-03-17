#include <stdio.h>

main (){
    int eingabe;
    int i, summe;
    summe = 0;
    printf("\nBitte einen Wert eingeben: ");

    scanf("%i", &eingabe);


    for (i=1; i<=eingabe; i++){
        int gerade = i % 2;
        if (gerade == 0){
            summe = summe + i;
        } else
        {
            printf("ungerade");
        }
        
    }
    printf("Ausgabe: %i", summe);

}