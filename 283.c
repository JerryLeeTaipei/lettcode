

void moveZeroes(int* nums, int numsSize){

    int i=0;
    int count=0;
    for ( i=0; i< numsSize; i++ ) {
        if ( nums[i] == 0 ){
            count++;
        } else {
            if ( count > 0 ){
                nums[i-count] = nums[i] ;
                nums[i] = 0;
            }
        }
    }
    
}
