void merge(char *str, int l, int m, int r){
    char *L=NULL, *R=NULL;
    int  i=0, j=0, k=0, len, L_len=0, R_len=0;
    
    //printf("merge():%d-%d-%d\n", l, m , r);
    L_len = (m-l+1);
    L = malloc(sizeof(char)*L_len );
    R_len = (r-m);
    R = malloc(sizeof(char)*R_len );
    strncpy(L, str+l, (m-l+1));
    strncpy(R, str+m+1, (r-m) );
    len = r+1;
    for ( i=l; i< len; i++){
        //printf("%d/%d:%d/%d\n",  j, L_len, k, R_len);
        if ( (j < L_len) && (k < R_len) ) {
            //printf("%c,%c->\n", L[j] , R[k]);            
            if ( L[j] < R[k] ){
                //printf("2:j=%d\n", j);
                str[i] = L[j];
                j++;
            } else {
                //printf("2:k=%d\n", k);
                str[i] = R[k];
                k++;
            }
        } else if ( j < L_len ) {
            //printf("1:j=%d\n", j);
            str[i] = L[j];
            j++;
        } else {
            //printf("1:k=%d\n", k);
            str[i] = R[k];
            k++;
        }
        //printf("    %c\n", str[i]);
    }    
#if 0    
    printf("merged:\n");
    for ( i=l; i< (r+1); i++ )  
        printf("%c\n", str[i]);
    printf("\n");
#endif
}

void mergeSort(char *str, int l, int r){
    int  m=0;
    
    if (l == r)
        return;

    m = l+(r-l)/2;
    //printf("mergeSort(L): %d-%d\n", l, m);
    mergeSort(str, l, m);
    //printf("mergeSort(R): %d-%d\n", m+1, r);
    mergeSort(str, m+1, r);
    //printf("mergeSort(): merge(%d-%d-%d)\n", l, m, r);
    merge(str, l, m, r);
    //printf("==== mergeSort() ed ===\n");
}

bool isAnagram(char * s, char * t){
    char *s_ptr=NULL, *t_ptr=NULL;
    
    if ( (!s) && (!t) )
        return true;
    else if ( !s )
        return false;
    else if ( !t )
        return false;
    if ( strlen(s) != strlen(t) )
        return false;
    if ( (strlen(s)== 0) && (strlen(t)==0) )
        return true;
    mergeSort(s, 0, strlen(s)-1);
    printf("=%s=\n\n", s);
    mergeSort(t, 0, strlen(t)-1);
    printf("=%s=\n", t);
    s_ptr = s;
    t_ptr = t;
    while ( *s_ptr ) {
        if ( *s_ptr != *t_ptr )
            return false;
        s_ptr++;
        t_ptr++;
    }
    return true;
}
