#include <stdio.h>

main(){
    int jahr;
    for (jahr=1950; jahr <= 2000; jahr++){
        printf("\n%i", jahr);
        if ((jahr%4))
        continue;
        printf(" = Schaltjahr");
    }
}