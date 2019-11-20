unsigned char reverseByte(unsigned char byte){
    unsigned char num=0;
    
    num = (byte&1)<<7 | (byte&2)<<5 | (byte&4)<<3 | (byte&8)<<1 | (byte&0x10)>>1 | (byte&0x20)>>3 | (byte&0x40)>>5 | (byte&0x80)>>7 ;
    //printf("%d,%d,%d,%d:%d,%d,%d,%d\n", (byte&1)<<7 , (byte&2)<<5 , (byte&4)<<3, (byte&8)<<1 , (byte&0x10)>>1 , (byte&20)>>3 , (byte&40)>>5 , (byte&80)>>7 );
    printf("%x -> %x\n", byte, num);
    return num;
}

uint32_t reverseBits(uint32_t n) {
    unsigned char bytes[4];
    unsigned long num=0;
    unsigned long flag=0;
    
    printf("%ld\n", n);
    bytes[0] = 0x000000FF & n;
    bytes[0] = reverseByte(bytes[0]);
    bytes[1] = (0x0000FF00 & n) >> 8;
    bytes[1] = reverseByte(bytes[1]);
    bytes[2] = (0x00FF0000 & n) >> 16;
    bytes[2] = reverseByte(bytes[2]);
    bytes[3] = (0xFF000000 & n) >> 24;
    bytes[3] = reverseByte(bytes[3]);
    num =  ( (unsigned long) bytes[0] )<<24 ;
    num |=  bytes[1]<<16 | bytes[2]<<8 | bytes[3];

    return num;
}
