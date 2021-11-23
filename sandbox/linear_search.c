#include <stdio.h>

// cf: https://blog.h13i32maru.jp/entry/2012/07/01/000000
int main() {
  int input[] = {1, 2, 3, 4, 5, 6};
  int len = (int)(sizeof(input)/sizeof(int));
  int target = 5;
  int i;

  for(i = 0; i < len; i++) {
    if (input[i] == target) {
      printf("target index is %d\n", i);
      return 1;
    }
  }
  printf("not found");
  return 0;
}
