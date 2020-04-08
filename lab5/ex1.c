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
    // initializarea matricelor a si b
    for (i = 0 ; i < N; i++){
        for (j = 0; j < N; j++){
            a[i][j] = i;
            b[i][j] = j;
            c[i][j] = 0;
        }
    }

    /* classic mode */
    gettimeofday(&start, NULL);
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            c[i][j] = 0.0;
            for (k=0;k<N;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("Classic mode: = %lf \n",elapsed);

    for (i = 0 ; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = 0;

    /*Detectarea constantelor din bucle*/
    gettimeofday(&start, NULL);
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            register double suma = 0.0;
            for (k=0;k<N;k++) {
                suma += a[i][k] * b[k][j];
            }
            c[i][j] = suma;
        }
    }
    gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("Detectarea constantelor din bucle: = %lf \n",elapsed);
    

    for (i = 0 ; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = 0;



    //Accesul la vectori
    gettimeofday(&start, NULL);
    for(i = 0; i < N; i++){
        double *orig_pa = &a[i][0];
        for(j = 0; j < N; j++){
            double *pa = orig_pa;
            double *pb = &b[0][j];
            register double suma = 0;
            for(k = 0; k < N; k++){
                suma += *pa * *pb;
                pa++;
                pb += N;
            }
            c[i][j] = suma;
        }
    }
    gettimeofday(&end, NULL);
    elapsed = (double) (end.tv_sec-start.tv_sec) + (double) (end.tv_usec-start.tv_usec) * 1.e-6;
    printf("Accesul la vectori: = %lf \n",elapsed);
    
    
    return 0;
}