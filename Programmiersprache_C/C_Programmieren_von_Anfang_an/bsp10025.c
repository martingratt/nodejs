#include <stdio.h>

main(){
    int eingabe;
    do {
        printf("\nBitte eine Zahl bis max. 100 :");
        scanf("%i", &eingabe);

    } while (eingabe > 100);
    
        printf("\nIhre Zahl %i", eingabe);
    
    
}