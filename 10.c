/*
10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define RULE_SINGLE 1
#define RULE_ANY 2
#define RULE_REPEATED 4

char *process_match(char rules, char *s, char *p){
    char *s_p=NULL, preceeding=0;

    s_p = s;
    if ( *s_p == 0)
        return s_p; 
    if ( p[1] == 0 ) { // single match
        if ( p[0] == '.' ) {
            s_p++;
        } else {
            if ( p[0] == *s_p ) {
                s_p++;
            } else
                return NULL;
        } 
        return s_p;
    } else {
        printf("*match the preceeding %c%c...\n", p[0],p[1]);
        if ( p[0] == '.' )
            preceeding = *s_p;
        else
            preceeding = p[0];
        while ( *s_p != 0 ) {
            if ( *s_p != preceeding ) {
                return s_p;
            } 
            s_p++;
        }
        return s_p; 
    }
}

bool isMatch(char * s, char * p){
    char *s_p=NULL, *target_p=NULL, rules=0, pattern[3];
    
    if ( s && p && (strlen(s) == strlen(p)) )
        return true;
        
    s_p = s;
    target_p = p;
    pattern[2] = 0;
    while ( (*s_p != 0) && (*target_p != 0) ) {
        printf("s:%s, p:%s\n", s_p, target_p);
        if ( *target_p == '.' ) {
            pattern[0] = '.';
            if ( *(target_p+1) != '*' )  {       
                rules = RULE_ANY;
                pattern[1] = 0;           
                printf("%c%c rules=%x for s_p:%s\n", pattern[0], pattern[1], rules, s_p);
                s_p = process_match(rules, s_p, pattern);

            }
        } else if ( *target_p == '*' ) {
            rules |= RULE_REPEATED;
            pattern[1] = '*';
            printf("%c%c rules=%x for s_p:%s\n", pattern[0], pattern[1], rules, s_p);
            s_p = process_match(rules, s_p, pattern);
            rules = 0;
            pattern[0] = 0;
            pattern[1] = 0;
        } else {
            pattern[0] = *target_p;
            if ( *(target_p+1) != '*' ) {
                rules = RULE_SINGLE;
                pattern[1] = 0;
                printf("%c%c rules=%x for s_p:%s\n", pattern[0], pattern[1], rules, s_p);
                s_p = process_match(rules, s_p, pattern);
            } 
        }
        if ( s_p == NULL ) {
            printf("match failure\n");
            return false;
        }
        target_p++;
        if ( *s_p == 0 ) { 
            if (*target_p != 0) {  // remained pattern must not match
                printf("check remained pattern:%s\n", target_p);
                if ( (target_p+1) && (*(target_p+1) != 0) ) {
                    if ( *(target_p+1) == '*' ) {
                        if ( *(target_p+2) != 0 )
                            return false;
                        else
                            return true;
                    } else
                        return false;
                } else // single char match should fail
                    return false;          
            } else {
                printf("EoP\n");
                return true;
            }
        }
        printf("===s:%c, p:%c===\n", *s_p, *target_p);
    }// while
    // end of p
    if ( (*target_p == 0) && (*s_p != 0) )
        return false;
    // end of s
     if ( (*target_p != 0) && (*s_p == 0) )
        return false;   
    return true;

}


#define SRC "aaa"
#define PATTERN "ab*a*c*a"


int main() {
    bool ret=false;

    ret = isMatch(SRC,PATTERN);
    printf(" %s includes %s?\n", SRC, PATTERN);
    if ( ret )
        printf("match\n");
    else
        printf("not match\n");
}

