int nonRepeatedLen(char *start){
    char *tmp=NULL;
    char ascii[255];
    
    while (tmp) {
        
        tmp++;
    }
}

int lengthOfLongestSubstring(char * s){
    int longest=0, len=0;
    char *tmp=NULL;
    
    tmp = s;
    while ( tmp) {
        len = nonRepeatedLen(tmp);
        if ( len > longest )
            longest = len;
        tmp++;
    }
    return longest;
}

