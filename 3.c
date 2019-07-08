
static char *ascii=NULL;


int nonRepeatedLen(char *start){
    char *tmp=NULL;
    int len=0;
     
    tmp = start;
    while ( *tmp != 0 ) {
        if ( ascii[*tmp] == 0 ) {
            ascii[*tmp] = 1;
            len++;
        } else
            break; 
        tmp++;
    }
    return len;
}

int lengthOfLongestSubstring(char * s){
    int longest=0, len=0;
    char *tmp=NULL;
    ascii = malloc(sizeof(char) *255);
    tmp = s;
    while ( *tmp) {
        bzero(ascii, 255);
        len = nonRepeatedLen(tmp);
        if ( len > longest )
            longest = len;
        tmp++;
    }
    free(ascii);
    return longest;
}

