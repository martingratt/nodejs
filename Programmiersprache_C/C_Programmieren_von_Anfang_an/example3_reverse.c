#include <stdio.h>
#include <wincrypt.h>

main(){

    int pcchString = 16; 
    char pszString []  = "YXNkZg==";
    int dwFlags = 1;
    int cbBinary = 4;
    char pbBinary[] = "asdf";



    CryptBinaryToStringA(pcchString, pszString, dwFlags, cbBinary, pbBinary);

    //CryptStringToBinaryA()
}