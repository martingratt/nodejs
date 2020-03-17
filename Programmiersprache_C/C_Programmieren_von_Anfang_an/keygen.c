#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*Functions*/
uint32_t gen_char(uint32_t in_val, uint32_t count, char* pass_str, size_t str_len);
uint32_t multiply(uint32_t a, uint32_t b);
uint32_t hi(uint32_t x);
uint32_t lo(uint32_t x);
  
int main (int argc, char *argv[]) {

	char user[10];
	char pass[12];
	uint32_t temp=0;
        uint32_t userlen=0;
	/*check if an username has been passed*/
	if(argc<2){	
		/*if no then ask the user to enter one*/
		printf("Please enter an username with max 10 symbols: \n");
		scanf("%s", user);
	}
	else
		/*otherwise copy the passed arguement to the local variable */
		strncpy(user, argv[1], sizeof(user));
		user[sizeof(user)-1]='\0';
 
	/*check the user length*/
	userlen = strlen(user);
	
	/*generate the password*/
	for(uint32_t i=0; i<10; i++){
		switch(i){
			/*initialise the password*/
			/*create the first input for the algorithm*/
			case 0: temp = user[0]+user[1];
			break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9: if(i<userlen){
					/*create the next input in this way if the
					  counter is smaller then the user length*/
					temp = user[i]*4+pass[i-1];
					printf("\nuseri = %x", user[i]);
					printf("\nuser*4 = %x", user[i]*4);
					printf("\npass[i-1] = %x", pass[i-1]);
					}
					
				else
					/*otherwise use this method to create the 
					  input for the next characters until 10*/								
					temp = ((i+65)<<(10-i))+pass[i-1];
					printf("I: %i", i);
					printf("\nElse tmp: %i", temp);
			break;
		}
		/*call the function which will generates the password characters*/
		gen_char(temp, i, pass, sizeof(pass));
	} 
	printf("\n\nHere is your password: %s \n", pass);
}
/*Function to generate the password characters
 *Parameters: 
 *          @uint32_t in_val          initialisation vector
 *          @uint32_t count           position of the character
 *          @char* pass_str           string to save the generated character
 *	    @size_t str_len           the length of the string
 *Returns:
 *          -1                        if the counter bigger then string length
 *          0                         if succesfully stored the generated character
*/
uint32_t gen_char(uint32_t in_val, uint32_t count, char* pass_str, size_t str_len){
	
	/*check if the counter bigger than the length of string is*/
	if(count>str_len)
	return -1;
        
        /*Hardcoded keys*/
	uint32_t key1=738919105;
	uint32_t key2=93;
	uint32_t key3=33;

	uint32_t tmp_sft=0;
	uint32_t tmp_mult=0;
	uint32_t sub=0;
		
		printf("\nTMPMULT0: %x", in_val);
	
       
        /*do multiplication of number or result larger than 32bits*/
		tmp_mult=multiply(in_val, key1);
		printf("\nTMPMULT1: %x", tmp_mult);
        /*shift the result of multiplication 4 bits to right*/
		tmp_sft=tmp_mult>>4;
		printf("\nTMPMULT2: %x", tmp_sft);

        /*multiply the result of the shifting with key 2*/
        tmp_mult=tmp_sft*key2;
		printf("\nTMPMULT3: %x", tmp_mult);
		
        /*subtract the result of the multiplication from the initialisation vector*/
	sub=in_val-tmp_mult;
        /*add to result of the subtraction to key 3 and save the result into the string*/
        pass_str[count]=sub+key3;

	return 0;
}
/*Function to multiply two numbers larger then 32bits 
 *Parameters:
 *            @uint32_t a      first number to be multiply
 *            @uint32_t b      second number
 *Returns:
 *            the value of the carry
*/
uint32_t multiply(uint32_t a, uint32_t b) {
    
    uint32_t s0, s1, s2, s3; 

    uint32_t x = lo(a) * lo(b);
    s0 = lo(x);

    x = hi(a) * lo(b) + hi(x);
    s1 = lo(x);
    s2 = hi(x);

    x = s1 + lo(a) * hi(b);
    s1 = lo(x);

    x = s2 + hi(a) * hi(b) + hi(x);
    s2 = lo(x);
    s3 = hi(x);

    uint32_t result = s1 << 16 | s0;
    uint32_t carry = s3 << 16 | s2;
    return carry;
}
/*Split the number into half and return the higher 16bits*/
uint32_t hi(uint32_t x) {
    return x >> 16;
}
/*Return the second half, also the lower 16bits*/
uint32_t lo(uint32_t x) {
    return ((1L << 16) - 1) & x;
}
