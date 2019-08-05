#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    int count;
    int type; // 0 default, 1sum([0,0,0]), 2 2sum, 3 3sum
    struct node *next;
};
  
int find_num(struct node *root, int num){
    struct node *tmp=NULL;
    
    tmp = root;
    while ( tmp != NULL ){
        if ( tmp->num == num ) {
            printf("return %d: %d\n", num, tmp->count);
            return tmp->count;
        } 
        tmp = tmp->next;
    }  
    printf("%d: not found\n", num);
    return 0;  
}
    
void add_num(struct node *root, int num){
    struct node *tmp=NULL, *last=NULL;
    
    tmp = root;
    last = root;
    while ( tmp != NULL ){
        if ( tmp->num == num ) {
            tmp->count++;
            printf("node(%d) ++\n", num);
            return;
        } 
        last = tmp;
        tmp = tmp->next;
    }
    // append a new num node
    last->next =  (struct node *) malloc(sizeof(struct node));
    tmp = last->next;
    tmp->num = num;
    tmp->count = 1;
    tmp->next = NULL;
    printf("node(%d) added\n", num);
}

void release_num(struct node *root){
    struct node *tmp=NULL, *next=NULL;
    
    tmp = root;
    while ( tmp != NULL ){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }   
}

void add_result(int **results, int *numSet, int *returnSize, int **returnColumnSizes){
    int *result=0;

    (*returnSize)++;
    *(*returnColumnSizes) += (int) sizeof(int) * 3;
    result = (int *) malloc(sizeof(int) * 3);

}
  
int num_type(struct node *root, struct node *test_node){
    struct node *tmp = NULL;
    
    tmp = root;
    while ( tmp != NULL ){
        if ( tmp->num == test_node->num )
            return tmp->type;
        tmp = tmp->next;
    }  
    return 0; 
}

void set_num_type(struct node *root, struct node *test_node, int type){
    struct node *tmp = NULL;
    int match_num=0;
    
    match_num = 0 - test_node->num;
    
    tmp = root;
    if ( type == 2 ) {
        while ( tmp != NULL ){
            if ( (tmp->num == test_node->num) || (tmp->num == match_num) ) {
                tmp->type = type;
            }
            tmp = tmp->next;
        }
    }  else {
         while ( tmp != NULL ){
            if ( tmp->num == test_node->num) {
                tmp->type = type;
                return;
            }
            tmp = tmp->next;
        }   
    }
}
        
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i=0, **result=NULL, *set=NULL;
    int *numSet=NULL;
    struct node *root=NULL, *tmp_node=NULL;

    if ( numsSize < 3 ) {
        *returnSize = 0;
        return result;
    }
    // build the linked list to count the nums
    root = (struct node *) malloc(sizeof(struct node));
    root->num = 0;
    root->count = 0;
    root->next = NULL;
    for ( i=0; i< numsSize; i++) {
        add_num(root, nums[i]);
    }
    result = (int **) malloc( sizeof(int *) *(numsSize/3));   
    numSet  = (int *) malloc( sizeof(int *) *(numsSize/3));
    printf("numSet=%p\n", numSet);
    returnColumnSizes = &numSet;
    // 3 zeros
    if ( find_num(root, 0) == 3 ) {
        set = (int *) malloc(sizeof(int) * 3);
        set[0] = set[1] = set[2] = 0;
        result [*returnSize] = (int *) set;
        numSet[*returnSize] += (int) sizeof(int) * 3;       
        (*returnSize)++;
    } 
    if ( find_num(root, 0) == 1 ) { // 1 zeros, find 2Sum
        tmp_node = root;
        while ( tmp_node != NULL ){
            if ( tmp_node->num ) { // ignore 0
                if ( find_num(root, 0-tmp_node->num) > 0 ) {
                    if ( num_type(root, tmp_node) != 2 ) {
                        set = (int *) malloc(sizeof(int) * 3);
                        set[0] = 0;
                        set[1] = tmp_node->num;
                        set[2] = 0-tmp_node->num;
                        result [*returnSize] = (int *) set;
                        set_num_type(root, tmp_node, 2);
                        numSet[*returnSize] += (int) sizeof(int) * 3;       
                        (*returnSize)++;
                    } else
                        printf("%d is duplicated\n", tmp_node->num);
                }
            }
            tmp_node = tmp_node->next;
        }
    }
    release_num(root);
    printf("returnSize(%d)\n", *returnSize);
    return result;
}

#define NUMS    6
int main(){
    int nums[NUMS]={-1, 0, 1, 2, -1, -4};
    int **answer=NULL, returnSize=0;
    int **returnColumnSizes=NULL;
    int **sets=NULL, *set=NULL;;
    
    answer = threeSum(nums, NUMS, &returnSize, returnColumnSizes);
    int i=0;
    sets = answer;

    for ( i=0; i<returnSize; i++) {
        printf("%d-set:\n", i);
        set = *sets;
        printf("%d:%d:%d", set[0], set[1], set[2]);
        printf("\n");
        free(set);
        sets++;
    }
    free(returnColumnSizes);
    free(answer);
}
