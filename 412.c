
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** fizzBuzz(int n, int* returnSize){
    char **array=NULL, *str;
    int i=0, num=0;
    int digits = 1, rem=0;
    array = malloc(sizeof(char *) * n);
    *returnSize = n;
    for ( i=0; i<n ; i++ ) {
        num = i+1;
        if ( (num % 15) == 0) {
            str = malloc(strlen("FizzBuzz")+1);
            strcpy(str, "FizzBuzz"); 
        } else if ( (num %3) == 0 ){
            str = malloc(strlen("Fizz")+1);
            strcpy(str, "Fizz");
        } else if ( (num % 5) == 0 ) {
            str = malloc(strlen("Buzz")+1);
            strcpy(str, "Buzz");  
        } else  {
            rem = num;
            while ( (rem /= 10) > 0 )
                digits++;
            str = malloc(digits+1);
            printf("num(%d)\n", num);
            sprintf(str,"%d", num);
            //str[0] = num + '0';
            str[digits] = 0;            
        }
        array[i] = str;
    }
    return array;
}
