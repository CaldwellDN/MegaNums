#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char* NumStr;
  int length;
} MegaNum;


void MegaNum_Init(MegaNum *name) {
  name->NumStr = malloc(2*sizeof(char));

  if (name->NumStr == NULL) {
    perror("Error Initializing MegaNum");
  }

  strncpy(name->NumStr, "0", 2);

  name->length = 1;

}

void MegaNum_Terminate(MegaNum *name) {
  free(name->NumStr);
  name->NumStr = NULL;
  name->length = 0;
}

void MegaNum_Set(MegaNum *name, char *value) {
  // MegaNum_Set(test, "10000");
  if (name == NULL || value == NULL)
    perror("Error reading name/value");

  for(size_t i = 0; i < strlen(value); i++) {
    if (!isdigit(value[i])) {
      perror("Value contains non digits!");
    }
  }

  name->length = strlen(value);
  free(name->NumStr);
  name->NumStr = malloc((name->length+1)*sizeof(char));
  if (name->NumStr == NULL)
    perror("Error allocating memory");
  strncpy(name->NumStr, value, name->length+1);
}


// NOTE: Returns 0 if both vals are equal, 1 if val1 is greater than val2, -1 otherwise
int MegaNum_Compare(MegaNum *value1, MegaNum *value2) {
  // Check first if both values are initialized
  if (value1->NumStr == NULL || value2->NumStr == NULL)
    perror("Error reading values during comparison");
  // Basic length check
  if (value1->length != value2->length)
    return value1->length > value2->length ?  1 : -1;

  if (value1->length == value2->length) {
    if (strcmp(value1->NumStr, value2->NumStr) == 1)
      return 0;

    for (size_t i = 0; i < value1->length; i++) {
      return atoi(&value1->NumStr[i]) > atoi(&value2->NumStr[i]) ? 1 : -1; // NOTE: MAKE STRTOL()
    }
  }
}

// Add two MegaNum values together
void MegaNum_Add(MegaNum *val1, MegaNum *val2) {
  int largestNumSize = MegaNum_Compare(val1, val2) >= 0 ?
}


int main() {
  MegaNum test, test2;

  MegaNum_Init(&test);
  MegaNum_Init(&test2);

  MegaNum_Set(&test, "12000");
  MegaNum_Set(&test2, "10000");

  int ans = MegaNum_Compare(&test, &test2);


  if (ans == 2){
    printf("Equal");
  } else if (ans == 1) {
    printf("test > test2");
  } else if (ans == 0) {
    printf("test < test2");
  }

  printf("\n");

  printf("%s\n", test.NumStr);
  printf("%s\n", test2.NumStr);

  MegaNum_Terminate(&test);
  MegaNum_Terminate(&test);

  return 0;
}
