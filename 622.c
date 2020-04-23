

typedef struct {
    int *array;
    int size;
    int usage;
    int rear;
    int front;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue=NULL;
    
    queue = (MyCircularQueue *) malloc(sizeof(MyCircularQueue));
    queue->array = malloc(sizeof(int) * k);
    queue->size = k;
    queue->usage = 0;
    queue->rear = queue->front = 0;
    
    return queue;
}

void dec_rear(MyCircularQueue* obj){
    if ( obj->rear == 0 )
        obj->rear = obj->size -1;
    else
        obj->rear--;
}

void dec_front(MyCircularQueue* obj){
    if ( obj->front == 0 )
        obj->front = obj->size -1; 
    else
        obj->front--;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  
    if ( obj->size == obj->usage )
        return false;
    if ( obj->usage == 0 ) { // reset
        obj->rear = obj->front = 0;
        obj->array[obj->rear] = obj->array[obj->front] = value;    
    } else{
        dec_rear(obj);
        obj->array[obj->rear] = value;
    }
    obj->usage++;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
 
    if ( obj->usage == 0 )
        return false;
    else {
        obj->array[obj->front] = 0;
        dec_front(obj);
        obj->usage--;
        return true;
    }
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  
    if ( obj->usage == 0 )
        return -1;
    return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  
    if ( obj->usage == 0 )
        return -1;
    return obj->array[obj->rear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  
    if ( obj->usage == 0 )
        return true;
    else
        return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  
    if ( obj->usage == obj->size )
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    
    if ( obj->size > 0 )
        free(obj->array);
    if (obj)
        free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
