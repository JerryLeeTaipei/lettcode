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

 0                           (r-1)*2
(1)                       .  (r-1)*2 +1
(2)                   .      (r-1)*2 +2
 .             (r+1)         . 
 .       (r)                 .
(r-1)                        (r-1)*3


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

char * convert(char * s, int numRows){

}

