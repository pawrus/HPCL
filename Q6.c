#include <stdio.h>
#include <omp.h>

int main() {
    int x = 10;

    printf("Before parallel region: x = %d\n", x);

    #pragma omp parallel num_threads(4) private(x)
    {
        int tid = omp_get_thread_num();
        x = tid * 5;
        printf("Thread %d has private x = %d\n", tid, x);
    }
    printf("After parallel region: x = %d\n", x);

    return 0;
}