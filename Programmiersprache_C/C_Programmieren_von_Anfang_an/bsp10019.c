#include <stdio.h>
#include <ctype.h>

main(){
    char eingabe;
    int zahl;
    printf("\nWaehlen Sie (O)ktal. (H)ex oder (A)SCII > ");
    eingabe=getchar();
    printf("\nBitte Dezimalzahl eingeben: ");
    scanf("%i", &zahl);
    switch (toupper(eingabe))
    {
    case 'O':
        printf("Dezimal %i = Oktal %o \n", zahl, zahl);
        break;
    case 'H':
        printf("Dezimal %i = Hexadezimal %x \n", zahl, zahl);
    case 'A':
        if(zahl <= 255)
            printf("ASCII-Code %i entspricht %c \n", zahl, zahl);
        else
            printf("Diese Zahl ist zu gross ! \n\a");
            break;
    default:
        break;
    }
}