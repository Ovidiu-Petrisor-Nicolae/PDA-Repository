
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>



__global__ void Compute_Path(int *Md, const int Width, const int k)
{
	//2 Thread ID
	int ROW = blockIdx.x;
	int COL = threadIdx.x;


	if (Md[ROW * Width + COL] > Md[ROW * Width + k] + Md[k * Width + COL])
		Md[ROW * Width + COL] = Md[ROW * Width + k] + Md[k * Width + COL];
}

void addWithCuda(int *c, int size);
int main()
{
	int d;
	int a[36] = {	0, 2, 5, 999, 999, 999, 
					999, 0, 7, 1, 999, 8,
					999, 999, 0, 4, 999, 999,
					999, 999, 999, 0, 3, 999,
					999, 999, 2, 999, 0, 3,
					999, 5, 999, 2, 4, 0
				};

	// Add vectors in parallel.
	addWithCuda(a, 6);


	for (int i = 0; i < 36; i++)
		printf("%d ", a[i]);
		
		

		

	
	scanf("%d",&d);

	return 0;
} 

// Helper function for using CUDA to add vectors in parallel.
void addWithCuda(int *c, int Width)
{
	int *dev_c;
	int size = Width*Width * sizeof(int);
	// Choose which GPU to run on, change this on a multi-GPU system.
	
	

	// Allocate GPU buffers for three vectors (two input, one output)    .
	cudaMalloc((void**)&dev_c, size * sizeof(int));
	

	

	// Copy input vectors from host memory to GPU buffers.
	cudaMemcpy(dev_c, c, size * sizeof(int), cudaMemcpyHostToDevice);
	

	// Launch a kernel on the GPU with one thread for each element.
	for (int k = 0; k < 6; k++)
		Compute_Path << <Width, Width >> >(dev_c, Width,k);

	

	// Copy output vector from GPU buffer to host memory.
	cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);


	cudaFree(dev_c);
}
