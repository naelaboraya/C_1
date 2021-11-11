#include <stdio.h>
#define false 0
#define true 1

int isPalindrome(int x) {
    if (x < 0)
        return false;
    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }
    while (x != 0) {
        int l = x / div;
        int r = x % 10;
        if (l != r)
            return false;
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}

int size(int n){//A helping function , returns how many digits there is in the given number
    int sum = 0;
    while(n>0){
        n=n/10;
        sum++;
    }
    return sum;
}

 //A helping function to calculate the power of two given numbers 
 int pow(int base, int exponent)
{
int result=1;
for (exponent; exponent>0; exponent--)
{
result = result * base;
}
return result;
}

int isArmstrong(int n){ 

    int number_of_digits = size(n); 
    int tmp = n; 
    int result = 0; 
    int remainder; 

    for(int i = 0; i<number_of_digits; i++){ 
        remainder = tmp%10; 
        result += power(remainder,number_of_digits);
        tmp = tmp/10;
    }

    if(result == n){
        return true;
    }
    return false;
}
