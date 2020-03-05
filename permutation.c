#include <string.h>
#include <stdlib.h>
#include "mat.h"
#define nPn(n) {int i=1; int f=n; n=1; for (; f>0; --f) n*=f;}
#define swap(a, b, type) {type c; c=a; a=b; b=c;}
static int counter = 1;

double* determinant(double** m)
{
    int a[2];
    rowcol(a, m, "double");
    int l = a[1], L = a[0];
    if ((l = a[0]) != a[1] || l == 0)
    {
        printf("정사각행렬이 아니므로 역행렬을 구할 수 없습니다.");
        return 0;
    }
    nPn(l);

    double** m2 = malloc(L * sizeof(double*));
    if (m2 == NULL) exit(0);
    int i = 0, j = 0;
    for (; i < L; i++)
    {
        m2[i] = malloc(L * sizeof(double));
        for (j = 0; j < L; j++) m2[i][j] = m[i][j];
    }

    char* permstring = (char*)calloc(l * L + 1, sizeof(char));

    int* P = (int*)malloc(sizeof(int) * (L + 1));
    {
        int j = 0;
        for (; j <= L; ++j)
            P[j] = j;
    }
    
    char* tempBuffer = (char*)calloc(L + 1, sizeof(char));
    {
        int j = 0;
        for (; j < L; j++)
            tempBuffer[j] = 48 + j + 1;
    }

    char* initstr = (char*)malloc((L + 1) * sizeof(char));
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

    for (i = 0; i < l; i++)
    {
        int dif = -1;
        for (j = 0; j < L; j++) if (initstr[j] ^ permstring[3 * i + j]) dif++;
        double n = 1;
        for (j = 0; j < L; j++)
            n *= m2[j][(int)permstring[3 * i + j] - 49];
        for (j = 0; j < dif; j++) n *= -1;
        det += n;
    }
    double Det[1] = det;
    return Det;
}