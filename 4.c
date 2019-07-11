/*
The Median is the "middle" of a sorted list of numbers.
To find the Median, place the numbers in value order and find the middle.
BUT, with an even amount of numbers , we find the middle pair of numbers, and then find the value that is half way between them.

3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23, 29, 40, 56

the middle numbers are 21 and 23, the Median is 22.
*/

merge( int *dest, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2) {
    
}
    

double mergeSubBlocks( int *dest, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2){
    int mid=0;
    int *blk1_l=NULL, *blk1_r=NULL, *blk2_l=NULL, *blk2_r=NULL;
    // if non-overlapped
    if ( src1[end_1] < src2[0] ) {
        merge(array, src1, 0, end_1, src2, 0, end_2);
    } else if ( src2[end_2] < src1[0] ) {
        merge(array, src2, 0, end_2, src1, 0, end_1);
    } else { // decompose until no overlapped or 1 element remained
        
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double median_value=0;  
    array = malloc ( (nums1Size + nums2Size) * sizeof(int) );
    mergeSubBlocks(array, nums1, 0, nums1Size-1, nums2, 0, nums2Size-1);
    median_value = find_median(array);
    return median_value;
}
