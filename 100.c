/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool traversal(struct TreeNode* p, struct TreeNode* q){
    // check arch
    if ( p->left && !(q->left )){
        printf("l-r\n");
        return false;
    }
    if ( p->right && !(q->right )){
        printf("r-l\n");
        return false;
    }
    if ( !(p->left) && q->left ){
        printf("-l+r\n");
        return false;
    }
    if ( !(p->right) && q->right ){
        printf("-r+l\n");
        return false;
    }   
    // check val
    if ( p->left && q->left) {
        if ( !traversal( p->left, q->left) ){
            printf("miss-match(%d,%d)\n", p->left->val, q->left->val);
            return false;
        }
    } 
    
    if ( p->val != q->val ) {
        printf("invald key\n");
        return false;
    }    
    
    if ( p->right && q->right) {
        if ( !traversal( p->right, q->right) ){
            printf("miss-match\n");
            return false;
        }
    } 
    
    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    struct TreeNode *tmp_p=NULL, *tmp_q=NULL;
    bool status=false;
    
    if ( !p && !q )
        return true;
    else if ( p && q )
        status = traversal(p, q);
    return status;
    
}
