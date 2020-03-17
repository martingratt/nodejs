#include <stdio.h>

int vorzeichen(double);

main(){

    printf("\n Vorzeichen: %i", vorzeichen(-12.12));

}

int vorzeichen(double a){
    if (a > 0){
        return 1;
    }
    else if (a < 0)
    {
        return -1;
    } else
    {
        return 0;
    }
    
    
   
}