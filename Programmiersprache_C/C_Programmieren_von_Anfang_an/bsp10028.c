#include <stdio.h>

main(){
    int x,y;
    double preis, rest;
    printf("\nRestwerttabelle \n");
    printf("\nBitte Neupreis in Euro eingeben: ");
    scanf("%lf", &preis);
    printf("\n\t AFA - Zeitraum");
    printf("\nJahr \t8 Jahre \t6 Jahre \t4 Jahre");
    for(x=1; x<=8; x++){
        printf("\n%i\t", x);
        for (y=8; y>=4; y=y-2){
            rest = preis - x*preis/y;
            if (rest < 0)
            break;
            printf("%8.1f", rest);
        }
    }
}