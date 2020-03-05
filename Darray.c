#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mat.h"

int main()
{
    //double **M1=inmat(2,2), **M2=inmat(2,3), **M3=matmul(M1, M2);
    ////double* m;
    ////m = (double *)malloc(c * sizeof(double));
    ///*mat[0] = (double*)malloc(sizeof(double) * c * r);
    //for (int i = 1; i < r; i++)
    //    mat[i] = mat[i - 1] + c;*/
    ////printf("%d", _msize(m)/sizeof(double));
    ////printf("%d", _msize(mat)/sizeof(double *));
    //system("cls");
    //printf("\t행렬 A\n");
    //outmat(M1);
    //printf("\t행렬 B\n");
    //outmat(M2);
    //if (M3 != 0)
    //{
    //    printf("\t행렬 A x 행렬 B\n");
    //    outmat(M3);
    //}
    double** m3 = calc();
    outmat(m3);
    halt();
}

void halt()
{
    printf("\n\n프로그램을 종료시키려면 아무키나 누르세요.\n");
    _getch();
    exit(0);
}