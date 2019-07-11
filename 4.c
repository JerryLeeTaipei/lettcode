/*
The Median is the "middle" of a sorted list of numbers.
To find the Median, place the numbers in value order and find the middle.
BUT, with an even amount of numbers , we find the middle pair of numbers, and then find the value that is half way between them.

3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23, 29, 40, 56

the middle numbers are 21 and 23, the Median is 22.
*/

merge( int *dest, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2) {
    
}

/*
    These 2 sorted arrays are non-overlapped
    Eacg array is divided into 2 sub-blocks.
    Compare and merge from the smaller(left) block, then, do the same for the bigger(right) block
    Return the accumulated length of the merged blocks
*/

/*
    The left block is smaller than the right one
*/
merge(int *array, int offset, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2) {
    int i=0, len=0;
    len = end_1 - start_1 + 1;
    for ( i=0; i< len; i++)
        array[offset +i] = src1[start_1 + i];
    len = end_2 - start_2 + 1;
    for ( i=0; i< len; i++)
        array[offset +i] = src2[start_2 + i];
}
    
int double mergeSort( int *array, int offset, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2){
    int mid1=0, mid2=0, len=0;
    
    len = (end_1 - start_1 + 1) + (end_2 - start_2 + 1);
    // if non-overlapped
    if ( src1[end_1] < src2[0] ) {
        merge(array, offset, src1, start_1, end_1, src2, start_2, end_2);
        return (offset + len);
    } else if ( src2[end_2] < src1[0] ) {
        merge(array, offset,  src2, 0, end_2, src1, 0, end_1);   
        return (offset + len);        
    }
    // decompose until no overlapped or 1 element remained
    mid1 = (end_1 - start_1)/2;
    mid2 = (end_2 - start_2)/2;
    // compare the left block
    len = mergeSort(array, offset, src1, start_1, mid1, src2, start_2, mid2);
    // compare the right block    
    offset = len;
    len = mergeSort(array, offset, src1, mid1+1, end_1, src2, mid2+1, end_2);
    return len;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double median_value=0;  
    array = malloc ( (nums1Size + nums2Size) * sizeof(int) );
    mergeSort(array, 0, nums1, 0, nums1Size-1, nums2, 0, nums2Size-1);
    median_value = find_median(array);
    return median_value;
}
