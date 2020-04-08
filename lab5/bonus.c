#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int blockSize=25; 

 
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
 
    ///////////////////// Matrix A //////////////////////////
    A = malloc(n * sizeof(*A));
    if (A == NULL)
        exit(EXIT_FAILURE);
 
    ///////////////////// Matrix B ////////////////////////// 
    B = malloc(n * sizeof(*B));
    if (B == NULL)
        exit(EXIT_FAILURE);
 
    ///////////////////// Matrix C //////////////////////////
    C = calloc(n, sizeof(*C));
    if (C == NULL)
        exit(EXIT_FAILURE);


    for (i = 0; i != n; ++i)
	{
		A[i] = malloc(n * sizeof(**A));
		B[i] = malloc(n * sizeof(**B));
		C[i] = calloc(n, sizeof(**C));

		for (j = 0; j != n; ++j)
		{
			A[i][j] = 1;
			B[i][j] = 2;
		}
	}        
 

    //multiply matrices
 
    printf("Multiply matrices %d times for blocksize = %d...\n", numreps, blockSize);
    for (i=0; i<numreps; i++)
    {
        gettimeofday(&tv1, NULL);
        BMMultiply(n,A,B,C);
        gettimeofday(&tv2, NULL);
        elapsed += (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    }
    printf("Time = %lf \n",elapsed);
 
    //deallocate memory for matrices A, B & C
    free(A);
    free(B);
    free(C);

    return 0;
}
