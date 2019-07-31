/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * intToRoman(int num){
    char *ptre=NULL, *rome=NULL;
    int q=0, divider=1000;
    
    rome = (char *) malloc(17);
    rome[0] = 0;
    while (divider > 0) {
        printf("num(%d), q(%d), divider(%d)\n", num, q, divider);
        q = num / divider;
        if ( divider == 1000 ) { // M
            num -= divider * q;
            while ( q > 0 ) {
                strncat(rome, "M", 1);
                q--;
            }
        } else if ( divider == 100 ) { // D +- C
            num -= divider * q;
             if ( q == 9 ) {
                strncat(rome, "CM", 2);
             } else if ( q > 5 ) {
                strncat(rome, "D", 1);
                q -= 5;
                while ( q > 0 ) {
                    strncat(rome, "C", 1);
                    q--;
                }
             } else if ( q == 5 ) {
                strncat(rome, "D", 1);
             } else if ( q == 4 ) {
                strncat(rome, "CD", 2);
             } else {                
                while ( q > 0 ) {
                    strncat(rome, "C", 1);
                    q--;
                }
             }
        } else if ( divider == 10 ) { // L +- X
            num -= divider * q;
             if ( q == 9 ) {
                strncat(rome, "XC", 2);
             } else if ( q > 5 ) {
                strncat(rome, "L", 1);
                q -= 5;
                while ( q > 0 ) {
                    strncat(rome, "X", 1);
                    q--;
                }
             } else if ( q == 5 ) {
                strncat(rome, "L", 1);
             } else if ( q == 4 ) {
                strncat(rome, "XL", 2);
             } else {                
                while ( q > 0 ) {
                    strncat(rome, "X", 1);
                    q--;
                }
             }
        } else if ( divider == 1 ) { // V +- I
            num =0;
             if ( q == 9 ) {
                strncat(rome, "IX", 2);
             } else if ( q > 5 ) {
                strncat(rome, "V", 1);
                q -= 5;
                while ( q > 0 ) {
                    strncat(rome, "I", 1);
                    q--;
                }
             } else if ( q == 5 ) {
                strncat(rome, "V", 1);
             } else if ( q == 4 ) {
                strncat(rome, "IV", 2);
             } else {                
                while ( q > 0 ) {
                    strncat(rome, "I",1);
                    q--;
                }
             }
        }    
        
        divider = divider/10;
    }
    rome[16] = 0;
    return rome;
}


int main(){
  int num = 188;
  char *ptr=NULL;
  
  ptr = intToRoman(num);
  printf("%d --> %s\n", num, ptr);
  free(ptr);
}
