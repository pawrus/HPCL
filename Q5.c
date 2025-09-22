#include <stdio.h>
#include <omp.h>
int main() {
omp_set_num_threads(4); // Fix number of threads = 4
int val = 1234; // Shared variable outside the region
printf("Outside parallel region: val = %d\n", val);
#pragma omp parallel firstprivate(val)
{
int tid = omp_get_thread_num();
printf("Thread %d: initial val = %d\n", tid, val);
val++;
printf("Thread %d: updated val = %d\n", tid, val);
}
printf("Outside parallel region after parallel block: val = %d\n", val);
return 0;
}