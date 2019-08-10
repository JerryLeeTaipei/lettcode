#include <stdio.h>
#include <stdlib.h>

struct node{
    int index;
    int val;
    struct node *left, *right;// left is <= val
};

static int node_count=0;
static int root_count=0;
  

struct node *find_node_lt(struct node *current, int num){
    struct node *tmp=NULL;

    tmp = current->left;
    while ( tmp ) {
        if ( tmp->val <= num )
            return tmp;
        tmp = current->left;
    } 
    return NULL;
}
   
struct node *find_node_gt(struct node *current, int num){
    struct node *tmp=NULL;

    tmp = current;
    while ( tmp ) {
        if ( tmp->val >= num ) {
            return tmp;
        }
        tmp = tmp->right;
    } 
    return NULL;
}
    
struct node *find_node(struct node *current, int num){
    
    if ( current ) {
        if ( current->val == num)
            return current;
        if ( current->left ) {
            find_node(current->left, num);
        }
        if ( current->right ) {
            find_node(current->right, num);
        }
    } 
    return NULL;
}  
  
void add_node(struct node *root, int num){
    struct node *tmp=NULL, *last=NULL;
    
    if ( num == 0 ){
        root_count++;
        //printf("root(0) increased(%d)\n", root_count);
        return;
    }
    tmp = root;
    while ( tmp != NULL ){
        last = tmp;
        if ( num > tmp->val ) 
            tmp = tmp->right;
        else
            tmp = tmp->left;        
    }  
    tmp = (struct node *) malloc(sizeof(struct node));
    node_count++;
    tmp->index = node_count;
    tmp->val = num;
    tmp->left = NULL;
    tmp->right = NULL; 
    if ( num > last->val ) {
        last->right = tmp;
        //printf("node(%d, %d) added under node(%d,%d)'s right\n", tmp->index, tmp->val, last->index, last->val);
    } else {
        last->left = tmp;    
        //printf("node(%d, %d) added under node(%d,%d)'s left\n", tmp->index, tmp->val, last->index, last->val);
    }

}


void add_result( int *set, int **result, int *numSet, int *returnSize, int **returnColumnSizes ){

    result [*returnSize] = set;
    numSet[*returnSize] += (int) sizeof(int) * 3;       
    (*returnSize)++;
}
  

void release_bst(struct node *current){
    
    if ( current ) {
        if ( current->left ) {
            release_bst(current->left);
        }
        if ( current->right ) {
            release_bst(current->right);
        }
        //printf("node (%d,%d) is free\n", current->index, current->val);
        free(current);
    } 
}

int find_1Sum(struct node *root, struct node *current, int *num3){        
    int ret=0, target_val=0;
    struct node *tmp_r=NULL;
    
    target_val = 0 - (2 *current->val);
 
    if ( target_val > 0 ) {
        //printf("%d: serach %d from the right...\n", current->val, target_val);
        tmp_r = find_node_gt(root, target_val);   
        if ( tmp_r ) {
            if ( tmp_r->val == target_val ) {
                *num3 = tmp_r->val;
                return 1;
            }      
        } 
    } 
    //printf("Set not found for %d\n", current->val);
    return ret;
}
 
int find_2Sum(struct node *root, struct node *current, int *num2, int *num3){        
    int ret=0, target_val=0;
    struct node *tmp_l=NULL, *tmp_r=NULL;
    
    target_val = 0 - current->val;
 
    if ( target_val > 0 ) {
        //printf("%d: searching %d from the right...\n", current->val, target_val);
        tmp_r = find_node_gt(root, 1);   
        while ( tmp_r ) {
            //printf("%d: searching %d from the right...\n", tmp_r->val, target_val);
            if ( tmp_r->val > target_val ) { 
                //printf("no_2\n");    
                return ret; // no match
            } else { // num2 qualified
                target_val = tmp_r->val - target_val;
                if ( target_val == 0 ) {
                    if ( root_count > 0 ) {
                        *num2 = tmp_r->val;
                        *num3 = 0;
                        //printf("match (%d,%d) for %d\n", *num2, *num3, current->val);
                        return 1;
                    }
                    //printf("no_3\n"); 
                    return ret; // no need for num3
                } else {
                    *num2 = tmp_r->val;
                    tmp_l = find_node(root, target_val);
                    if ( tmp_l ) {
                        *num3 = tmp_l->val;
                        //printf("match (%d,%d) for %d\n", *num2, *num3, current->val);
                        return 1;
                    } else 
                        break;
                }
            }
            // try deeper
            tmp_r = tmp_r->right;       
        } //while
    } else if  ( target_val < 0 ) {
    
    } else {
    
    }
    printf("Set not found for %d\n", current->val);
    return ret;
}
 
int** find_3Sum(int numsSize, struct node *root, int *returnSize, int **returnColumnSizes){
    int **result=NULL;
    int *set=NULL;
    int *sizeList=NULL;
    int num2=0, num3=0, match_size=0, last_num=0, duplicated=0;
    struct node *tmp_node=NULL;

    result = (int **) malloc( sizeof(int *) *(numsSize/3));   
    sizeList = (int *) malloc( sizeof(int) *(numsSize/3));

    *returnColumnSizes = sizeList;
    //printf("*returnColumnSizes = sizeList: sizeList=%p, returnColumnSizes=%p, *returnColumnSizes=%p\n", sizeList, returnColumnSizes,  *returnColumnSizes);
    
    tmp_node = root;
    last_num = 1; // impossible
    duplicated = 0;
    while ( tmp_node ) {
        if ( tmp_node->val != last_num ) {
            duplicated = 0;
            if ( find_2Sum(root, tmp_node, &num2, &num3) ){
                set = malloc(sizeof(int)*3);
                set[0] = tmp_node->val;
                set[1] = num2;
                set[2] = num3;
                result[match_size] = set;
                sizeList[match_size] = 3;  
                match_size++;
            }
        } else { // duplicated
            duplicated++;
            if ( duplicated == 1 ) {// val occurs twice
                printf("%d is duplicated twice\n", tmp_node->val);
                if ( find_1Sum(root, tmp_node,  &num3) ){
                    set = malloc(sizeof(int)*3);
                    set[0] = tmp_node->val;
                    set[1] = set[0];
                    set[2] = num3;
                    result[match_size] = set;
                    sizeList[match_size] = 3;  
                    match_size++;
                }
            } else if ( (duplicated == 2) && (tmp_node->val == 0) ) {
                set = malloc(sizeof(int)*3);
                set[0] = tmp_node->val;           
                set[1] = 0;
                set[2] = 0;  
                result[match_size] = set;
                sizeList[match_size] = 3;  
                match_size++;                        
            } else {               
                printf("%d is ignored because of duplicated > twice\n", tmp_node->val);
            }
        }
        last_num = tmp_node->val;
        tmp_node = tmp_node->left;
        //printf("match_size=%x\n", match_size);
    }
    *returnSize = match_size;
    return result;
}            

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i=0, **result=NULL;
    struct node *root=NULL, *tmp_node=NULL;

    if ( numsSize < 3 ) {
        *returnSize = 0;
        return result;
    }
    // build the BST
    root = (struct node *) malloc(sizeof(struct node));
    root->index = 0;
    root->val = 0;
    root_count = 0;
    root->left = NULL;
    root->right = NULL;
    for ( i=0; i< numsSize; i++) {
        add_node(root, nums[i]);
    }
    int *sizeList=NULL;
    //result = find_3Sum(numsSize, root, returnSize, returnColumnSizes);
    
    result = find_3Sum(numsSize, root, returnSize, &sizeList);
    //printf("sizeList=%p, sizeList[0]=%d\n", sizeList, sizeList[0]);
    *returnColumnSizes = sizeList ;
    release_bst(root);
    //printf("returnSize(%d))\n", *returnSize);
    return result;
}
/*
                             -1   1
                            -1 0   2
                           -4    
                                    

*/
#define NUMS    6
int main(){
    int nums[NUMS]={-1, 0, 1, 2, -1, -4};
    int **answer=NULL, returnSize=0;
    int *returnColumnSizes=NULL;
    int **sets=NULL, *set=NULL;;
    
    answer = threeSum(nums, NUMS, &returnSize, &returnColumnSizes);
    int i=0;
    sets = answer;

    for ( i=0; i<returnSize; i++) {
        printf("%d-set: %d\n", i, returnColumnSizes[i]);
        set = *sets;
        printf("[%d:%d:%d]", set[0], set[1], set[2]);
        printf("\n");
        free(set);
        sets++;
    }

    free(returnColumnSizes);

    if ( answer)
        free(answer);
}
