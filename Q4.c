#include <stdio.h>
#include <omp.h>
int main() 
{
	// Force 4 threads
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		printf("Hello, I am thread %d printing my NAME: Paras Zope\n", tid);
	}
}