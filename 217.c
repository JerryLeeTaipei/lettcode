
void mergeInt(int *str, int l, int m, int r){
    int *L=NULL, *R=NULL;
    int  i=0, j=0, k=0, len, L_len=0, R_len=0;
    
    //printf("merge():%d-%d-%d\n", l, m , r);
    L_len = (m-l+1);
    L = malloc(sizeof(int)*L_len );
    R_len = (r-m);
    R = malloc(sizeof(int)*R_len );
    //strncpy(L, str+l, (m-l+1));
    for (j=0; j< (m-l+1); j++){
        //printf("str[%d]=%d\n", l+j, str[l+j]);
        L[j] = str[l+j];
    }
    //strncpy(R, str+m+1, (r-m) );
    for (k=0; k< r-m; k++)
        R[k] = str[m+1+k];
    len = r+1;
    j = k = 0;
    for ( i=l; i< len; i++){
        //printf("%d/%d:%d/%d\n",  j, L_len, k, R_len);
        if ( (j < L_len) && (k < R_len) ) {
            //printf("%d,%d->\n", L[j] , R[k]);            
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
        //printf("    %d\n", str[i]);
    }    
#if 0    
    printf("merged:\n");
    for ( i=l; i< (r+1); i++ )  
        printf("%d\n", str[i]);
    printf("\n");
#endif
}

void mergeSortInt(int *str, int l, int r){
    int  m=0;
    
    if (l == r)
        return;

    m = l+(r-l)/2;
    //printf("mergeSort(): %d-%d\n", l, m);
    mergeSortInt(str, l, m);
    //printf("mergeSort(): %d-%d\n", m+1, r);
    mergeSortInt(str, m+1, r);
    //printf("mergeSort(): merge(%d-%d-%d)\n", l, m, r);
    mergeInt(str, l, m, r);
    //printf("==== mergeSort() ed ===\n");
}

bool containsDuplicate(int* nums, int numsSize){
    int i=0;
    
    if ( numsSize == 0 )
        return false;
    
    mergeSortInt(nums, 0, numsSize-1);
    for (i=1; i<numsSize; i++) {
        if ( nums[i] == nums[i-1] )   
            return true;
    }
  
    return false;
}
