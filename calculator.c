#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mat.h"

double** calc()
{
    int R, C, i;
    printf("행렬의 행과 열의 크기를 쉼표로 구분하여 입력해주세요.\n");
    scanf("%d,%d", &R, &C);
    while (R < 1 || C < 1)
    {
        printf("잘못 입력하셨습니다. 행의 크기나 열의 크기는 0보다 큰 정수여야합니다.");
        scanf("%d,%d", &R, &C);
    }
    double** m1 = inmat(R, C);
    char* oneop = "-1Tdetr*^%", * twoop = "+-x/";
    system("cls");
    for (i = 0; i < C - 1; i++) printf("\t");
    printf("행렬 A\n");
    outmat(m1);
    printf("\n아래의 연산자 중 원하는 연산의 연산자를 입력하세요.\n");
    printf("\n단행렬 연산자\n");
    printf("(-1: 역행렬, T: 전치, det: 행렬식, tr: 대각합, ^: 거듭제곱, *: 스칼라로 곱하기, %%: 스칼라로 나누기)\n");
    printf("\n2행렬 연산자\n");
    printf("( +: 행렬간 더하기, -: 행렬간 빼기, *: 행렬간 곱하기, %: 행렬간 나누기)\n");
    //for (i = 0; i < strlen(twoop); i++) printf(", %c", twoop[i]);
    //printf(")\n");
    char* op = input();
    while (strlen(op) < 1)
    {
        printf("연산자를 입력해야 합니다!\n");
        printf("\n아래의 연산자 중 원하는 연산의 연산자를 입력하세요.\n");
        printf("\n단행렬 연산자\n");
        printf("(-1: 역행렬, T: 전치, det: 행렬식, tr: 대각합, ^: 거듭제곱, *: 스칼라로 곱하기, %%: 스칼라로 나누기)\n");
        printf("\n2행렬 연산자\n");
        printf("( +: 행렬간 더하기, -: 행렬간 빼기, *: 행렬간 곱하기, %: 행렬간 나누기)\n");
        //for (i = 0; i < strlen(twoop); i++) printf(", %c", twoop[i]);
        //printf(")\n");
        op = input();
    }
    system("cls");
    for (i = 0; i < C - 1; i++) printf("\t");
    printf("행렬 A\n");
    outmat(m1);
    printf("\n");
    for (i = 0; i < C - 1; i++) printf("\t");
    printf("행렬 A %s ", op);
    if (strstr(twoop, op) != NULL)
    {
        system("cls");
        printf("두번째 행렬의 행과 열의 크기를 쉼표로 구분하여 입력해주세요.\n");
        int c = C - 1;
        scanf("%d,%d", &R, &C);
        while (R < 1 || C < 1)
        {
            printf("잘못 입력하셨습니다. 행의 크기나 열의 크기는 0보다 큰 정수여야합니다.");
            scanf("%d,%d", &R, &C);
        }
        double** m2 = inmat(R, C);
        system("cls");
        for (i = 0; i < c; i++) printf("\t");
        printf("행렬 A\n");
        outmat(m1);
        printf("\n");
        for (i = 0; i < C - 1; i++) printf("\t");
        printf("행렬 B\n");
        outmat(m2);
        printf("\n");
        for (i = 0; i < (c + C - 1) / 2; i++) printf("\t");
        printf("행렬 A %c 행렬 B\n", op[0]);
        switch ((int)op[0]) {
        case 0x2B:
            return matsum(m1, m2);
            break;
        case 0x2D:
            return matsub(m1, m2);
            break;
        case 0x78:
            return matmul(m1, m2);
            break;
        case 0x2F:
            return matdiv(m1, m2);
            break;
        }
    }
    else if (!strcmp(op, "-1"))
    {
        printf("\n");
        return invmat(m1);
    }
    else if (!strcmp(op, "T"))
    {
        printf("\n");
        return transpose(m1);
    }
    else if (!strcmp(op, "det"))
    {
        printf("\n");
        return determinant(m1);
    }
    else if (!strcmp(op, "tr"))
    {
        printf("\n");
        return trace(m1);
    }
    else if (!strcmp(op, "*"))
    {
        char* n = input();
        printf("\n", n);
        return scalamul(m1, atof(n));
    }
    else if (!strcmp(op, "^"))
    {
        char* n = input();
        printf("\n", n);
        return powermat(m1, atoi(n));
    }
    else if (!strcmp(op, "%"))
    {
        char* n = input();
        printf("\n", n);
        return scaladiv(m1, atof(n));
    }
    else
    {
        printf("연산자를 잘못 입력하셨습니다.");
        halt();
    }
}