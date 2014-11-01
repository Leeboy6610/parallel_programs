#include </Developer/NVIDIA/CUDA-6.5/include/cuda.h>
#include </Developer/NVIDIA/CUDA-6.5/include/cuda_runtime.h>
#include </Developer/NVIDIA/CUDA-6.5/include/device_launch_parameters.h>
#include <stdio.h>

// Kernel definition
__global__ void MatAdd(float a[N][N], float b[N][N], float c[N][N]) {
    int i = threadIdx.x;
    int j = threadIdx.y;
    c[i][j] = a[i][j] + b[i][j];
}
 
int main() {
    float a[N][N];
    float b[N][N];
    float c[N][N];

    int *dev_a = 0;
    int *dev_b = 0;
    int *dev_c = 0;

    float (*d_A)[N]; //pointers to arrays of dimension N
    float (*d_B)[N];
    float (*d_C)[N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j] = i;
            b[i][j] = j;
        }
    }

    // Kernel invocation with one block of N * N * 1 threads
    int numBlocks = 1;
    dim3 threadsPerBlock(N, N);
    MatAdd<<<numBlocks, threadsPerBlock>>>(a, b, c);

    //allocation
    cudaMalloc((void**)&d_A, (N*N)*sizeof(float));
    cudaMalloc((void**)&d_B, (N*N)*sizeof(float));
    cudaMalloc((void**)&d_C, (N*N)*sizeof(float));
}