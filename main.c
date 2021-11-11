#include <stdio.h>
#include "NumClass.h"



int main() {

    int x;
    int y;
    scanf("%d %d", &x ,&y);//get two nums

	// to see wich is the max and min 
    int min;
    int max;
    if(x<y)
    {
         min=x;
         max=y;
    }
    else{
        min=y;
        max=x;
    }
    
    printf("The Armstrong numbers are:");// armstrong


   for (int i=min; i<=max; i++) {
        if (isArmstrong(i)) {

            printf(" %d", i);
        }
    }
            printf("\n");


    printf("The Palindromes are:");//the palindrome

    for (int i=min; i<=max; i++) {
        if (isPalindrome(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");
    
    printf("The Prime numbers are:");//prime

    for (int i=min; i<=max; i++) {
        if (isPrime(i)) {

            printf(" %d", i);
        }
    }
    printf("\n");
    printf("The Strong numbers are:");//strong

   for (int i=min; i<=max; i++) {

        if (isStrong(i)) {
            printf(" %d", i);
        }
    }
     printf("\n");

   
   return 0;
}
