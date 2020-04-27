/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* sortList(struct ListNode* head){
    struct ListNode *current_head=NULL, *next=NULL, *current=NULL, *min=NULL;
    int val;
    
    if ( head == NULL )
        return NULL;
    else if ( head->next == NULL)
        return head;
    
    current_head = head;
    while (current_head) {
        min = current_head;
        current = current_head;
        //printf("test %d: ", current->val);
        while (current->next){
            next = current->next;
            //printf("cmp(%d) ", next->val);
            if ( (next->val) < (min->val) )
                min = next;
            current = next;
        }
        if ( current_head != min ) {// swap value
            //printf("swap(%d,%d)\n", current_head->val, min->val);
            val = current_head->val;
            current_head->val = min->val;
            min->val = val;
        }
        current_head = current_head->next;
    }
    return head;
}

