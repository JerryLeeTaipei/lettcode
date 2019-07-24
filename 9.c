/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIGITS    0xFFFFFFFF

int max_digits(){
    int digits=0;
    long num = 0xFFFFFFFF - 1;
    

    digits = 1;
    while ( num > 0 ) {
        num = num/10;
        digits++;
        
    }
    return digits;
}

bool isPalindrome(int x){
    bool ret=false;
    int tmp = 0, i=0, j=0, noDigits=0, decimalDigits=0;
    char *digits=NULL;
 
    if ( x < 0 )
        return false;
    decimalDigits =  max_digits();
    printf("max. digits=%d\n", decimalDigits);   
    digits = malloc( sizeof (char) * decimalDigits );
    if ( digits ) {
        tmp = x;
        i = 0;
        while ( tmp > 9 ) {
            digits[i] = tmp % 10;
            i++;
            tmp = tmp/10;
            printf("tmp=%d\n", tmp);
            if ( tmp < 10 ) {
                digits[i] = tmp;
                i++;
                break;
            }
        }
        noDigits = i;
        printf("%d has %d digits\n", x, noDigits);
        if ( noDigits < 2 ) {
            ret = true;
            goto free_m;
        }
        i = 0;
        j = noDigits - 1;
        ret = true;      
        while ( i != j ) {
            printf("%d : %d\n",  digits[i] , digits[j]);
            if ( digits[i] != digits[j] ) {
                ret = false;
                break;
            }
            i++;
            j--;
            if ( j == 0 )
                break;
        }

    }    
free_m:
    if (digits)
        free(digits);
    return ret;
}


int main(){
    int num=-121;
    
    printf("%d(0x %x)\n", num, num);
    if ( isPalindrome(num) )
        printf("%d is Palindrome\n", num);
    else
        printf("%d is Not Palindrome\n", num);
}
