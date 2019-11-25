/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int list_count=0;
    struct ListNode *node=NULL, *lastP=NULL;
    
    list_count = n;
    node = head;
    while (node) {
        if ( lastP == NULL ){// 1st node
                lastP = node;
        } 
        if ( list_count >= 0 ) {
            list_count--;
        } else {
            lastP = lastP->next;
        }
        //printf("%d->%d ", lastP->val, node->val);
        node = node->next;
    }
    //printf("\n");
    if ( (head->next == NULL) && ( n==1 ) )
        return NULL;
    if ( list_count == 0 ) {// head is the target
        node = head->next;
        free(head);
        //printf("remove head\n");
        return node;
    }
    node = lastP->next;
    //printf("remove %d\n", node->val);
    lastP->next = node->next;
    free(node);
    return head;
}

