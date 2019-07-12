

/*
The Median is the "middle" of a sorted list of numbers.
To find the Median, place the numbers in value order and find the middle.
BUT, with an even amount of numbers , we find the middle pair of numbers, and then find the value that is half way between them.
3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23, 29, 40, 56
the middle numbers are 21 and 23, the Median is 22.
*/



/*
    The left block is smaller than the right one
    Update: offset 
*/
merge(int *array, int *offset, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2) {
    int i=0, len=0;
    len = end_1 - start_1 + 1;    
    for ( i=0; i< len; i++)
        array[offset +i] = src1[start_1 + i];
    *offset = *offset + len;
    len = end_2 - start_2 + 1;
    for ( i=0; i< len; i++)
        array[offset +i] = src2[start_2 + i];        
    *offset = *offset + len;
}
 

/*
    These 2 sorted arrays are non-overlapped
    Eacg array is divided into 2 sub-blocks.
    Compare and merge from the smaller(left) block, then, do the same for the bigger(right) block
    Return the accumulated length of the merged blocks
*/

void  mergeSort( int *array, int *offset, int *src1, int *start_1, int *end_1, int *src2, int *start_2, int *end_2){
    int mid1=0, mid2=0, len=0;
        
    // if non-overlapped
    if ( src1[*end_1] < src2[*start_2] ) {
        merge(array, *offset, src1, *start_1, *end_1, src2, *start_2, *end_2);
        return;
    } else if ( src2[end_2] < src1[0] ) {
        merge(array, *offset, src2, *start_2, *end_2, src1, *start_1, *end_1);   
        return;
    }
   
    // decompose for at least 2 elements
    if ( (*end_1 - *start_1) > 0 )
        *end_1 = (*end_1 - *start_1)/2;
    if ( (*end_2 - *start_q) > 0 )
        *end_2 = (*end_2 - *start_2)/2;
    
    // merge the left block
    mergeSort(array, offset, src1, start_1, end_1, src2, start_2, end_2);
    // merge the right block    
    mergeSort(array, offset, src1, mid1+1, end_1, src2, mid2+1, end_2);
}

double  find_median(int *array, int len){
    double mid=0;
    
    if ( (len%2) == 1)
        mid = (double) array[(len/2)];
    else
        mid = ( (double) array[(len-1)/2]  +  (double) array[((len-1)/2)+1] ) / 2;
    return mid;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *array=NULL, offset=0, start_1=0, end_1=0, start_2=0, end_2=0;
    double median_value=0;  
    array = malloc ( (nums1Size + nums2Size) * sizeof(int) + 1); // add one 0 at the end
    end_1 = nums1Size - 1;
    end_2 = nums2Size - 1;
    mergeSort(array, &offset, nums1, &start_1, &end_1, nums2, &start_2, &end_2);    
    median_value = find_median(array, offset-1); // remove the 0 tail
    free(array);
    return median_value;
}
