#include "n0pi_malloc.h"
#include <sys/mman.h>
#include <unistd.h>

#define N0PI_HEAP_PAGES 4

static Block *freeListRoot = NULL;
static int freeListLength = 0;

void *init_heap() {
  size_t size = N0PI_HEAP_PAGES * getpagesize();
  void *heap = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (heap == MAP_FAILED) {
    return NULL;
  }
  Block *heap_start = (Block*)heap;
  heap_start->size = size;
  heap_start->next = NULL;
  heap_start->prev = NULL;
  freeListRoot = heap_start;
  freeListLength = 1;
  return heap_start;
}

void *n0pi_malloc(size_t size) {
  Block *currentNode = freeListRoot;
  for (int i = 0; i < freeListLength; i++) {
    if (currentNode->size >= size) {
      Block *nextNode = currentNode->next;
      Block *prevNode = currentNode->prev;
      
      if (prevNode == NULL) {
        freeListRoot = nextNode;
      } else {
        prevNode->next = nextNode;
      }

      if (nextNode != NULL) {
        nextNode->prev = prevNode;
      }

      freeListLength--;
      return currentNode;
    }
    currentNode = currentNode->next;
  }
  return NULL;
}

//Block *checkFreeList(size_t size) {
  // walk free list
  // if block.size >= size: return block
  // if last block && < size: return null
//}

//void n0pi_free(void *ptr) {
  // get block from ptr
  // add block to free list
//}
