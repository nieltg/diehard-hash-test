#include <stdio.h>
#include <stdint.h>

int main(void) {
  for (uint64_t i = 0;; ++i) {
    fwrite(&i, sizeof(i), 1, stdout);
  }
}
