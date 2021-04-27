#ifndef THREADS_HEAP_H
#define THREADS_HEAP_H

#include <stdbool.h>
#include <stddef.h>

#define CAPACITY 1024

/* 自定义比较函数：如果 a < b 返回 true ，如果 a >= b 返回 false */
typedef bool heap_less_than(void *a, void *b);

/* 堆元素指针 */
typedef void *heap_elem;

struct heap
{
    heap_elem c[CAPACITY]; // 最大容量
    size_t size;           // 当前大小
    heap_less_than *cmp;   // 堆使用的比较函数
    bool max_heap;         // 是否是大根堆（若为 false 则是小根堆）
};

void heap_init(struct heap *, heap_less_than, bool max_heap);
bool heap_is_empty(struct heap *);
heap_elem heap_top(struct heap *);
void heap_push(struct heap *, heap_elem);
heap_elem heap_pop(struct heap *);

#endif /* threads/heap.h */
