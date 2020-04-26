void printMerge(int *num, int s, int e){
    int i=0;
    
    for ( i=s; i<e; i++)
        printf("%d ", num[i]);
    printf("\n");
}

// merge 2 sorted arrays
void merge(int *num, int s, int m, int e){
    int *L=NULL, *R=NULL, l=0, r=0, i=0, j=0, k=0;
    
    l = m-s+1;
    r = e-m;
    L = malloc(sizeof(int)*l);
    R = malloc(sizeof(int)*r);
    //printf("merge-1(%d,%d)\n", l, r);
    
    for (i=0; i< l; i++){
        L[i] = num[s+i];
        //printf("%d ", L[i]);
    }
    for (i=0; i< r; i++) {
        R[i] = num[s+l+i];
        //printf("%d ", R[i]);
    }
  
    //printf("\nmerge-2(%d-%d-%d)\n", s, m, e);
    
    for ( i=0; i<(e-s+1); i++){
        //printf("%d/%d, %d/%d\n", j, l, k, r);
        if ( ( k == r ) || ( (j != l) && (L[j] < R[k]) ) ){
                num[s+i] = L[j];
                j++;
        } else {
            num[s+i] = R[k];
            k++;
        }
    }
    //printMerge(num, s, e);
    if ( L )
        free(L);
    if ( R )
        free(R);
}

void mergeSort(int *array, int s, int e){
    int m=0, len=0;
    
    if ( s < e ) {
        len = (e-s+1);
        m = len/2;
        if ( m == (len+1)/2 ) // len is even
            m -= 1;
        m += s; 
        //printf("mergeSortL(%d-%d)\n", s, m);
        mergeSort(array, s, m);
        //printf("mergeSortR(%d-%d)\n", m+1, e);
        mergeSort(array, m+1, e);
        //printf("mergeLR(%d-%d-%d)\n", s, m, e);
        merge(array, s, m, e);
    }
}
int findKthLargest(int* nums, int numsSize, int k){

    mergeSort(nums, 0, numsSize-1);
    return nums[numsSize-k];
}

