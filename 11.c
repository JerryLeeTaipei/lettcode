/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/



int maxArea(int* height, int heightSize){
    int width=0, area=0, max_area=0, index=0, offset=0, h=0;
    char *ptr=NULL;

        
    printf("heightSize=%d\n", heightSize);
    width = heightSize-1;
    while ( width >0 ) {
        offset = width;
        index = 0;
        while ( offset < heightSize ) {
            //printf("%d/%d\n", offset, width);
            h = (height[index] < height[offset]) ? height[index] : height[offset];
            area = width * h;
            //printf("[%d, %d]:w(%d)*h(%d)=%d\n", index, offset, width, h, area);
            if ( area >= max_area ) {
                max_area = area; 
                printf("max_area=%d\n", max_area);
            } else {
                printf("area=%d\n", area);
            }
            index++;
            offset++;
        }       
        width--;
    }
    return max_area;
}
