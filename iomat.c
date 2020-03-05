#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mat.h"

int deci(double n)
{
    int b0, b = 0;
    b0 = (int)n;
    do { b++; } while (b0 /= 10);
    return b;
}

void outmat(double** m)
{
    //int row = _msize(m) / sizeof(double*), col = _msize(m[0]) / sizeof(double), i, j;
    int rc[2] = { 0 };
    rowcol(rc, m, "double");
    int row = rc[0], col = rc[1], i, j, k, length = 4 * (row - 1), l, L, n, b0, b = 0;
    double B = 0;
    for (i = 0; i < row; i++) for (j = 0; j < col; j++) if (fabs(m[i][j]) > B) B = fabs(m[i][j]);
    b = deci(B);

    if (row ^ 1) for (i = 0; i < row; i++)
    {
        n = 0;
        for (j = 0; j < col; j++) if (m[i][j] >= 0) n++;
        l = length + n;
        L = l / row;
        printf(i ^ 0 ? i ^ (row - 1) ? "┃" : "┗" : "┏");
        for (j = 0; j < col; j++)
        {
            if (j == 0) printf("  ");
            /*
            else if (l > L)
            {
                //for (k = 0; k < L; k++) printf(" ");
                printf("\t");
                l -= L;
            }
            else for (k = 0; k < l; k++) printf(" ");
            */
            else printf("    ");
            //char* blank = malloc(b * sizeof(char));
            //for (k = 0; k < b; k++) blank[k] = " ";
            if (b <= 5)
            {
                if (m[i][j] != 0)
                {
                    if (deci(fabs(m[i][j])) < b)
                    {
                        if (m[i][j] > 0) printf("%9.8lf", m[i][j]);
                        else printf("%9.7lf", m[i][j]);
                    }
                    else
                    {
                        if (m[i][j] > 0) printf("%9.7lf", m[i][j]);
                        else printf("%9.6lf", m[i][j]);
                    }
                }
                else printf("%.*lf", 6 + b, 0);
            }
            else printf("%e", m[i][j]);
        } //printf("\t%lf%s", m[i][j], (j != col - 1) ? " " : "\n");
        printf(i ^ 0 ? i ^ (row - 1) ? " ┃" : " ┛" : " ┓");
        printf("\n");
    }
    else
    {
        printf("┃");
        double* m0 = m[0];
        for (j = 0; j < col; j++)
        {
            if (j == 0) printf("  ");
            else printf("    ");
            if (b <= 5)
            {
                if (m0[j] != 0)
                {
                    printf("%lf", m0[j]);
                }
                else printf("%lf", 0);
            }
            else printf("%e", m0[j]);
        }
        printf(" ┃");
        printf("\n");
    }
}

double** inmat(int r, int c)
{
    //int row = _msize(m)/sizeof(double *), col = _msize(m[0])/sizeof(double), i, j;
    int i, j, k;
    //printf("행렬의 행과 열의 크기를 쉼표로 구분하여 입력해주세요.\n");
    //scanf("%d, %d", &r, &c);
    //printf("\n");
    double** mat = malloc(r * sizeof(double*));
    for (i = 0; i < r; i++) mat[i] = calloc(c, sizeof(double));
    //int *rc = rowcol(mat, "double"), row = rc[0], col = rc[1];
    for (i = 0; i < r; i++) for (j = 0; j < c; )
    {
        system("cls");
        for (k = 0; k < c - 1; k++) printf("\t");
        printf("입력 행렬\n");
        outmat(mat);
        printf("\n행렬의 %d번째 행 %d번째 열의 원소를 입력해주세요.\n(wasd를 이용해 원하는 입력위치로 이동할 수 있습니다. 입력없이 엔터를 누를 시 다음 칸으로 이동합니다.)\n", i + 1, j + 1);
        char* key = input();
        if (strlen(key) == 0)
        {
            j++;
            continue;
        }
        switch ((int)key[0]) {
        case 0x57:
        case 0x77:
            if (i ^ 0) i--;
            else i = r - 1;
            break;
        case 0x41:
        case 0x61:
            if (j ^ 0) j--;
            else j = c - 1;
            break;
        case 0x53:
        case 0x73:
            if (i ^ (r-1)) i++;
            else i = -1;
            break;
        case 0x44:
        case 0x64:
            if (j ^ (c-1)) j++;
            else j = 0;
            break;
        default:
            mat[i][j] = atof(key);
            j++;
        }
        //scanf("%lf", &mat[i][j]);
        system("cls");
        for (k = 0; k < c - 1; k++) printf("\t");
        printf("입력 행렬\n");
        outmat(mat);
        if (i == (r - 1) && j == c)
        {
            printf("\n행렬을 다 채우셨습니까? (Y/N)");
            switch ((int)input()) {
            case 0x59:
            case 0x79:
                break;
            default:
                i == 0;
                j == 0;
            }
        }
    }
    printf("\n");
    return mat;
}