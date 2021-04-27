#include "heap.h"
#include <string.h>
#include <debug.h>

static void 
swap(heap_elem *a, heap_elem *b)
{
    heap_elem tmp = *a;
    *a = *b;
    *b = tmp;
}


void 
heap_init(struct heap *h, heap_less_than cmp, bool max_heap)
{
    h->size = 0;
    h->cmp = cmp;
    h->max_heap = max_heap;
}

bool 
heap_is_empty(struct heap *h)
{
    return h->size == 0;
}

/* 返回堆顶元素（根） */
heap_elem 
heap_top(struct heap *h)
{
    ASSERT(!heap_is_empty(h));

    return h->c[0];
}

void 
heap_push(struct heap *h, heap_elem e)
{
    size_t i = h->size;
    ASSERT(i < CAPACITY);

    h->c[i] = e;
    while (i != 0) 
    {
        size_t p = (i - 1) / 2;
        if ((h->max_heap && !h->cmp(h->c[p], h->c[i])) || (!h->max_heap && !h->cmp(h->c[i], h->c[p])))
            break;
        swap(&h->c[i], &h->c[p]);
        i = p;
    }

    h->size++;
}

heap_elem 
heap_pop(struct heap *h)
{
    ASSERT(!heap_is_empty(h));

    h->size--;
    swap(&h->c[0], &h->c[h->size]);

    size_t i = 0;
    while (true) 
    {
        size_t c = i * 2 + 1;
        if (c >= h->size)
            break;
        if (c + 1 < h->size && (h->cmp(h->c[c], h->c[c + 1]) == h->max_heap))
            c++;
        if ((h->max_heap && !h->cmp(h->c[i], h->c[c])) || (!h->max_heap && !h->cmp(h->c[c], h->c[i])))
            break;
        swap(&h->c[i], &h->c[c]);
        i = c;
    }

    return h->c[h->size];
}
