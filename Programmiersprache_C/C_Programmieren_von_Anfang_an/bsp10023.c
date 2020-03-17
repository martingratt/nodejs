#include <stdio.h>

main(){

    int zahl;
    printf("\nBitte Zahl eingeben ('0' fuer Ende) :");
    scanf("%i", &zahl);
    while (zahl != 0)

        {
            printf("%3i hoch 2 = %4i\n", zahl, zahl*zahl);
            printf("\nBitte Zahl eingebben ('0' fuer Ende) :");
            scanf("%i", &zahl);
        }

}