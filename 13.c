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
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"


Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int romanToInt(char * s){
    int num=0, i=0, tmp=0;
    char *ptr=NULL;

    ptr = s;
    while ( *ptr != 0) {
        tmp = 0;
        // 1~ 4
        if ( *ptr == 'I' ) {//         I:    
             if ( *(ptr+1) == 'X' ) {
                tmp = 9;
                ptr += 2;
            } else if ( *(ptr+1) == 'V' ) {
                tmp = 4;
                ptr += 2;
            } else {
                tmp = 1;
                ptr++;
                while ( *ptr == 'I' ) {
                    tmp += 1; 
                    ptr++;
                }
            }        
        } else if ( *ptr == 'V' ) {//  I:V:III
            // count V
            tmp = 5;
            ptr++;
            while ( *ptr == 'I' ) {
                tmp += 1; 
                ptr++;
            }        
        } else if ( *ptr == 'X' ) {//  I:XXX:
            if ( *(ptr+1) == 'C' ) {
                tmp = 90;
                ptr += 2;
            } else if ( *(ptr+1) == 'L' ) {
                tmp = 40;
                ptr += 2;
            } else {
                tmp = 10;
                ptr++;
                while ( *ptr == 'X' ) {
                    tmp += 10; 
                    ptr++;
                }
            }       
        } else if ( *ptr == 'L' ) {//  X:L:XXX
            // count L
            tmp = 50;
            ptr++;
            while ( *ptr == 'X' ) {
                tmp += 10; 
                ptr++;
            }        
        } else if ( *ptr == 'C' ) {//  X:CCC:
            if ( *(ptr+1) == 'M' ) {
                tmp = 900;
                ptr += 2;
            } else if ( *(ptr+1) == 'D' ) {
                tmp = 400;
                ptr += 2;
            } else {
                tmp = 100;
                ptr++;
                while ( *ptr == 'C' ) {
                    tmp += 100; 
                    ptr++;
                }
            }
        } else if ( *ptr == 'D' ) {//  C:D:CCC
            // count D
            tmp = 500;
            ptr++;
            while ( *ptr == 'C' ) {
                tmp += 100; 
                ptr++;
            }       
        } else if ( *ptr == 'M' ) {//  C:MMM:
            tmp = 1000;
            ptr++;
            while ( *ptr == 'M' ) {
                tmp += 1000; 
                ptr++;
            }
        } else {
            printf("incorrect %c\n", *ptr);
            return 0;
        }
        num += tmp;
    }// while

    return num;
}

#define ROME "IX"

int main(){
  int num = 0;

  
  num = romanToInt(ROME);
  printf("%s --> %d\n", ROME, num);

}
