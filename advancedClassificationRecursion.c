#include<stdio.h>
#define false 0
#define true 1


int size(int n){//A helping function , returns how many digits there is in the given number
    int sum = 0;
    while(n>0){
        n=n/10;
        sum++;
    }
    return sum;
    }
int power(int base, int exponent)
{
int result=1;
for (exponent; exponent>0; exponent--)
{
result = result * base;
}
return result;
}
 // Recursive function to find reverse of any number
 
int reverseNumber(int num) {
	int rev = 0, r;
        if (num == 0) {
            return rev;
        }

        if (num > 0) {
            r = num % 10;
            rev = rev * 10 + r;
            num = reverseNumber(num / 10);
        }

        return rev;
    }


int isPalindrome(int num)
{
    /* 
     * Check if the given number is equal to 
     * its reverse.
     */
    if(num == reverseNumber(num))
    {
        return true;
    }
    
    return false;
}



//-------------------------------------

int isarmstrongg(int num, int temporary,int digits){//A helping function (recursion)
    int A = digits;
    if(num==0){
        return temporary;
    }
    int remainder = num%10;
    temporary = power(remainder,digits) + temporary;
    return isarmstrongg(num/10,temporary,A);
  }  
    int isArmstrong(int num) { 

    if(num == isarmstrongg(num,0,size(num))){
        return true;
    }
   return false;
}



//-------------------------------------

