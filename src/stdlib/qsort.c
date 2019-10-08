#include <stdlib.h>
#include <string.h>

static void qsort_swap(char *a, char *b, size_t size)
{
    char buf[size];
    memcpy(buf, a, size);
    memcpy(a, b, size);
    memcpy(b, buf, size);
}

static inline size_t qsort_partition(char *arr, size_t first, size_t last, size_t size, __compar_fn_t cmp)
{
    char *pivot = &arr[last*size];
    size_t i, j;
    for ( i = j = first; j < last; j++ )
    {
        if(cmp(&arr[j*size], pivot) <= 0)
        {
            qsort_swap(&arr[i*size], &arr[j*size], size);
            i++;
        }
    }
    qsort_swap(&arr[i*size], pivot, size);
    return i;
}

static void quick_sort(void *base, size_t low, size_t high, size_t size, __compar_fn_t cmp)
{
    if(low < high)
    {
        int pi = qsort_partition(base, low, high, size, cmp);
        quick_sort(base, low, pi-1, size, cmp);
        quick_sort(base, pi+1, high, size, cmp);
    }
}

void qsort(void *base, size_t nmemb, size_t size, __compar_fn_t cmp)
{
    quick_sort(base, 0, nmemb-1, size, cmp);
}
