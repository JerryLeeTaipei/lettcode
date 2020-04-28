/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void invertChilds(struct TreeNode* node){
    struct TreeNode *tmp=NULL;
    
    if ( node ) {
        tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        invertChilds(node->left);
        invertChilds(node->right);
    }
}

struct TreeNode* invertTree(struct TreeNode* root){

    if (root){
        invertChilds(root);
    } 
        
    return root;  
}

