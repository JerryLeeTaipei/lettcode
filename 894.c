#include<stdio.h>

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
     int index;
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


struct TreeNode* createNode(int index) {
    struct TreeNode* tmpNode=NULL;
    tmpNode = malloc(sizeof(struct TreeNode));
    tmpNode->index = index;
    tmpNode->val = 0;
}

int createChildren(struct TreeNode* node) {
    struct TreeNode* tmpNode=NULL;
    
    tmpNode = malloc(sizeof(struct TreeNode));
    if ( !tmpNode )
        return 1;
    tmpNode->val = index + 1;
    tmpNode->val = 0;
    node->left = tmpNode;
    
    tmpNode = malloc(sizeof(struct TreeNode));
    if ( !tmpNode )
        return 1;    
    tmpNode->val = index + 2;
    tmpNode->val = 0;
    node->right = tmpNode;
    return 0;
}

/*
  A full tree of N nodes, each level has at least 2 nodes so that the max. of depth is (N+1)/2
  1. Build a complete binary tree with (N+1)/2 depth
     Each node is labeled from top-down and left-right, each node's index for a level :
        index = 2^(level-1) ~ 2^(level) - 1
     The lable of the root node is 0 at level-0.
     The nodes in the level-1: 1, 2
     ...
     The nodes in the level-n are indexed with:  2^(level-1) ...  2^(level) - 1
  2. Visit the node level by level and recursively
     a. the max number of node this level can have: 2^0, 2^1, 2^2, ... 2^[(N+1)/2]
     b. pick up nodes combinationally from 1 until the total number is achieved.
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** allPossibleFBT(int N, int* returnSize){

    struct TreeNode** btList=NULL, newNode=NULL;
    int n=N;
    int index = 0;
    int ret=0;
    // build a complete binary tree with the depth (N+1)/2
   
    while ( n > 0 ) {       
        newNode = createNode(index);
        if ( !newNode ) {
            printf("Out of memory\n");
            return NULL;
        }           
        n--;
        index++;
        if ( createChildren(newNode) != 0 ) {
            printf("Failed to create children\n");
            break;
        }           
        if ( !btList )
            btList = newNode;
        n -=2 ;
        index += 2;
    }    

    return btList;
}

int main(void) {
    puts("Hello World!");
    return 0;
}
