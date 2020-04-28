/**
 * Definition for singly-linked list.

struct ListNode {
     int val;
     struct ListNode *next;
 };
  */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *current=NULL, *tmp=NULL, *last;
    
    current = head;
    last = NULL;
    while (current){
        if ( current->next ) {
            tmp = current->next;
            if ( last ){
                last->next = tmp;
            } else {
                head = tmp;
            }
            current->next = tmp->next;
            tmp->next = current;
            last = current;
            current = current->next;
        } else
            break;
        
    }
    return head;
}

