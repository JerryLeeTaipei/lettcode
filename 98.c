/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *find_BstParent(struct TreeNode* root, struct TreeNode* child){
    struct TreeNode *parent=NULL;
    
    //printf("find parent for child: %d(%p)\n", child->val, child);
    parent = root;
    while (parent) {
        //printf("parent(%d)\n", parent->val);
        if ( child->val < parent->val ) {
            if ( parent->left ) {
                if (child->val == parent->left->val ){
                    //printf("%d(%p) == %d(%p)\n", child->val, child,  parent->left->val, parent->left);
                    if ( child != parent->left )//duplicate val
                        return NULL;
                    else
                        break;
                }
                parent = parent->left;
                //printf("parent->left(%d)\n", parent->val);
            } else
                break;            
        } else { // child->val > parent->val ) 
            if ( parent->right ) {
                if (child->val == parent->right->val ){
                    //printf("%d(%p) == %d(%p)\n", child->val, child,  parent->right->val, parent->right);
                    if ( child != parent->right )//duplicate val
                        return NULL;  
                    else
                        break;
                }
                parent = parent->right;
                //printf("parent->right(%d)\n", parent->val);
            } else
                break;    
        }
    }// while
    //printf("return parent(%d) for child(%d)\n", parent->val, child->val);
    return parent;
}

bool isBstNode(struct TreeNode* root,  struct TreeNode* parent, struct TreeNode* child) {
    struct TreeNode* node=NULL;
/*    
    if ( parent->val == child->val ){
        printf("duplicated %x\n", parent->val);
        return false;
}*/
    node = find_BstParent(root, child);
    //printf("ideal(%d) == real(%d) ? for child(%d)\n", parent->val, node->val, child->val);
    if ( !node )
        return false;
    if ( node->val != parent->val )
        return false;
    else
        return true;
}

bool visit(struct TreeNode* root, struct TreeNode* node ) {
    bool rc=true;
    struct TreeNode *left=NULL, *right=NULL;


    //printf("node(%d)\n", node->val);

        if ( node->left ){
            if ( node->left->val >= node->val )
                return false;
            rc = visit(root,node->left);
            if ( !rc ){
                return false;
            }
            if ( ! isBstNode(root,  node, node->left) )
                return false;
        }
        if ( ! find_BstParent(root, node) )
                return false;
        if ( node->right ){
            if ( node->right->val <= node->val )
                return false;
            rc = visit(root,node->right);
            if ( !rc ){
                return false;
            }
            if ( ! isBstNode(root,  node, node->right) )
                return false;
        }

    //printf("node(%d) return (%d)\n", node->val, rc);
    return rc;
}

bool isValidBST(struct TreeNode* root){
    bool rc=true;
    
    if ( !root )
        return true;
    
    rc = visit(root, root);
        
    return rc;
}

