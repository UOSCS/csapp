#include <stdio.h>
#include <assert.h>

int int_shifts_are_arithemetic() {
  int num = -1;
  printf("%d\n", !(num ^ (num >> 1)));
}

int main(int argc, char* argv[]) {
  assert(int_shifts_are_arithemetic());
  return 0;
}
