#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	palindrome:
	
	a word or group of words that is the same when you read it forwards from the beginning or backwards from the end:
	
	"aba", "ccc", "abcdcba"
	
	Both looking from the left to right and right to the left are the same.
*/


char * longestPalindrome(char * s){
    int len=0, answer_len=1, tmp_answer_len=0, tested_len=0;
    char *ptr=NULL, target=0, *tmp_ptr=NULL, *answer_ptr=NULL;
    
    len = strlen(s);
    answer_ptr = s;
    ptr = s;
    while ( *ptr != 0 ) {
        target = *ptr;
	// TODO: check if the target has ben checked before, ignore if it is done

        tested_len = len - (ptr - s); // tested_len included the target
	printf("%d: search %c for len(%d)\n", answer_len, target,tested_len);
        tmp_answer_len=1; // reset count for each position
        tmp_ptr = ptr + 1;
	if ( *(tmp_ptr + 1) == 0 ) // ignore the last char
		break;
        while ( *tmp_ptr != 0 ) { // for each position
	    printf("%c is %c?\n", *tmp_ptr, target);
	    tmp_answer_len++;
            if ( *tmp_ptr == target ) {
	        if ( tmp_answer_len > answer_len ) {
            	    answer_len = tmp_answer_len;
            	    answer_ptr = ptr;
	    	    printf("Change answer=%c with len(%d)\n", *answer_ptr, answer_len);
		}
		// reset counting for this target
		tmp_answer_len = 1;
            }
            tmp_ptr++;
        }// while	
	if ( *tmp_ptr == 0 ) // no matched
	       tmp_answer_len = 0;
	printf("%c with max. len(%d)\n", *ptr, tmp_answer_len);    
        ptr++;
	if ( *ptr == 0 )
		break;
    }// while
    ptr = (char *) malloc(sizeof(char) * (answer_len+1) );
    strncpy(ptr, answer_ptr, answer_len);
    ptr[answer_len] = 0;
    return ptr;
}

int main(){
	char *answer=NULL;
	answer = longestPalindrome("babad");
	if ( answer )
		printf("%s\n", answer);
	else
		printf("NULL input\n");
}
