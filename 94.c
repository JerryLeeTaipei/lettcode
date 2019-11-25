/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void travell(struct TreeNode* node, int** result, int* returnSize) {
    int *ptr=NULL;
    
    if ( node == NULL )
        return;

    if ( node->left )
        travell(node->left, result, returnSize);
    //printf("%d\n", node->val);
    (*returnSize)++;
    ptr = *result;
    *result = (int *) realloc(*result, *returnSize* sizeof(int));
    (*result)[*returnSize -1] = node->val;
    if ( node->right )
        travell(node->right, result, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){

    *returnSize = 0;

    if ( root == NULL ) {
        return NULL;
    }
    int *result=NULL;
    travell(root, &result, returnSize);
    //printf("total(%d)", *returnSize);
    return result;
}
