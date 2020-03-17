#include <stdio.h>

main(){
    int eingabe = 0;
    int fakultaet = 1;
    int i = 1;
    printf("\nBitte geben Sie eine Zahl ein");
    scanf("%i", &eingabe);
    for (i; i<=eingabe; i++){
        fakultaet = fakultaet * i;
        printf ("\nSchritt %i: ,Fakultaet: %i", i, fakultaet);
    }

}