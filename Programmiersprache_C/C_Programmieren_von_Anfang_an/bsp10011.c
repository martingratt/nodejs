#include <stdio.h>

main(){
    int x,y,z;
    printf("\nZahlenvergleich\n");
    printf("Bitte x eingeben: ");
    scanf("%i", &x);
    printf("Bitte y eingeben: ");
    scanf("%i", &y);
    printf("Bitte z eingeben: ");
    scanf("%i", &z);
    printf("\nDie groessere Zahl lautet %i",
    (x>y) ? ((z>x) ? z : x) : ((z>y)? z : y)    );
}