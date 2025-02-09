#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*
9+5 = 14 * 10^0 = 14
1+1 = 2 * 10^1 = 20
0+1 = 1 * 10^2 = 100
1+0 = 1 * 10^3 = 1000

Total = 1134
*/

int main() {
  int total = 0;
  char* strA = "1019";
  char* strB = "115";

  char** longest;
  char** shortest;
  if (strlen(strA) > strlen(strB)) {
    longest = &strA;
    shortest = &strB;
  } else {
    longest = &strB;
    shortest = &strA;
  }

  size_t lenLong = strlen(*longest);
  size_t lenShort = strlen(*shortest);
  size_t lenDiff = lenLong-lenShort;

  int num = 0;
  int powIterator = 0;
  for(int i = lenLong-1; i >= 0; i--) {
    num += (*longest)[i] - '0';
    if (i-lenDiff >= 0 && i-lenDiff < lenLong) {
      num += (*shortest)[i-lenDiff] - '0';
    }

    total += num * pow(10, powIterator);
    powIterator++;
    num = 0;
  }


  printf("Total: %d\n", total);
  return 0;
}
