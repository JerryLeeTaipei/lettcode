int find_target_index(int* nums, int numsSize, int target, int start){
    int *ptr=NULL;
    int m_index=0;
    
    m_index = numsSize/2;
    printf("start=%d, m_index=%d\n", start, m_index);
    ptr = nums+start;
    if (  m_index == 0 ){// 1 elements
        if ( target <= *ptr)
            return start;
        else
            return (start+1);        
    }
    if (target == ptr[m_index])
        return (start+m_index);
    else if (target < ptr[m_index]) // left
        return find_target_index(nums, m_index, target, start);
    else // right
        return find_target_index(nums, (numsSize-m_index), target, start+m_index ); 
    
}

int searchInsert(int* nums, int numsSize, int target){

    return find_target_index(nums, numsSize, target, 0);
}
