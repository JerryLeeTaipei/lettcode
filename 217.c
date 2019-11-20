bool duplicated(int* nums, int index){
    int num=0;
    
    num = nums[index];
    index--;
    while (index>=0){
        if ( nums[index] == num )
            return true;
        index--;
    }
    return false;
}

bool containsDuplicate(int* nums, int numsSize){
    int i=0;
    
    for (i=1; i<numsSize; i++) {
           if ( duplicated(nums, i) )
               return true;
    }
#if 0    
    for ( i=0; i<numsSize; i++) {
        for ( j=0; j< numsSize; j++) {
            if ( nums[i] == nums[j] ) {
                if ( i != j)
                    return true;
            }
        }
        
    }
#endif    
    return false;
}
