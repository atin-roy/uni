#include <stdio.h>

union UnionData {
  int intValue;
  float floatValue;
  char stringValue[50];
};

int main() {
  union UnionData data;

  data.intValue = 10;
  printf("Integer Value: %d\n", data.intValue);

  data.floatValue = 3.14;
  printf("Float Value: %.2f\n", data.floatValue);

  sprintf(data.stringValue, "Hello, Union!");
  printf("String Value: %s\n", data.stringValue);

  return 0;
}
