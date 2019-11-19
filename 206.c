/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void print_newHead(struct ListNode* newHead){
    struct ListNode* node=NULL;
    
    node = newHead;
    while (node) {
        printf("node(%d)\n", node->val);
        node = node->next;
    }
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* node=NULL, *newHead=NULL, *tmp1=NULL, *tmp2=NULL;
    
    node = head;
    while ( node ){
        tmp2 = malloc(sizeof(struct ListNode));
        tmp2->val = node->val;
        tmp2->next = tmp1;
        newHead = tmp2;
        //printf("newHead(%x, %d)->next(%x)\n", newHead, newHead->val, newHead->next);
        if ( node->next ) {
            node = node->next;
            tmp1 = malloc(sizeof(struct ListNode));
            tmp1->val = node->val;
            tmp1->next = tmp2;
            newHead = tmp1;
        }
        //printf("newHead(%x, %d)->next(%x)\n", newHead, newHead->val, newHead->next);
        node = node->next;        
    }
    //print_newHead(newHead);
    return newHead;
}
