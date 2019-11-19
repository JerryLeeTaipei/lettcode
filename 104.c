/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void visit(struct TreeNode* node, int *depth, int *max_depth){
    
    if ( node ) {
        (*depth)++;
        if ( *depth > *max_depth)
            *max_depth = *depth;  
        //printf("node(%d):%d, %d\n", node->val, *depth, *max_depth);
    } 
    if ( node->left ) {
        visit(node->left, depth, max_depth);
        (*depth)--;
    }
    if ( node->right ) {
        visit(node->right, depth, max_depth); 
        (*depth)--;
    }
}

int maxDepth(struct TreeNode* root){
    int depth=0, max_depth=0;
    
    if ( !root )
        return 0;
    visit(root, &depth, &max_depth);
    return max_depth;
}
