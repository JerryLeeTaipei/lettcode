
int removeDuplicates(int* nums, int numsSize){
    int curChar=0, nextChar=0;
    int *curPtr=NULL, *nextPtr=NULL, *ptr=NULL;
    int no=0;
    
    if ( numsSize == 0 )
        return 0;
    
    curPtr = nums;
    curChar = nums[0];
    ptr = curPtr;
    no = 1;
    numsSize--;
    while ( numsSize > 0 ) {
        ptr++;
        //printf("no(%d),*ptr=%d: curChar(%d)\n", no, *ptr, curChar);
        if ( *ptr != curChar ) {
            no++;
            curPtr++;
            *(curPtr) = *ptr;
            curChar = *curPtr;
            //printf("---------> %d\n", curChar);
        }
        numsSize--;
    }
    return no;
}

int main() {
  int num1[]={0,0,1,1,1,2,2,3,3,4};
  int no=0;
  
  no = removeDuplicates(num1, sizeof(num1)/sizeof(int) );
  if ( no ) {
    printf("%d\n", no);
  }
  else
    printf("0\n");
  printf("end\n");
  return 0;
}
