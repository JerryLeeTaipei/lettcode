#include <stdio.h>
#include <stdlib.h>

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
    The 1st block is smaller than the 2nd one
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
    	The 1st element of the 1st array is smaller than the 2nd array's.

	Divide rule: find the mid1 and mid2 so that
	
	(src1[mid]  < src2[mid2+1]) && (src2[mid2]  < src1[mid1+1])
	
	1. find the max. index of the 1st array (using power of 2 increment) which can't be bigger than the 1st element in the 2nd array
	3. use this index as the middle to divide the operated array
	4. merge this left with the 1st element in the 2nd array
	5. use the 2nd array as the operated array, repeat 2~5
    	    
    Return the accumulated length of the merged blocks
*/

void  mergeSort( int *array, int *offset, int *src1, int start_1, int end_1, int *src2, int start_2, int end_2){
    int inc_power=0, mid1=0, len=0;
    printf("src1(%d:%d)=%d, src2(%d:%d)=%d\n", start_1, end_1, src1[start_1], start_2, end_2, src2[start_2]);
    // if non-overlapped
    if ( src1[end_1] <= src2[start_2] ) {
        merge(array, offset, src1, start_1, end_1, src2, start_2, end_2);
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
	len = end_1 - start_1;
	while ( src1[start_1+(1<<inc_power)] <= src2[start_2] ){
	    inc_power++; // next power to be checked
printf("%d > %d ?\n", (1<<inc_power), len);
	    if ( (1<<inc_power) > len ) {
		break;
	    }
	}
printf("inc_power=%d\n", inc_power);
	if ( inc_power == 0)
	    mid1 = start_1;
	else if ( (1<<inc_power) > len ) {
		inc_power--;
		if ( src1[start_1+(1<<inc_power)+1] <= src2[start_2] )
			mid1 = start_1+(1<<inc_power)+1;
		else
			mid1 = start_1+(1<<inc_power);
	}
	else {
	    mid1 = start_1 +(1<<inc_power) -1; 
	}
printf("mid1=%d\n", mid1);	    
    	// merge the 1st block  
	printf("mergeL->src1(%d:%d), src2(%d)\n", start_1, mid1, start_2);      
    	mergeSort(array, offset, src1, start_1, mid1, src2, start_2, start_2);
    	// decide the smaller repeat for the remained block   
	if ( src1[mid1+1] <= src2[start_2+1] ) {
		printf("mergeR->src1(%d:%d), src2(%d:%d)\n", mid1+1, end_1, start_2+1, end_2);
    		mergeSort(array, offset, src1, mid1+1, end_1, src2, start_2+1, end_2);
	} else { // swap
		printf("mergeR->src2(%d:%d), src1(%d:%d)\n", start_2+1, end_2, mid1+1, end_1);
    		mergeSort(array, offset, src2, start_2+1, end_2, src1, mid1+1, end_1);
	}
    	// combine ?

    }
    return;
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
        array = malloc ( (nums1Size + nums2Size + 1) * sizeof(int) ); // add one 0 at the end
        end_1 = nums1Size - 1;
        end_2 = nums2Size - 1;
	if ( nums1[start_1] <= nums2[start_2] ) {
            printf("findMedianSortedArrays:(%d:%d), (%d:%d)\n", start_1, end_1, start_2, end_2);
            mergeSort(array, &offset, nums1, start_1, end_1, nums2, start_2, end_2); 
	} else {
            printf("findMedianSortedArrays:(%d:%d), (%d:%d)\n", start_2, end_2, start_1, end_1);
            mergeSort(array, &offset, nums2, start_2, end_2, nums1, start_1, end_1); 
	}
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

	int num1[] = {4,6};
	int num2[] = {1,2,3,5,7,8};
	median = findMedianSortedArrays(num1, 2, num2, 6);
	printf("%f\n", median);
}
