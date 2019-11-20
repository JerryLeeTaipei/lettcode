/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *next=NULL, *last=NULL;
    
    while (node) {
        next = node->next;
        if ( next == NULL ) {// last node
            free(node);
            last->next = NULL;
            break;
        }
        node->val = next->val;
        last = node;
        node = next;    
    }
}
