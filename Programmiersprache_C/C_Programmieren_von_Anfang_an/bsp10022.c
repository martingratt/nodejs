#include <stdio.h>

main(){
    int x, y;
    for (x=1; x<=10; x++){
        printf("\n");
        for (y=1; y<=10; y++){
            printf("%4i", x*y);
        }

    }
}