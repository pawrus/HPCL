#include <stdio.h>
#include <omp.h>
int main() 
{
    int N = 20;
    int CHUNK = 3;
    omp_set_num_threads(4); 
    printf("Scheduling loop statically with CHUNK = %d\n", CHUNK);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        
        #pragma omp for schedule(static, CHUNK)
        for (int i = 0; i < N; i++) 
        {
            printf("Thread %d is processing iteration %d\n", tid, i);
        }
    }
    return 0;
}