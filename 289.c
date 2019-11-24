
int lives(int **board, int i, int j){
    return ( board[i-1][j-1]+board[i-1][j]+board[i-1][j+1]+board[i][j-1]+board[i][j+1]+board[i+1][j-1]+board[i+1][j]+board[i+1][j+1] );
    
}

int conv(int **pad, int i, int j){
    int n=0;
    
    //printf("conv(%d,%d)\n", i, j);
    n = lives(pad, i, j);
    //printf("%d:conv(%d,%d)=%d\n",pad[i][j], i, j, n);
    if ( pad[i][j] ){ // live
        if ( n<2 )
            return 0;
        else if ( (n==2) ||(n==3) )
            return 1;
        else 
            return 0;
    } else { // dead
        if ( n==3 )
            return 1;
        else 
            return 0;
    }
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int **pad=NULL;// for 5 x 12
    int i=0, j=0, padSize=0, padColSize=0;
    
    printf("board(%d x %d) \n", boardSize, *boardColSize);
    padSize = boardSize + 2;
    padColSize = *boardColSize + 2;
    //printf("pad(%d x %d) \n", padSize, padColSize);
    pad = malloc(sizeof(int*) * padSize);
    for ( i=0; i< (padSize); i++) {
        pad[i] = malloc(sizeof(int)*padColSize);
        if ( (i!=0) && i != (padSize-1) ){
            for ( j=1; j< (padColSize-1); j++ ) {
                pad[i][j] = board[i-1][j-1];                
            }    
            pad[i][0] = pad[i][padColSize-1] = 0;
        } else {
            for ( j=0; j< (padColSize); j++ ) {
                 pad[i][j] = 0;                
            }   
        }
    }
#if 0    
    for (  i=1; i<padSize-1; i++ ){
        for ( j=1; j<padColSize-1; j++) {
            printf("%d ", pad[i][j] );
        }
        printf("\n");
    }
#endif
    //printf("\nnext generation\n\n");

    for (  i=1; i<(padSize-1); i++ ){
        for ( j=1; j<(padColSize-1); j++) {
                board[i-1][j-1] = conv(pad, i, j); 
                //printf("%d ", pad[i][j] );
                //board[i-1][j-1] = pad[i][j];
        }
        printf("\n");
    }

    
}
