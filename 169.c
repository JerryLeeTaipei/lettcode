typedef struct node {
    int key;
    int count;
}node_t;

int exist(node_t *table, int table_size, int key){
    int i=0, index = -1;
    
    for (i=0; i<table_size; i++) {
        if ( table[i].count == -1)   
            break;
        else {
            if ( table[i].key == key ){
                index = i;
                break;
            }
        }
    }
    return index;
}

void insert(node_t *table, int table_size, int key){
    int i=0;
    
    for ( i=0; i<table_size; i++ ) {
        if ( table[i].count == -1 ) {  
            break;
        }
    }
    table[i].key = key;
    table[i].count = 1;
    //printf("%d:key(%d) inserted\n", i, key);
}

void update(node_t *table, int table_size,  int key){
    int index=-1;
    //printf("update(%d)\n", key);
    if ( (index=exist(table, table_size, key)) >= 0 ){
        table[index].count++;
        //printf("key(%d) inc(%d)\n", key, table[index].count);
    } else {
        insert(table, table_size, key);
    }
}

int getMax(node_t *table, int table_size){
    int max= 0, i=0, max_key=-1;
    
    for (i=0; i<table_size; i++) {
        //printf("%d, count(%d) > max(%d)\n",table[i].key , table[i].count, max);
        if ( table[i].count > max ) {
            max = table[i].count;
            max_key = table[i].key;
        }
    }
    return max_key;
}

int majorityElement(int* nums, int numsSize){
    node_t *table=NULL;
    int table_size=0, i=0;

    table_size = (numsSize+1)/2;
    table = malloc(sizeof(node_t)*table_size);
    
    for (i=0; i<table_size; i++) {
        table[i].key = 0;
        table[i].count = -1;
    }
    for (i=0; i<numsSize; i++) {
        update(table, table_size, nums[i]);
    }
    
    return getMax(table, table_size);
}
