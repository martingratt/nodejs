#include <stdio.h>

main(){
    int jahr,monat,tage;
    printf("\nKalender");
    printf("\nBitte Jahr eingeben:");
    scanf("%i",&jahr);
    printf("\nBitte Monat eingeben:");
    scanf("%i",&monat);
    if (monat>=1&&monat<=12 && jahr > 1582){
        switch (monat) {
        case 2:
        if (!((jahr%100)%4) && (jahr%100)
        || !(jahr%400))
        tage = 29;
        else
        
            tage = 28;/* code */
        
        
            break;
        case 2*2:
        case 6:
        case 9: case 11:
        tage = 30;
            break;

        
        default:
            tage = 31;
        
        }
        printf("\n%i hat der Montag %i %i Tage", jahr,monat,tage);
    
    }
    else
    
        printf("\nFalsche Datumsangaben!");  
    

}