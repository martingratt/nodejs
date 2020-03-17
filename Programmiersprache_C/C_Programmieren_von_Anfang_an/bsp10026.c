#include <stdio.h>

main(){
    int eingabe;
    while (1)
    {
       printf("\nBitte eine Zahl bis max. 100: ");
       scanf("%i", &eingabe);
       if (eingabe<=100)
           break;
       
    }
    printf("Ihre Zahl war %i", eingabe);
    
}