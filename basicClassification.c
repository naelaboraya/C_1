#include <stdio.h>
#include "NumClass.h"
#define false 0
#define true 1

//A function to check if a number is a prime number or not -> 1=true , 0=false
int isPrime(int n) {

    if (n<= 1) {
        return false;
    } else {
        for (int i = 2; i <= n / 2; i = i + 1) {
            if (n % i == 0) {
                return false;
            }
        }
    }
    return true;

}

//A helping function (recursive) to get factorial of a given number : 

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int isStrong(int n) {

    int temp = n;
    int sum = 0; // to check the sum of factorial of digits if its equals to the original number
    while (temp > 0) { // while the number greater than 0 , every time we add to the sum the factorial of the number's last digit
        int last = temp%10; // last digit of the number 
        sum = sum + factorial(last); 
        temp = temp / 10; 
    }
   
    if (n == sum) {
        return true;
    }
    return false;
    
   }
