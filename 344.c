void reverseString(char* s, int sSize){
    char tmp;
    int i=0;
    int swap_times;
    int endIndex=0;
    
    if ( (sSize % 2) == 1 )
        swap_times =  sSize/2;
    else
        swap_times =  sSize/2 - 1;
    endIndex = sSize - 1;
    for ( i=0; i<= swap_times ; i++) {
        tmp = s[i];
        s[i] = s[endIndex-i];
        s[endIndex-i] = tmp;
    }
    
}
