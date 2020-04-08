#include <stdio.h>
#include "utils/utils.h"

// ~TODO 3~
// Modify the kernel below such as each element of the 
// array will be now equal to 0 if it is an even number
// or 1, if it is an odd number
__global__ void kernel_parity_id(int *a, int N) {
    unsigned int i = threadIdx.x + blockDim.x * blockIdx.x;

	if (i < N)
		a[i] %= 2;
}

// ~TODO 4~
// Modify the kernel below such as each element will
// be equal to the BLOCK ID this computation takes
// place.
__global__ void kernel_block_id(int *a, int N) {
    unsigned int i = threadIdx.x + blockDim.x * blockIdx.x;

	if (i < N)
		a[i] = blockIdx.x;
}

// ~TODO 5~
// Modify the kernel below such as each element will
// be equal to the THREAD ID this computation takes
// place.
__global__ void kernel_thread_id(int *a, int N) {
    unsigned int i = threadIdx.x + blockDim.x * blockIdx.x;

	if (i < N)
		a[i] = threadIdx.x;
}

int main(void) {
    int nDevices;
    cudaDeviceProp p;
    int *host_array;
    int *device_array;
    int n = 1 << 20;


    // Get the number of CUDA-capable GPU(s)
    cudaGetDeviceCount(&nDevices);

    // ~TODO 1~
    // For each device, show some details in the format below, 
    // then set as active device the first one (assuming there
    // is at least CUDA-capable device). Pay attention to the
    // type of the fields in the cudaDeviceProp structure.
    //
    // Device number: <i>
    //      Device name: <name>
    //      Total memory: <mem>
    //      Memory Clock Rate (KHz): <mcr>
    //      Memory Bus Width (bits): <mbw>
    // 
    // Hint: look for cudaGetDeviceProperties and cudaSetDevice in
    // the Cuda Toolkit Documentation. 
    for (int i = 0; i < nDevices; ++i) {
        cudaGetDeviceProperties(&p, i);
        printf("Device number: %d\n", i);
        printf("\tDevice name: %s\n", p.name);
        printf("\tTotal memory: %zu\n", p.totalGlobalMem);
        printf("\tMemory Clock Rate (KHz): %d\n", p.memoryClockRate);
        printf("\tMemory Bus Width (bits): %d\n", p.memoryBusWidth);
    }

    // ~TODO 2~
    // With information from example_2.cu, allocate an array with
    // integers (where a[i] = i). Then, modify the three kernels
    // above and execute them using 4 blocks, each with 4 threads.
    // Hint: num_elements = block_size * block_no (see example_2)
    //
    // You can use the fill_array_int(int *a, int n) function (from utils)
    // to fill your array as many times you want.

    host_array = (int *)malloc(n * sizeof(*host_array));

	cudaMalloc(&device_array, n * sizeof(*device_array));

	fill_array_int(host_array, n);

	cudaMemcpy(device_array, host_array, n * sizeof(*host_array), cudaMemcpyHostToDevice);

    // ~TODO 3~
    // Execute kernel_parity_id kernel and then copy from 
    // the device to the host; call cudaDeviceSynchronize()
    // after a kernel execution for safety purposes.
    //
    // Uncomment the line below to check your results
    kernel_parity_id<<<n / 4, 4>>>(device_array, n);

	cudaDeviceSynchronize();

	cudaMemcpy(host_array, device_array, n * sizeof(*host_array), cudaMemcpyDeviceToHost);

    check_task_1(3, host_array);

    // ~TODO 4~
    // Execute kernel_block_id kernel and then copy from 
    // the device to the host;
    //
    // Uncomment the line below to check your results
    kernel_block_id<<<n / 4, 4>>>(device_array, n);

	cudaDeviceSynchronize();

	cudaMemcpy(host_array, device_array, n * sizeof(*host_array), cudaMemcpyDeviceToHost);

    check_task_1(4, host_array);

    // ~TODO 5~
    // Execute kernel_thread_id kernel and then copy from 
    // the device to the host;
    //
    // Uncomment the line below to check your results
    kernel_thread_id<<<n / 4, 4>>>(device_array, n);

	cudaDeviceSynchronize();

	cudaMemcpy(host_array, device_array, n * sizeof(*host_array), cudaMemcpyDeviceToHost);

    check_task_1(5, host_array);

    // TODO 6: Free the memory
    free(host_array);
    cudaFree(device_array);
    

    return 0;
}
