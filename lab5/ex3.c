#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int blockSize=100; 

 
void BMMultiply(int n, double** a, double** b, double** c)
{
    int bi=0;
    int bj=0;
    int bk=0;
    int i=0;
    int j=0;
    int k=0;
 
    for(bi=0; bi<n; bi+=blockSize)
        for(bj=0; bj<n; bj+=blockSize)
            for(bk=0; bk<n; bk+=blockSize)
                for(i=0; i<blockSize; i++)
                    for(j=0; j<blockSize; j++)
                        for(k=0; k<blockSize; k++)
                            c[bi+i][bj+j] += a[bi+i][bk+k]*b[bk+k][bj+j];
}
 
int main(void)
{
    int n;
    double** A;
    double** B;
    double** C;
    int numreps = 10;
    int i=0;
    int j=0;
    struct timeval tv1, tv2;
    //struct timezone tz;
    double elapsed;
    
    // TODO: set matrix dimension n
    n = 1200;
    // allocate memory for the matrices
 
    double* a = malloc(n * n * sizeof(double));
    double* b = malloc(n * n * sizeof(double));
    double* c = malloc(n * n * sizeof(double));
    if(!a || !b || !c)
        exit(EXIT_FAILURE);

    A = malloc(n * sizeof(double**));
    B = malloc(n * sizeof(double**));
    C = malloc(n * sizeof(double**));

    if (!A || !B || !C) {
        free(a);
        free(b);
        free(c);
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++) {
        A[i] = &a[n * i];
        B[i] = &b[n * i];
        C[i] = &c[n * i];
    }
	
    // Initialize matrices A & B
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            A[i][j] = 1;
            B[i][j] = 2;
        }
    }
 
    // multiply matrices
 
    printf("Multiply matrices %d times for blocksize = %d...\n", numreps, blockSize);
    for (i=0; i<numreps; i++)
    {
        gettimeofday(&tv1, NULL);
        BMMultiply(n,A,B,C);
        gettimeofday(&tv2, NULL);
        elapsed += (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    }
    printf("Time = %lf \n",elapsed);
 
    // deallocate memory for matrices A, B & C
    free(A);
    free(B);
    free(C);
 
    free(a);
    free(b);
    free(c);   

    return 0;
}
