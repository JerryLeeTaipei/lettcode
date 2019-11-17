

typedef struct node{
    int val;
    struct node *prev;
    struct node *next;
}node_t;

typedef struct {
    int size;
    int usage;
    struct node *front;
    struct node *end;    
    struct node *queue;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *deq=NULL;
    int i=0;
    
    deq = malloc(sizeof(MyCircularDeque));
    deq->size = k;
    if ( k ) {
        deq->queue = malloc(sizeof(node_t));
        node_t *tmp_node=NULL;
        node_t *last_node = deq->queue;
        for ( i= 1; i<k; i++ ){
            tmp_node = malloc(sizeof(node_t));
            last_node->next = tmp_node;
            tmp_node->prev = last_node;
            last_node = tmp_node;
        }
        last_node->next = deq->queue;
        deq->queue->prev = last_node;
    } else {
        deq->queue = NULL;
    }
    deq->front = deq->end = NULL;
    deq->usage = 0;
    return deq;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    bool status=false;
    node_t *front=NULL;
    
    if ( obj->usage < obj->size ) {
        if (obj->front == NULL) {
            front = obj->queue;
            obj->end = front;
        } else {
            front = obj->front->prev;
        }
        front->val = value;
        obj->front = front;
        obj->usage++;
        return true;  
    }
    return false;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    bool status=false;
    node_t *end=NULL;
    
    if ( obj->usage < obj->size ) {
        if (obj->end == NULL) {
            end = obj->queue;
            obj->front = end;
        } else {
            end = obj->end->next;
        }
        end->val = value;
        obj->end = end;
        obj->usage++;
        return true;  
    }
    return false;  
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    bool status=false;
    node_t *front=NULL;
    
    if ( obj->usage >0 ) {
        obj->front = obj->front->next;
        obj->usage--;
        return true;  
    }
    return false;  
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    bool status=false;
    node_t *end=NULL;
    
    if ( obj->usage >0 ) {
        obj->end = obj->end->prev;
        obj->usage--;
        return true;  
    }
    return false;    
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    
    if ( obj->usage >0 ) {
        return obj->front->val;  
    }
    return -1;     
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if ( obj->usage >0 ) {
        return obj->end->val;  
    }
    return -1;     
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if ( obj->usage >0 ) 
        return false;
    else
        return true;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
     if ( obj->usage == obj->size ) 
        return true;
    else
        return false; 
}

void myCircularDequeFree(MyCircularDeque* obj) {
    
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
