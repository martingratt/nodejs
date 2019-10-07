#include <stdio.h>

main(){
    int x,y;
    printf("\nZahlenvergleich\n");
    printf("\nBitte x eingeben: ");
    scanf("%i", &x);
    printf("\nBitte y eingeben: ");
    scanf("%i", &y);
    printf("\nDie groessere Zahl lautet %i", (x>y) ? x : y);
}