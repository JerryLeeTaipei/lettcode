/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
        int n, a, b, a_i, b_i, *result;
        result = malloc(sizeof(int)*2);
        *returnSize =0;
        for ( a_i=0;  a_i<numsSize; a_i++ ){
                a = nums[a_i];
                for (b_i=0; b_i<numsSize; b_i++) {
                        b = nums[b_i];
                        if ( (a_i!=b_i) && (a + b) == target ) {
                                *result = a_i;
                                *(result+1) = b_i;
                                *returnSize = 2;
                                return result;
                        }//if
                }//for
                n--;
        }// while
        return result;
}


