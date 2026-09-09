#include <stdbool.h>
#include <stddef.h>

typedef struct Block {
  size_t size;
  struct Block *next;
  struct Block *prev;
} Block;

Block *init_heap(void);

