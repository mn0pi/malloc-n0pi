#include <assert.h>
#include <stdio.h>
#include "n0pi_malloc.h"

int main(void) {
    void *heap = init_heap();
    assert(heap != NULL);

    assert(heap->allocated == false);
    printf("heap size: %z\n", heap->size);

    printf("init_heap test passed\n");
    return 0;
}
