/**
 * Definition for singly-linked list.
  */

 struct ListNode {
      int val;
      struct ListNode *next;
 };


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
  int val=0, match=0;
  struct ListNode *tmp=NULL, *tmp1=NULL, *tmp2=NULL, *result=NULL, *tail=NULL;
  tmp1 = l1;
  tmp2 = l2;
  while ( 1 ){
    val = 0;
    if ( tmp1 )
      val += tmp1->val;
      tmp1 = tmp1->next;
    if ( tmp2 )
      val += tmp2->val;
      tmp2 = tmp2->next;
    if ( !tmp1 && !tmp2 ) {
      break;
    }
    tmp = malloc(sizeof(struct ListNode));
    tmp->val = val;
    tmp->next = NULL;
    if ( !tail ) {// NOT 1st node
      tail->next = tmp;
      tail = tmp;
    } else // 1st node
      result = tail;
  }
  return result;
}
