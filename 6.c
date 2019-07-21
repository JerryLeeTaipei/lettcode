/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

 anchor_0                                                 anchor_1
 
 0                                                        (r-1)*2
(1)                                        (r-1)+(r-2)    (r-1)*2 +1
(2)                           (r-1)+(r-3)                 (r-1)*2 +2
 .
 .
(r-3)                (r-1)+2                               . 
(r-2)       (r-1)+1                                        .
(r-1)                                                      (r-1)*3


The result array is rows * columns.

How many colums are needed?

the length of the string is l, the rows is r,

 (l-1) / (r-1) = n
 (l-1) % (r-1) = tail

if (n % 2 == 1)
     n = n-1   

if ( tail == 0 )
    c = (n-1) * r
else
    c = (n-2) * r + tail 
       


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
  char *ptr=NULL;
  int r=0, c=0, len=0, anchor=0, tail=0, i=0, a=0, index=0;

  len = strlen(s);
  anchor = len / numRows;
  tail = len % numRows;

  printf(" malloc(%d+1) for %d x %d - %d\n", len, numRows, anchor, (numRows - tail));
  ptr = malloc( sizeof(char) * (len + 1));
  ptr[len] = 0;
  i = 0;
  r = 1;
  a = 0;
  while ( i < len ) {
        printf("---i(%d), r(%d), a(%d)\n", i, r, a);
        if ( (r == 1) || ( r == numRows) ) {
            if ( r == 1 )    
                index = ( numRows - 1 ) * (a * 2);
            else
                index = ( numRows - 1 ) * (a * 2 + 1);
            ptr[i] = s[index];
            printf("r(%d),a(%d), ptr[%d]=%c <- s[%d]\n", r, a, i, ptr[i], index);
            a++;
            if ( a >= anchor ) {
                a = 0;
                r++;
            }
        } else {
            index = ( numRows - 1 ) * (a * 2) + (r-1);
            if ( index < len ) {
                ptr[i] = s[index];
                printf("1-r(%d),a(%d), ptr[%d]=%c <- s[%d]\n", r, a, i, ptr[i], index);
                i++;
                if ( i >= len ) {
                    printf("i-OOR:%d\n", i);
                    break;
               }
                index = ( numRows - 1 ) * (a * 2 + 1) + (numRows-r);
                if ( index < len ) {
                    ptr[i] = s[index];
                    printf("2-r(%d),a(%d), ptr[%d]=%c <- s[%d]\n", r, a, i, ptr[i], index);
                    a++;
                    if ( a >= anchor ) {
                        a = 0;
                        r++;
                    }
                } else {
                    printf("index-OOR:%d\n", index);
                    i--;
                    a = 0;
                    r++;
                }
            } else {
                printf("index-OOR:%d\n", index);
                i--;
                a = 0;
                r++;
            }
        }
        i++;
  } // while

endScan:  
  return ptr;
}


int main(){
  char *ptr=NULL;

  ptr = convert("PAYPALISHIRING",3);

  if ( ptr ) {
    printf("%s\n", ptr);
    free(ptr);
  }
}

