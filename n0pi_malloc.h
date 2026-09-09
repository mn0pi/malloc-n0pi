#include <stdbool.h>
#include <stddef.h>

typedef struct Block {
  size_t size;
  struct Block *next;
  struct Block *prev;
} Block;

Block *init_heap(void);

void *n0pi_malloc(size_t size);

