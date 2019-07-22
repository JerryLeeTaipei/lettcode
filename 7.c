/*

Given a 32-bit signed integer, reverse digits of an integer.
Integers are within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21

*/

#define BITS_LIMIT	(1<<31) 

int check_bounds(long num){
    int ret=0;
    long upper_l= 1;
    upper_l = (upper_l << 31) - 1;
    long lower_l = 1;
    lower_l = 0 - (lower_l <<31);

    //printf("check bounds: %ld, %ld\n", lower_l, upper_l);
    if ( (num>0) && (num >= upper_l) ) {
        //printf("Overflow: > %ld\n", upper_l);
        return 0;
    }
    if ( (num<0) && (num <= lower_l) ) {
        //printf("underflow: < %ld\n", lower_l);
        return 0;
    }
    return 1;
}

int reverse(int x){
    long y=0, z=0;
    
    if ( check_bounds(x) == 0 )
        return 0;
    if ( x < 0 ) {
        y = 0 - (long)x;
    } else
        y = x;
    while ( (y/10) > 0 ){
        //printf("%ld <- %ld\n", z, y);
        z = z * 10 + (y % 10);
        //printf("%ld \n", z);
        y = y/10;
    }
    z = z * 10 + y;
    if ( x < 0 )
        y = 0 - z;
    else
        y = z;
    //printf("ans=%ld\n", y);
    if ( check_bounds(y) == 0 )
        return 0;
    return y;
}

