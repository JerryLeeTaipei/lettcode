/*
The Median is the "middle" of a sorted list of numbers.
To find the Median, place the numbers in value order and find the middle.
BUT, with an even amount of numbers , we find the middle pair of numbers, and then find the value that is half way between them.
3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23, 29, 40, 56
the middle numbers are 21 and 23, the Median is 22.
*/

/*
	Insert one element into an array
*/
void insert(int *array, int *offset, int target, int *src, int start, int end) {
    int i=0, len=0;
    len = end - start + 1;    
    for ( i=0; i< len; i++) {
        if ( target <= src[start+i] ) {
		array[*offset +i] = target;
		break;
	} else
       		array[*offset +i] = src[start + i];
    }
    while ( i < len ) {
	array[*offset +i+1] = src[start + i];
	i++;
    }     
    *offset = *offset + len;
	printf("insert():offset(%d)\n", *offset);
}

/*
    The left block is smaller than the right one
    Update: offset 
*/
void merge(int *array, int *offset, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2) {
    int i=0, len=0;
    len = end_1 - start_1 + 1;    
    for ( i=0; i< len; i++)
        array[*offset +i] = src1[start_1 + i];
    *offset = *offset + len;
    len = end_2 - start_2 + 1;
    for ( i=0; i< len; i++)
        array[*offset +i] = src2[start_2 + i];        
    *offset = *offset + len;
	printf("merge():offset(%d)\n", *offset);
}
 

/*
    These 2 sorted arrays are non-overlapped
    Each array is divided into 2 sub-blocks.
    Compare and merge from the smaller(left) block, then, do the same for the bigger(right) block
    Return the accumulated length of the merged blocks
*/

void  mergeSort( int *array, int *offset, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2){
    int mid1=0, mid2=0, len=0;
        printf("src1(%d:%d), src2(%d:%d)\n", start_1, end_1, start_2, end_2);
    // if non-overlapped
    if ( src1[end_1] <= src2[start_2] ) {
        merge(array, offset, src1, start_1, end_1, src2, start_2, end_2);
        return;
    } else if ( src2[end_2] <= src1[start_1] ) {
        merge(array, offset, src2, start_2, end_2, src1, start_1, end_1);   
        return;
    } 
   
    // decide which block to be merged when single element is seen
    if ( start_1 == end_1 ) { // insert the left in the right
	printf("insertL->src1(%d), src2(%d:%d)\n", start_1, start_2, end_2);    
	insert(array, offset, src1[start_1], src2, start_2, end_2);
    } else if ( start_2 == end_2 ) { // insert the right in the left
	printf("insertR->src2(%d), src1(%d:%d)\n", start_2, start_1, end_1);
	insert(array, offset, src2[start_2], src1, start_1, end_1); 
    } else { 
	mid1 = end_1;
	mid2 = end_2;    
    	/* decompose for at least 2 elements
	Divide rule: find the mid1 and mid2 so that
	
	(src1[mid]  < src2[mid2+1]) && (src2[mid2]  < src1[mid1+1])
	
    	*/
    	if ( (end_1 - start_1) > 0 ) {
       	 	mid1 = (end_1 - start_1)/2;
    	} 
    	if ( (end_2 - start_2) > 0 ) {
        	mid2 = (end_2 - start_2)/2;  
    	}	    
    	// merge the left block  
	printf("mergeL->src1(%d:%d), src2(%d:%d)\n", start_1, mid1, start_2, mid2);      
    	mergeSort(array, offset, src1, start_1, mid1, src2, start_2, mid2);
    	// merge the right block   
	printf("mergeR->src1(%d:%d), src2(%d:%d)\n", mid1+1, end_1, mid2+1, end_2);
    	mergeSort(array, offset, src1, mid1+1, end_1, src2, mid2+1, end_2);
    	// combine ?

    }
    

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
	int i=0, len=0;
    if ( (nums1Size != 0) && (nums2Size !=0) ) {
        for (i=0; i<nums1Size; i++)
            printf("%d ", nums1[i]);
        printf("\n");
        for (i=0; i<nums2Size; i++)
            printf("%d ", nums2[i]);
        printf("\n");    
        array = malloc ( (nums1Size + nums2Size) * sizeof(int) + 1); // add one 0 at the end
        end_1 = nums1Size - 1;
        end_2 = nums2Size - 1;
        printf("findMedianSortedArrays:(%d:%d), (%d:%d)\n", start_1, end_1, start_2, end_2);
        mergeSort(array, &offset, nums1, start_1, end_1, nums2, start_2, end_2); 
        median_value = find_median(array, nums1Size + nums2Size); 
	    len = nums1Size + nums2Size ;
	    for ( i=0; i< len; i++)
		    printf("%d ", array[i]);
	    printf("\n");
        free(array);
    } else {
        if (nums1Size == 0)
            median_value = find_median(nums2, nums2Size); 
        else if (nums2Size == 0)
            median_value = find_median(nums1, nums1Size); 
        else
            median_value = 0;
    }
    

    return median_value;
}


int main(int argc, char **argv){
	double median=0;

	int num1[] = {1,3};
	int num2[] = {2,4,5};
	median = findMedianSortedArrays(num1, 2, num2, 1);
	printf("%f\n", median);
}
/*
1 3 
    2 4 5 
findMedianSortedArrays:(0:1), (0:2)
src1(0:1), src2(0:2)
mergeL->src1(0:0), src2(0:1) -> 1 vs 2,4
src1(0:0), src2(0:1)
merge():offset(3) --> 1, 2, 4
mergeR->src1(1:1), src2(2:2) -> 3 vs 5
src1(1:1), src2(2:2)
merge():offset(5)
1 2 4 3 5

*/
