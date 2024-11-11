#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main() {
	printf("comecando");
	double init_time = omp_get_wtime();
	int n=80000;
	
	int vector[n];
	
	srand(time(NULL));

	for (int i =0; i<n; i++) {
		vector[i] = rand();
	}
	
	int num_procs = omp_get_num_procs();
	printf("Num_p: %d\n", num_procs);
	long long int sum_vector = 0;
	for (int j=0;j<n;j++){
		sum_vector = sum_vector + vector[j];
		

	}
	
	double end_time = omp_get_wtime();
	printf("Levou %f segundos para somar todos o indicies do vetor\n", end_time - init_time);
	printf("Soma total do vetor: %lld\n",sum_vector);
	return sum_vector;

}
