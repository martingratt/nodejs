#include <stdio.h>

main(){
    int x = 5, y = 11, z =3;
    int ergebnis, result;
    ergebnis = x < y;
    result = x || z < y;
    if (ergebnis)
        printf("\nx ist kleiner als y");
    
    else
        
        printf("\nx ist groesser oder gleich y");

    printf("\n%i", result);
    
        
    
}