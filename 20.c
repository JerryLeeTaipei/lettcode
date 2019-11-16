#define SL  '('
#define SR  ')'
#define ML  '['
#define MR  ']'
#define LL  '{'
#define LR  '}'

typedef struct node {
    char val;
    struct node *next;
    struct node *pre;
}node_t;

/*
 list must not be NULL
 return the added node (the last node)
*/
node_t* append_node(node_t *last, int val){
    node_t *new=NULL;    
    
    new = malloc(sizeof(node_t));
    new->val = val;
    new->pre = last;
    new->next = NULL;
    last->next = new;
    return new;
}

bool has_leftTail(node_t *left_tail, char r) {
  
  switch (r) {
                case SR:
                      if ( left_tail->val != SL ){
                        return false;
                      } 
                      break;
                case MR:
                      if ( left_tail->val != ML ){
                        return false;
                      }
                      break;      
                case LR:
                      if ( left_tail->val != LL ){
                        return false;
                      }
                      break;
  }
  return true;
}

bool isValid(char * s){
    char *ptr=NULL;
    node_t *left_head=NULL, *left_tail=NULL, *tmp_node=NULL;
    int l_count=0, r_count=0;
    bool status=true;
    
    left_head = malloc(sizeof(node_t));
    left_head->val = '/';
    left_head->pre = NULL;
    left_head->next = NULL;
    left_tail = left_head;
    ptr = s;
    while ( *ptr != 0 ) {
        if ( *ptr != ' ') {
            switch (*ptr) {
                case SL:
                case ML:
                case LL:
                    left_tail = append_node(left_tail, *ptr);
                    l_count++;
                    break;
                case SR:
                case MR:
                case LR:
                    if ( !has_leftTail(left_tail, *ptr) ) {
                      //printf("No left_tail matched %c\n",  *ptr);
                      status = false;
                      goto quit;
                    }
                    tmp_node = left_tail;
                    left_tail = left_tail->pre;
                    //free(tmp_node);
                    r_count++;
                    break;   
                //default:
                    //printf("invalid:%c\n", *ptr);                    
            }
            
        }    
        ptr++;
    }// while
    //check count
    if ( l_count != r_count ) {
      //printf("count is not matched: %d, %d\n", l_count, r_count);
      status = false;
      goto quit;
    }

quit:
  
  while ( left_tail ){
    //printf("free %c\n", left_tail->val);
    tmp_node = left_tail;
    left_tail = left_tail->pre;
    
    free(tmp_node);
  }
  
  return status;
}
