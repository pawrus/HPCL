#include <stdio.h>
#include <omp.h>

int main()
{
	int n = 10;
	// force OpemMP to use exactly 2 threads
	omp_set_num_threads(2);

	#pragma omp parallel
	{
		int tid = omp_get_thread_num();

		if(tid == 0)
		{
			printf("Series 2 Thread %d: ", tid);
			for(int i = 0; i < n; i++)
			{
				printf("%d ", 2 * i);
			}
			printf("\n");
		}
		else if(tid == 1)
		{
			printf("Series 4 Thread %d: ", tid);
			for(int i = 0; i < n; i++)
			{
				printf("%d ", 4 * i);
			}
			printf("\n");
		}
	}
	return 0;
}