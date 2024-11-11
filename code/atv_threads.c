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
	int part_size = n/num_procs;
	#pragma omp parallel for reduction(+:sum_vector)
	for (int i=0; i<num_procs; i++){
		
		int init = part_size * i;
		int end = (i==num_procs - 1)? n : init + part_size;
		long long int sum_part=0;
		
				
		printf("O thread %d esta calculando o array que inicia a %d e termina %d\n",omp_get_thread_num(), init, end);
		
		printf("Hello from thread %d\n", omp_get_thread_num());
		for (int j=init;j<end;j++){
			sum_vector = sum_vector + vector[j];
		

		}
		sum_vector += sum_part;
	
		printf("Part da soma feita pelo thread: %d foi de -> %lld\n",omp_get_thread_num(),sum_vector);
	}
	double end_time = omp_get_wtime();
	printf("Levou %f segundos para somar todos o indicies do vetor\n", end_time - init_time);
	printf("Soma total do vetor: %lld\n",sum_vector);
	return sum_vector;

}
