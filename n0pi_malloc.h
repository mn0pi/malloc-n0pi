#include <stdbool.h>
#include <stddef.h>

typedef struct Block {
  size_t size;
  bool allocated;
} Block;

Block *init_heap(void);

