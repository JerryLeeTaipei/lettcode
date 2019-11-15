
#include <stdio.h>
#include <malloc.h>
#include <string.h>

char * addStrings(char * num1, char * num2){
  char *result=NULL, *sum=NULL, *sum_carry=NULL;
  int len1=0, len2=0, max_len=0, min_len=0;
  
  printf("%s + %s\n", num1, num2);
  len1 = strlen(num1);
  len2 = strlen(num2);
  
  if ( len1 > len2 ) {
      max_len = len1;
      min_len = len2;
  } else {
    max_len = len2;
    min_len = len1;      
  }
  sum = malloc(max_len+1);
  sum[max_len] = 0;
  if ( sum == NULL ) {
    return NULL;
  }
  int digit=0;
  int i=len1-1;
  int j=len2-1;
  int k = max_len-1;
  int carry = 0;
  int diff = max_len - min_len;
  while ( k >= 0 ) {
      printf("k(%d), carry(%d)\n", k, carry);
      if ( k >= diff ){
        printf("0->\n");
        digit = carry + num1[i] + num2[j] - 2 * '0';
        i--;
        j--;
      } else {
        if ( len1 > len2 ) {
          printf("1->\n");
          digit = carry + num1[i] - '0';
          i--;
        } else {
          printf("2->\n");
          digit = carry + num2[j] - '0';
          j--;
        }
      }
      if ( digit > 9 ) {
          digit -= 10;
          carry = 1;
      } else {
          carry = 0;
      }
      sum[k] = digit + '0';
      printf("%d,%d\n", carry, digit);
      k--;
  }
  if ( carry ) {
    sum_carry = malloc(max_len+2);
    sum_carry[max_len+1] = 0;
    sum_carry[0] = '1';
    strncpy(sum_carry+1, sum, max_len);
    free(sum);
    result = sum_carry;
  } else
    result = sum;
  //printf("%c %c %c ...\n",result[0], result[1], result[2]);
  return result;
}

// To execute C, please define "int main()"

  
int main() {
  char num1[]="12345", num2[]="678", *result=NULL;
  
  result = addStrings(num1, num2);
  if ( result ) {
    printf("result=%s\n", result);
    free(result);
  }
  else
    printf("0\n");
  printf("end\n");
  return 0;
}
