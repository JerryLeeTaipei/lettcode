bool sqrsum_1(unsigned long *m){
    unsigned char mod=0;
    unsigned long sum=0, divisor=10, n;
    
    n = *m;
    if ( n < 10 ){
        if ( n == 1 )
            return true;
        else {
            *m = (n *n);
            return false;
        }
    }
    while ( n > 10 ) {
        mod = n % 10;
        sum += (mod * mod);
        n = n/10;
        divisor *= 10;
    }
    sum += (n *n);
    //printf("sum(%ld)\n", sum);
    if ( sum == divisor )
        return true;
    else {
        *m = sum;
        return false;
    }
}

bool isHappy(int n){
    unsigned long m=0;
    printf("input(%d)\n", n);
    m = n;
    while ( !sqrsum_1(&m) ) 
        ;//printf("%ld\n", m);
    return true;
    
}
