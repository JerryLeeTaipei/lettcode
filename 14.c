/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char *ans_p=NULL;
    int i=0, j=0, min_len=0, len = 0;
    int end=0;
    
    printf("0. %d\n", strsSize );
    if ( strsSize == 0 )
        goto l_exit;

    min_len = strlen(strs[0]);
    for ( i=1; i< strsSize; i++ ) {
        len = strlen(strs[i]);
        if ( len < min_len )
            min_len = len;
    }
    i = 0;

    while ( i < min_len ) {
        end = 0;
        for ( j=0; j< strsSize-1; j++ ) {
            if ( strs[j][i] != strs[j+1][i] ){
                end = 1;
                break;
            }
        }
        if (end)
            break;
        else
            i++;
    }
    
l_exit:
    ans_p = (char *) malloc(sizeof(char) * (i+1));
    if ( i > 0 )
        strncpy(ans_p, strs[0], i);
    ans_p[i] = 0;

    return ans_p;
}
#define STR1 ""
#define STR2 ""
#define STR3 ""
#define STR_NUM 1

int main(){
    char *inputs[0], *ans=NULL;
    
    ans = longestCommonPrefix(inputs, STR_NUM);
    
    if ( ans ) {
        printf("prefix=%s\n", ans);
        free(ans);
    } else
        printf("NULL\n");
} 
