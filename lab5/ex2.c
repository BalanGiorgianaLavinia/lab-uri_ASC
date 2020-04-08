#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int N = 1200;
    int i,j,k;
    struct timeval start, end;
    double elapsed = 0;

    double a[N][N], b[N][N], c[N][N];

    for (i = 0 ; i < N; i++){
        for (j = 0; j < N; j++){
            a[i][j] = i;
            b[i][j] = j;
            c[i][j] = 0;
        }
    }



    //////////////* i-j-k *////////////////////
    gettimeofday(&start, NULL);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) 
			for (k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];

	gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("i-j-k: = %lf \n",elapsed);

    for (i = 0 ; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = 0;


    ////////////////* i-k-j *////////////////////
    gettimeofday(&start, NULL);
	for (i = 0; i < N; i++)
		for (k = 0; k < N; k++) 
        	for (j = 0; j < N; j++)
				c[i][j] += a[i][k] * b[k][j];
                
	gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("i-k-j: = %lf \n",elapsed);

    for (i = 0 ; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = 0;



    ////////////////* j-i-k *////////////////////
    gettimeofday(&start, NULL);
	for (j = 0; j < N; j++)
		for (i = 0; i < N; i++)
            for (k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];

	gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("j-i-k: = %lf \n",elapsed);

    for (i = 0 ; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = 0;        



    ////////////////* j-k-i *////////////////////
    gettimeofday(&start, NULL);
	for (j = 0; j < N; j++)
		for (k = 0; k < N; k++)
			for (i = 0; i < N; i++)
				c[i][j] += a[i][k] * b[k][j];

	gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("j-k-i: = %lf \n",elapsed);

    for (i = 0 ; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = 0;   



    ////////////////* k-i-j *////////////////////
    gettimeofday(&start, NULL);
	for (k = 0; k < N; k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				c[i][j] += a[i][k] * b[k][j];
	
	gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("k-i-j: = %lf \n",elapsed);

    for (i = 0 ; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = 0;   



    ////////////////* k-j-i *////////////////////
    gettimeofday(&start, NULL);
	for (k = 0; k < N; k++)
		for (j = 0; j < N; j++)
			for (i = 0; i < N; i++)
				c[i][j] += a[i][k] * b[k][j];

	gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("k-j-i: = %lf \n",elapsed);

    return 0;
}