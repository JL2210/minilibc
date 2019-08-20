#include <stdlib.h>

#define qsort_t struct { \
		    char n[size]; \
		}

static void qsort_swap(void *a, void *b, size_t size)
{
    qsort_t buf, *qa = a, *qb = b;
    buf = *qa;
    *qa = *qb;
    *qb = buf;
}

static inline size_t qsort_partition(void *a, size_t first, size_t last, size_t size, __compar_fn_t cmp)
{
    qsort_t *arr = a, *pivot;
    size_t i, j;
    pivot = arr + last;
    for ( i = j = first; j < last; j++ )
    {
        if(cmp(arr + j, pivot) <= 0)
        {
            qsort_swap(&arr[i], &arr[j], size);
            i++;
        }
    }
    qsort_swap(&arr[i], pivot, size);
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
