#include <stdio.h>
#include <omp.h>
int main() 
{
	#pragma omp parallel
	{
		int tid = omp_get_thread_num(); // Thread ID
		int nthreads = omp_get_num_threads(); // Total number of threads
		printf("Hello world from thread %d out of %d threads\n", tid, nthreads);
	}
}