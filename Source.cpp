#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 1000     

bool isPrime(int number)
{
	if (number < 2)
		return 0;
	for (int i = 2; i * i <= number; ++i)
		if (number % i == 0)
			return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	int	processes, rank, start, step, numbers[NMAX], localNumbers[NMAX], j, k = 0;
	int *sub;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &processes);
	start = (rank * 2) + 1;
	step = processes * 2;
	j = 0;
	if (rank == 0)
		localNumbers[j++] = 2;
	for (int i = start; i <= NMAX; i += step)
		if (isPrime(i))
			localNumbers[j++] = i;
	if (rank == 0)
	{
		MPI_Gather(&localNumbers, j, MPI_INT, numbers, j, MPI_INT, 0, MPI_COMM_WORLD);
		for (int i = 0; i < j; ++i)
			printf("%d ", numbers[i]);
	}
	MPI_Finalize();
}