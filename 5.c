
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




char *find_maxSymmetry(char *s, char *ptr, int *symmetry_len) {
    char * turning_ptr=NULL, *l_ptr=NULL, *r_ptr=NULL;
    int len = 1;

    l_ptr = ptr;
    if ( (*(ptr+1) != 0) &&  (*(ptr+2) != 0) ) { // test odd symmetric
	printf("test odd sym\n");
        if ( *(ptr) == *(ptr+2) ) {
            turning_ptr = ptr +1;
            r_ptr = ptr+2;
            len = 3;
        }
    } 
    if ( turning_ptr == NULL ){ // test even symmetric
	printf("test even sym\n");
        if ( *(ptr) == *(ptr+1) ) {
            r_ptr = ptr+1;
            len = 2;
        }
    }

    // watch out for the starting and ending
    while ( len > 1 ) { // symmetry is found
        printf("%c-%c\n", *l_ptr, *r_ptr);
        if ( (l_ptr == s) || ( *r_ptr == 0) ) { // touch the start or ending
            printf("The end\n");
            break;
        } else {
            l_ptr--;
            r_ptr++;
            if ( *(l_ptr) == *(r_ptr)  ) { // continuous symmetry
                len += 2;
            } else { // end of symmetry
                printf("sym is broken\n");
                // rollback
                l_ptr++;
                r_ptr--;
                break;
            }
        }
    }

    *symmetry_len = len;
    printf("%c has max. len-%d symmetry:\n", *ptr, len);
    int i=0;
    for (i=0; i< len; i++)
        printf("%c ", l_ptr[i]);
    printf("\n");
    return l_ptr;
}

char * longestPalindrome(char * s){
    int len=0, tested_len=0, answer_len=1, tmp_answer_len=1;
    char *answer_ptr=NULL, *ptr=NULL, *tmp_answer_ptr=NULL;
    
    len = strlen(s);
    answer_ptr = s;
    ptr = s;
    while ( *ptr != 0 ) {
        tested_len = len - (ptr - s); // tested_len included the target
	printf("%d: find for remained len(%d)\n", answer_len, tested_len);
	if ( *(ptr + 1) == 0 ) // ignore the last char
		break;
// main - begins
        tmp_answer_ptr = find_maxSymmetry(s, ptr, &tmp_answer_len);
        if ( tmp_answer_len > answer_len ) {
            answer_len = tmp_answer_len;
            answer_ptr = tmp_answer_ptr;
        }
// main - ends
	printf("Current max. len(%d): %s\n", answer_len, answer_ptr);    
        ptr++; // shift 1 for next test
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
	answer = longestPalindrome("aaaa");
	if ( answer )
		printf("%s\n", answer);
	else
		printf("NULL input\n");
}
