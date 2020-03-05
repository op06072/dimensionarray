#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mat.h"

#define nPn(n) {int i=1; int f=n; n=1; for (; f>0; --f) n*=f;}
#define swap(a, b, type) {type c; c=a; a=b; b=c;}
static int counter = 1;

double** matmul(double** m1, double** m2)
{
    int a[2] = { 0 }, b[2] = { 0 }, i, j, k, l, s, S;
    rowcol(a, m1, "double");
    rowcol(b, m2, "double");
    if ((l=a[1]) != b[0] || (s=a[0])*l*(S=b[1]) == 0 )
    {
        printf("이 계산은 수행되어질 수 없습니다!");
        halt();
    }
    double** M = malloc(s * sizeof(double*));
    if (M == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    for (i = 0; i < s; i++)
    {
        M[i] = calloc(S, sizeof(double));
        if (M[i] == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
    }
    for (i = 0; i < s; i++) for (j = 0; j < S; j++) for (k = 0; k < l; k++) M[i][j] += m1[i][k] * m2[k][j];
    return M;
}

double** matsum(double** m1, double** m2)
{
    int a[2] = {0}, b[2] = {0}, i, j, s, S;
    rowcol(a, m1, "double");
    rowcol(b, m2, "double");
    if ((s = a[0]) != b[0] || (S=a[1]) != b[1] || s*S == 0)
    {
        printf("이 계산은 수행되어질 수 없습니다!");
        halt();
    }
    double** M = malloc(s * sizeof(double*));
    if (M == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    for (i = 0; i < s; i++)
    {
        M[i] = calloc(S, sizeof(double));
        if (M[i] == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
    }
    for (i = 0; i < s; i++) for (j = 0; j < S; j++) M[i][j] = m1[i][j] + m2[i][j];
    return M;
}

double** matsub(double** m1, double** m2)
{
    int a[2] = {0}, b[2] = {0}, i, j, s, S;
    rowcol(a, m1, "double");
    rowcol(b, m2, "double");
    if ((s = a[0]) != b[0] || (S = a[1]) != b[1] || s * S == 0)
    {
        printf("이 계산은 수행되어질 수 없습니다!");
        halt();
    }
    double** M = malloc(s * sizeof(double*));
    if (M == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    for (i = 0; i < s; i++)
    {
        M[i] = calloc(S, sizeof(double));
        if (M[i] == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
    }
    for (i = 0; i < s; i++) for (j = 0; j < S; j++) M[i][j] = m1[i][j] - m2[i][j];
    return M;
}

double** transpose(double** m1)
{
    int a[2] = {0}, r, c, i, j;
    rowcol(a, m1, "double");
    double** M = malloc((r = a[1]) * sizeof(double*));
    if (M == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    for (i = 0; i < r; i++)
    {
        M[i] = malloc((c = a[0]) * sizeof(double));
        if (M[i] == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
        for (j = 0; j < c; j++) M[i][j] = m1[j][i];
    }
    return M;
}

double **trace(double** m1)
{
    int i, tr = 0, a[2] = {0}, l;
    double **rt = malloc(sizeof(double*));
    if (rt == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    rowcol(a, m1, "double");
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 대각합을 구할 수 없습니다.");
        halt();
    }
    for (i = 0; i < l; i++) tr += m1[i][i];
    rt[0] = malloc(sizeof(double));
    if (rt[0] == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    rt[0][0] = tr;
    return rt;
}

double** scalamul(double** m1, double n)
{
    int a[2];
    rowcol(a, m1, "double");
    int l = a[1], L = a[0], i = 0, j = 0;
    for (; i < L; i++)
    {
        for (j = 0; j < l; j++) m1[i][j] *= n;
    }
    return m1;
}

double** scaladiv(double** m1, double n)
{
    int a[2];
    rowcol(a, m1, "double");
    int l = a[1], L = a[0], i = 0, j = 0;
    for (; i < L; i++)
    {
        for (j = 0; j < l; j++) m1[i][j] /= n;
    }
    return m1;
}

double **determinant(double** m1)
{
    int a[2];
    rowcol(a, m1, "double");
    int l = a[1], L = a[0];
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 행렬식을 구할 수 없습니다.");
        halt();
    }
    nPn(l);

    double** m2 = malloc(L * sizeof(double*));
    if (m2 == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    int i = 0, j = 0;
    for (; i < L; i++)
    {
        m2[i] = malloc(L * sizeof(double));
        if (m2[i] == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
        for (j = 0; j < L; j++) m2[i][j] = m1[i][j];
    }

    char* permstring = (char*)calloc(l * L + 1, sizeof(char));
    if (permstring == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    int* P = (int*)malloc(sizeof(int) * (L + 1));
    if (P == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    {
        int j = 0;
        for (; j <= L; ++j)
            P[j] = j;
    }

    char* tempBuffer = (char*)calloc(L + 1, sizeof(char));
    if (tempBuffer == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    {
        int j = 0;
        for (; j < L; j++)
            tempBuffer[j] = 48 + j + 1;
    }

    char* initstr = (char*)malloc((L + 1) * sizeof(char));
    if (initstr == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    strcpy(initstr, tempBuffer);
    strcat(permstring, tempBuffer);

    i = 1, j = 0;
    while (i < L)
    {
        P[i]--;
        j = i % 2 * P[i];
        swap(tempBuffer[i], tempBuffer[j], char);
        counter++;
        strcat(permstring, tempBuffer);

        i = 1;
        while (!P[i] && i <= L)
        {
            P[i] = i;
            i++;
        }
    }

    double det = 0;
    //outmat(m2);

    for (i = 0; i < l; i++)
    {
        int dif = 0, I = L * i, cmp = L, p = 0;
        char* cmpstr = malloc((L + 1) * sizeof(char));
        if (cmpstr == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
        strcpy(cmpstr, initstr);
        while (cmp)
        {
            while (cmpstr[p] ^ 48)
            {
                cmpstr[p] = 48;
                cmp--;
                p = (int)permstring[I + p] - 49;
                dif++;
            }
            for (j = 0; j < L; j++) if (cmpstr[j] ^ 48) 
            { 
                p = j;
                break;
            }
            dif--;
        }
        double n = 1;
        //printf("\n");
        for (j = 0; j < L; j++)
        {
            //printf("%d %d %lf\n", j + 1, (int)permstring[L * i + j] - 48, m2[j][(int)permstring[L * i + j] - 49]);
            n *= m2[j][(int)permstring[L * i + j] - 49];
        }
        //for (j = 0; j < dif; j++) n *= -1;
        //printf("%lf\n", n);
        det += n * pow(-1, dif);
    }
    double **Det = malloc(sizeof(double*));
    if (Det == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    Det[0] = malloc(sizeof(double*));
    if (Det[0] == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    Det[0][0] = det;
    //printf("det: %lf\n", det);
    return Det;
}
/*
double* betterdet(m1)
{
    int a[2] = { 0 }, l, i=0, j, k;
    double m;
    rowcol(a, m1, "double");
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 행렬식을 구할 수 없습니다.");
        exit(0);
    }

    double** m2 = malloc(l * sizeof(double*));
    if (m2 == NULL) exit(0);
    int i = 0, j = 0;
    for (; i < L; i++)
    {
        m2[i] = malloc(L * sizeof(double));
        for (j = 0; j < L; j++) m2[i][j] = m1[i][j];
    }

    for (; i < l-1; i++)
    {
        m = m2[i][i] / m2[i+1][i]
        for (j = i; j < l; j++)
        {
            for (k = i; k < l; k++)
            {

            }
        }
    }
}
*/
double** minor(double** m1, int n0, int n1)
{
    int a[2] = { 0 }, l;
    rowcol(a, m1, "double");
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 소행렬을 구할 수 없습니다.");
        halt();
    }

    double** m = malloc((l - 1) * sizeof(double*));
    if (m == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }

    int i = 0, j = 0, I = 0, J = 0;
    for (; i < l; i++)
    {
        if (i ^ n0)
        {
            m[I] = malloc((l - 1) * sizeof(double));
            if (m[I] == NULL)
            {
                printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
                halt();
            }
            for (j=0; j < l; j++) if (j ^ n1) m[I][J] = m1[i][j], J++;
            J = 0;
            I++;
        }
    }
    //printf("minor:\n");
    //outmat(m);
    return m;
}

double** adj(double** m1)
{
    int a[2] = { 0 } , l;
    rowcol(a, m1, "double");
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 수반행렬을 구할 수 없습니다.");
        halt();
    }

    double** m = malloc(l * sizeof(double*));
    if (m == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    int i = 0, j = 0;
    for (; i < l; i++)
    {
        m[i] = malloc(l * sizeof(double));
        if (m[i] == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
        for (j=0; j < l; j++)
            m[i][j] = determinant(minor(m1, i, j))[0][0] * pow(-1, i + j);
    }
    //outmat(m);
    //outmat(transpose(m));
    return transpose(m);
}

double** revmat(double** m1)
{
    int a[2] = { 0 }, l, i, j, k, p = 0;
    rowcol(a, m1, "double");
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 역행렬을 구할 수 없습니다.");
        halt();
    }
    double** m = malloc(l * sizeof(double*)), * z = calloc(l, sizeof(double)), ** id = IDmat(l), d;
    if (m == NULL || z == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    memcpy(m, m1, _msize(m1));
    /*for (i = 0; i < l; i++)
    {
        m[i] = malloc(l * sizeof(double));
        memcpy(m[i], m1[i], l);
    }*/
    for (i = 0; i < l - 1; i++)
    {
        if (memcmp(m[i], z, _msize(z)) == 0)
        {
            printf("이 정사각행렬은 역행렬을 갖고있지 않습니다.");
            halt();
        }
        for (j = i; j < l; j++) if (fabs(m[p][i]) < fabs(m[j][i])) p = j;
        swap(m[i], m[p], double*);
        swap(id[i], id[p], double*);
        for (j = i + 1; j < l; j++)
        {
            d = m[j][i] / m[i][i];
            for (k = l - 1; k > -1; k--)
            {
                m[j][k] -= d * m[i][k];
                id[j][k] -= d * id[i][k];
            }
        }
    }
    for (i = l - 1; i > -1; i--)for (j = 0; j < i; j++)
    {
        d = m[j][i] / m[i][i];
        m[j][i] -= d * m[i][i];
        id[j][i] -= d * id[i][i];
    }
    return id;
}

double** invmat(double** m1)
{
    int a[2];
    rowcol(a, m1, "double");
    int l = a[1], L = a[0];
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 역행렬을 구할 수 없습니다.");
        halt();
    }
    if (l * L == 1)
    {
        double** m = malloc(sizeof(double*));
        if (m == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
        m[0] = malloc(sizeof(double));
        m[0][0] = 1/m1[0][0];
        return m;
    }
    double det = determinant(m1)[0][0];
    if (!det)
    {
        printf("행렬식의 값이 0이므로 역행렬을 구할 수 없습니다.");
        halt();
    }
    return scaladiv(adj(m1), det);
}

double** matdiv(double** m1,double** m2)
{
    return matmul(invmat(m1), m2);
}

double** powermat(double** m1, int n)
{
    //행렬의 고유값이 필요하므로 구현중
    //대신 제곱할 수를 이진수로 변환하여 시간복잡도를 줄이는 방안으로 대체하겠음.
    //하지만 이 방법으로는 행렬의 제곱근은 계산하지 못함. 따라서 n을 int형으로 두고 계산하겠음.
    int a[2];
    rowcol(a, m1, "double");
    int l = a[1], L = a[0];
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 거듭제곱을 구할 수 없습니다.");
        halt();
    }

    double** m2 = malloc(L * sizeof(double*));
    if (m2 == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    int i = 0, j = 0;
    for (; i < L; i++)
    {
        m2[i] = malloc(L * sizeof(double));
        if (m2[i] == NULL)
        {
            printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
            halt();
        }
        for (j = 0; j < L; j++) m2[i][j] = m1[i][j];
    }

    int b = 1;
    l = 1;
    while (b < n)
    {
        b *= 2;
        l++;
    }
    if (b ^ n)
    {
        b /= 2;
        l--;
    }

    int* bit = calloc(l, sizeof(int));
    if (bit == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    for (i = 0; i < l; i++) if (b <= n)
    {
        bit[i] = 1;
        n -= b;
        b /= 2;
    }
    //for (i = 0; i < l; i++) printf("%d", bit[i]);
    for (j = 0; bit[j] ^ 1; j++);
    for (j++; j < l; j++)
    {
        m2 = matmul(m2, m2);
        if (bit[j]) m2 = matmul(m1, m2);
    }
    return m2;
}