bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int *row=NULL;
    int colSize = 0;
    int rowSize=0;
    int i=0, j=0;
    
    if ( !matrixColSize )
        return false;
    if ( !matrixSize )
        return false;

    colSize = *matrixColSize;
    rowSize = matrixSize;
    if ( !rowSize )
        return false;
    if ( !colSize )
        return false;
    //printf("size(%d), colSize(%d)\n", rowSize, colSize);
    for ( i=0; i< rowSize; i++ ){
        row = matrix[i];
        if ( target <= row[colSize-1] )
            for ( j=0; j<colSize; j++ )
                if ( target == row[j] )
                    return true;
    }
    return false;
}

#define ROWS 3
#define COLS 4

int main() {
    int **array=NULL, cols=0, target=0;
    int i=0;
    int a[COLS]= {1,3,5,7}, b[COLS]= {10,11,16,20}, c[COLS]= {23,30,34,50};
    
    array = malloc( sizeof(int *) * ROWS );
    for ( i=0; i<ROWS; i++)
        array[i] = malloc(sizeof(int*) * COLS);
        
    target = 3;
    
    array[0] = a;
    array[1] = b;
    array[2] = c;
    
    cols = COLS;
    if ( searchMatrix(array, ROWS, &cols, target) )
        printf("Yes\n");
    else
        printf("N\n");
    
  return 0;
}
