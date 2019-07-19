#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
  l_ptr  ptr  r_ptr
         |
         |

  M      T      M
         O      O
  X      X

  Return

  sym_len the max. length of the symmetry

  0 odd symmetry
  1 even symmetry for the right
  -1 even symmetry for the left

*/


int bestSymmetry(char *s, char *c_ptr, int *sym_level){
    int level = 0, ret=0;
    char *l_ptr=NULL, *r_ptr=NULL;

    l_ptr = c_ptr-1;
    r_ptr = c_ptr+1;

    while ( 1 ) {// test odd symmetric
        if ( *l_ptr == *r_ptr ) {
            level++; 
            if ( (l_ptr == s) || (*r_ptr == 0) ) // end
		break;
            else {
                l_ptr--;
                r_ptr++;
            }
        } else
            break;
    } 
    *sym_level = level;
    printf("tested odd sym level(%d)\n", *sym_level);
    level = 0;
    // test even symmetric
    l_ptr = c_ptr;// test right
    r_ptr = c_ptr+1;
    while ( 1 ) {
        if ( *l_ptr == *r_ptr ) {
            level++; 
            if ( (l_ptr == s) || (*r_ptr == 0) ) // end
		break;
            else {
                l_ptr--;
                r_ptr++;
            }
        } else
            break;
    }
    if ( level > *sym_level ) {
        *sym_level = level;
        ret = 1;
    }
    printf("tested even-right sym: level(%d) > system_level(%d)?\n", level, *sym_level); // test even symmetric
    level = 0;
    l_ptr = c_ptr-1;// test left
    r_ptr = c_ptr;
    while (1 ) {
        if ( *l_ptr == *r_ptr ) {
            level++; 
            if ( (l_ptr == s) || (*r_ptr == 0) ) // end
		break;
            else {
                l_ptr--;
                r_ptr++;
            }
        } else
            break;
    }
    if ( level > *sym_level ) {
        *sym_level = level;
        ret = -1;
    }
    printf("tested even-left sym: level(%d) > system_level(%d)\n", level, *sym_level); // test even symmetric
    return ret;
}

char *find_maxSymmetry(char *s,  int *symmetry_len) {
    char *ptr=NULL, *l_ptr=NULL, *best_ptr=NULL;
    int sym_type=0, sym_level=0, best_level=0, best_len=0, len=0;

    *symmetry_len = 0;
    // skip the 1st char and NULL
    if ( s ) {
        if ( strlen(s) == 1 ) {
            *symmetry_len = 1;
            return s;
        } else {
            ptr = s + 1;
            while ( *ptr != 0 ) {
                sym_type = bestSymmetry(s, ptr, &sym_level);
                printf("best_level(%d)-best_len(%d): sym_type(%d), sym_level(%d): %s\n", best_level, best_len, sym_type, sym_level, ptr);               
                if ( sym_type == 0 ) { // odd
                        len = 1 + (2 * sym_level);
                        l_ptr = ptr - sym_level;
                } else if ( sym_type == 1 ) { // even symmetry for the right
                        len = (2 * sym_level);
                        l_ptr = ptr - sym_level +1;
                } else { // even symmetry for the left
                        len = (2 * sym_level);
                        l_ptr = ptr - sym_level;
                }
                if ( len > best_len ) {
                    best_level = sym_level;
                    best_len = len;
                    best_ptr = l_ptr;
                }
                ptr++;
            }
        }            
    } else {
        return NULL; 
    }
    printf("%c has max. len-%d symmetry:\n", *best_ptr, best_len);
    int i=0;
    for (i=0; i< best_len; i++)
        printf("%c ", best_ptr[i]);
    printf("\n");
    *symmetry_len = best_len;
    return best_ptr;
}

char * longestPalindrome(char * s){
    int answer_len=1;
    char *answer_ptr=NULL, *ptr=NULL;
    
    if ( strlen(s) > 0 ) {
        answer_ptr = find_maxSymmetry(s, &answer_len);
        ptr = (char *) malloc(sizeof(char) * (answer_len+1) );
        strncpy(ptr, answer_ptr, answer_len);
        ptr[answer_len] = 0;
    } else {
        ptr = (char *) malloc(sizeof(char)); 
        *ptr = 0;
    }
    return ptr;
}


int main(){
	char *answer=NULL;
	answer = longestPalindrome("jhgtrclvzumufurdemsogfkpzcwgyepdwucnxrsubrxadnenhvjyglxnhowncsubvdtftccomjufwhjupcuuvelblcdnuchuppqpcujernplvmombpdttfjowcujvxknzbwmdedjydxvwykbbamfnsyzcozlixdgoliddoejurusnrcdbqkfdxsoxxzlhgyiprujvvwgqlzredkwahexewlnvqcwfyahjpeiucnhsdhnxtgizgpqphunlgikogmsffexaeftzhblpdxrxgsmeascmqngmwbotycbjmwrngemxpfakrwcdndanouyhnnrygvntrhcuxgvpgjafijlrewfhqrguwhdepwlxvrakyqgstoyruyzohlvvdhvqmzdsnbtlwctetwyrhhktkhhobsojiyuydknvtxmjewvssegrtmshxuvzcbrabntjqulxkjazrsgbpqnrsxqflvbvzywzetrmoydodrrhnhdzlajzvnkrcylkfmsdode");
	if ( answer ) {
		printf("%s\n", answer);
                free(answer);
	} else
		printf("NULL input\n");
}
