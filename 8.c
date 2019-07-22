/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.


*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BITS_LIMIT	(1<<31) 
#define MAX_INPUT_LEN    10

int convert(int sign, char *num_str){
    long upper_l= 1;
    long lower_l = 1;
    long num=0;
    int len=0;
    char *ptr=NULL;
    
    upper_l = (upper_l << 31) - 1;
    lower_l = (lower_l <<31);


    if ( strlen(num_str) > MAX_INPUT_LEN )
        if ( sign > 0 ){
            printf("Overflow: > %ld\n", upper_l);
            return upper_l;
        } else {
            printf("underflow: < %ld\n", lower_l);
            return (0 - lower_l);
        }
    ptr = num_str;
    while ( *ptr != 0) {
        num = num*10 + (*ptr - '0'); 
        ptr++;  
    }
    printf("%ld: check (%d) bounds: %ld, %ld\n", num, sign, lower_l, upper_l);    
    if ( (sign>0) && (num >= upper_l) ) {
        printf("Overflow: > %ld\n", upper_l);
        return upper_l;
    }
    if ( (sign<0) && (num > lower_l) ) {
        printf("underflow: < %ld\n", lower_l);
        return (0 - lower_l);
    }
       
    if ( sign < 0 )
        num = 0 - num;
    return num;
}


/* return the the valid number string */
char *extract_numStr(char *s, int *sign, int *num_len){
    char *ptr=NULL, *n_ptr=NULL;
    int len=-1, pol=1;

    if ( strlen(s) > 0 ) {
        ptr = s;
        while ( (*ptr!=0) ){
            if ( len < 0 ) {// process heading
                if ( *ptr != ' ' ) {
                    if ( *ptr == '+') {
                        if ( (ptr != s) && (*(ptr-1) != ' ') ) {
                            printf("+ must follow WS\n");
                            return NULL;
                        }                            
                        pol = 1;
                        // skip 0 until the next non-0 is found
                        ptr++;
                        while ( *ptr != 0 ) {
                            if ( *ptr != '0' )
                                break;
                            ptr++;
                        }
                        len = 0;
                    } else if ( *ptr == '-' ){
                        if ( (ptr != s) && (*(ptr-1) != ' ') ) {
                            printf("- must follow WS\n");
                            return NULL;
                        }                     
                        pol = -1;
                        // skip 0 until the next non-0 is found
                        ptr++;
                        while ( *ptr != 0 ) {
                            if ( *ptr != '0' )
                                break;
                            ptr++;
                        }
                        len = 0;
                    } else {
                        if ( ((*ptr - '0') >= 0) && ((*ptr - '9') <=0) ) {
                            if ( *ptr != '0' )// skip leading 0
                                len = 0;
                        } else {
                            printf("Non valid heading : %s\n", ptr);   
                            return NULL;
                        }
                    }                           
                } else {// rule for WS
                    if ( (ptr != s) && (*(ptr-1) != ' ') ) {
                        printf("none can be ahead of WS\n");
                        return NULL;
                    } 
                }
            }
            if ( len >= 0 ) {// process num char
                if ( ((*ptr - '0') >=0) && ((*ptr - '9') <=0) ) {
                    len++;
                } else
                    break;
            }
            ptr++;
        }// while
        
        if ( len > 0 ){
            *sign = pol;
            *num_len = len;
            n_ptr = ptr - len;    
            ptr = malloc(len+1);
            ptr[len] = 0;
            strncpy(ptr, n_ptr, len);
            printf("copy %d bytes from n_ptr: %s\n", len, n_ptr);
        }
    }  
    return ptr;        
}

int myAtoi(char * str){
    int len=0, num=0, sign=0;
    char *ptr=NULL;

    ptr = extract_numStr(str, &sign, &len);
    if ( ptr && (len > 0) ) {
        printf("%s --> %s\n", str, ptr);
        //num = atoi(ptr);
        num = convert(sign, ptr);
        free(ptr);
    }
    return num;
}


#define INPUT_STR	"0  123"

int main(){
 int out=0;

 out = myAtoi(INPUT_STR);
 printf("%s --> %d\n", INPUT_STR, out);
}
