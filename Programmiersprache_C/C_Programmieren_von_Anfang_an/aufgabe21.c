#include <stdio.h>

main (){
    int eingabe;
    int i = 1, summe;
    summe = 0;
    printf("\nBitte einen Wert eingeben: ");

    scanf("%i", &eingabe);

    

    while (i <= eingabe)
    {
        int gerade = i % 2;
        if (gerade == 0){
            summe = summe + i;
        } else
        {
            printf("ungerade");
        }
        i++;
        continue;
    }
    
    printf("Ausgabe: %i", summe);

}