/* Beispiel 10005 */

#include <stdio.h>
main(){
int x, y;
printf("\n\t1 . R e c h e n p r o g r a m m\n");
printf("\nBitte x eingeben : ");
scanf("%i", &x);
printf("Bitte y eingeben : ");
scanf("%i", &y);
printf("\n %i + %i ist %i", x,y,x+y);
printf("\n %i - %i ist %i", x,y,x-y);
printf("\n %i * %i ist %i", x,y,x*y);
printf("\n %i / %i ist %i", x,y,x/y);
printf("\n %i %% %i ist %i", x,y,x%y);
}