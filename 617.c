/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */




struct TreeNode*  visit(struct TreeNode* t1, struct TreeNode* t2,  struct TreeNode *parent, char dir){
    struct TreeNode *root=NULL, *node=NULL;
    int val=0;
    printf("dir(%c)\n", dir);
    if ( !t1 && !t2 )
        return NULL;
    if ( t1 && t2 ){
        printf("(%d,%d)\n", t1->val, t2->val);
        val =  t1->val + t2->val;
    }
    else if ( t1 ){
        printf("(%d,)\n", t1->val);
        val =  t1->val;
    }
    else if ( t2 ){
        printf("(,%d)\n", t2->val);  
        val = t2->val;
    }
    printf("%c: Merged=%d\n", dir, val);
    node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    if ( parent ){
        if ( dir == 'L')
            parent->left = node;
        if ( dir == 'R')
            parent->right = node;
    } else
        root = node;
    parent = node;
    printf("<-\n");
    if ( !t1 ) {
        visit(NULL, t2->left, parent, 'L');
    } else if ( !t2 ) {
        visit(t1->left, NULL, parent, 'L');
    } else if ( (t1 && t1->left) || (t2 && t2->left) ) {
        visit(t1->left, t2->left, parent, 'L');
    }

    printf("->\n");
    if ( !t1 ) {
        visit(NULL, t2->left, parent, 'R');
    } else if ( !t2 ) {
        visit(t1->left, NULL, parent, 'R');
    } else if ( (t1 && t1->right) || (t2 && t2->right) ) {
        visit(t1->right, t2->right, parent, 'R');
    }
    
    return root;
}

void printTree(struct TreeNode* node){    
    
    printf("node(%d)\n", node->val);
    if ( node->left ) 
        printTree(node->left);
    if ( node->right )
        printTree(node->right);
        
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    struct TreeNode *tree=NULL;

    if ( !t1 )
        return t2;
    if ( !t2 )
        return t1;
    printf("visit\n");
    tree = visit(t1,t2, NULL, 0);
    //printTree(tree);
    
    return tree;
}

