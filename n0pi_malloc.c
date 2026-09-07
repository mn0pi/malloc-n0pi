#include "n0pi_malloc.h"
#include <sys/mman.h>
#include <unistd.h>

#define N0PI_HEAP_PAGES 4

static Block *freeListRoot = NULL;


void *init_heap() {
  size_t size = N0PI_HEAP_PAGES * getpagesize();
  void *heap = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (heap == MAP_FAILED) {
    return NULL;
  }
  Block *heap_start = (Block *)heap;
  heap_start->size = size;
  heap_start->allocated = false;
  freeListRoot = heap_start;
}

//void *n0pi_malloc(size_t size) {
  // check free list
  // if found:
  //  block.size > size ? shrink : return block
  // else:
  //  return null
//}

//Block *checkFreeList(size_t size) {
  // walk free list
  // if block.size >= size: return block
  // if last block && < size: return null
//}

//void n0pi_free(void *ptr) {
  // get block from ptr
  // add block to free list
//}
