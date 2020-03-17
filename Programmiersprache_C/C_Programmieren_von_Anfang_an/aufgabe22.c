#include <stdio.h>

main(){
    
    int eingabe;

    printf("\nBitte geben Sie eine ganez Zahl kleiner als Null ein: ");
    scanf("%i", &eingabe);

    do {
        printf("\nBitte Geben Sie eine gültige Zahl ein: ");
        scanf("%i", &eingabe);
     } while (eingabe >= 0);

    printf("Die Zahl ist gültig!");
    
}