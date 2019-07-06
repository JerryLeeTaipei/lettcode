/**
 * Definition for a binary tree node.
 */

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


struct TreeNode* createNode() {
    struct TreeNode* tmpNode=NULL;
    tmpNode = malloc(sizeof(struct TreeNode));
    tmpNode->val = 0;
    return tmpNode;
}

/*
  a full tree of N node
  * each level has at least 2 nodes so that the max. of depth is (N+1)/2
  
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** allPossibleFBT(int N, int* returnSize){

    struct TreeNode** btList=NULL, newNode=NULL;
    int n=N;
    while ( n > 0 ) {
        newNode = createNode();
        if ( !newNode ) {
            break;
        }
        
    }
    return btList;
}

