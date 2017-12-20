/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <cuda_runtime.h>
#include <math.h>
#include <iostream>

#define TARGET 1000
#define MAXTHREADS 256

using namespace std;

__global__ void sumMultiples(long load, long *dest);

int main() {

	double load = ceil(sqrt(TARGET));
	double totalthreads = ceil(TARGET / load);
	long blocks = ceil(totalthreads / MAXTHREADS);
	int threadsperblock = (totalthreads > MAXTHREADS) ? totalthreads / blocks : totalthreads;

	long *hostdest = new long[blocks];
	long *devdest;
	cudaMalloc(&devdest, blocks * sizeof(long));
	cudaMemset(devdest, 0, blocks * sizeof(long));

	cout << "Load per thread: " << load << endl;
	cout << "Total threads: " << totalthreads << endl;
	cout << "Blocks: " << blocks << endl;
	cout << "Threads per block: " << threadsperblock << endl;


	sumMultiples <<<blocks, threadsperblock, threadsperblock * sizeof(long)>>> ((long)load, devdest);

	cudaMemcpy(hostdest, devdest, blocks * sizeof(long), cudaMemcpyDeviceToHost);

	long sum = 0;
	for (int i = 0; i < blocks; ++i) {
		cout << hostdest[i] << endl;
		sum += hostdest[i];
	}

	cout << endl << "Sum: " << sum << endl;

	cudaFree(devdest);
	delete[] hostdest;
	return 0;
}


__global__ void sumMultiples(long load, long *dest) {


	extern __shared__ long sums[];
	__syncthreads();

	sums[threadIdx.x] = 0;
	long start = load * (blockIdx.x * blockDim.x + threadIdx.x);
	long end = start + load;
	for (int i = start; i < end && i < TARGET; ++i) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sums[threadIdx.x] += i;
		}
	}

	__syncthreads();

	if (threadIdx.x == 0) {
		for (int i = 0; i < blockDim.x; ++i) {
			dest[blockIdx.x] += sums[i];
		}
	}
}