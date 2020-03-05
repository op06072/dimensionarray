#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mat.h"

double** calc()
{
    int R, C, i;
    printf("����� ��� ���� ũ�⸦ ��ǥ�� �����Ͽ� �Է����ּ���.\n");
    scanf("%d,%d", &R, &C);
    while (R < 1 || C < 1)
    {
        printf("�߸� �Է��ϼ̽��ϴ�. ���� ũ�⳪ ���� ũ��� 0���� ū ���������մϴ�.");
        scanf("%d,%d", &R, &C);
    }
    double** m1 = inmat(R, C);
    char* oneop = "-1Tdetr*^%", * twoop = "+-x/";
    system("cls");
    for (i = 0; i < C - 1; i++) printf("\t");
    printf("��� A\n");
    outmat(m1);
    printf("\n�Ʒ��� ������ �� ���ϴ� ������ �����ڸ� �Է��ϼ���.\n");
    printf("\n����� ������\n");
    printf("(-1: �����, T: ��ġ, det: ��Ľ�, tr: �밢��, ^: �ŵ�����, *: ��Į��� ���ϱ�, %%: ��Į��� ������)\n");
    printf("\n2��� ������\n");
    printf("( +: ��İ� ���ϱ�, -: ��İ� ����, *: ��İ� ���ϱ�, %: ��İ� ������)\n");
    //for (i = 0; i < strlen(twoop); i++) printf(", %c", twoop[i]);
    //printf(")\n");
    char* op = input();
    while (strlen(op) < 1)
    {
        printf("�����ڸ� �Է��ؾ� �մϴ�!\n");
        printf("\n�Ʒ��� ������ �� ���ϴ� ������ �����ڸ� �Է��ϼ���.\n");
        printf("\n����� ������\n");
        printf("(-1: �����, T: ��ġ, det: ��Ľ�, tr: �밢��, ^: �ŵ�����, *: ��Į��� ���ϱ�, %%: ��Į��� ������)\n");
        printf("\n2��� ������\n");
        printf("( +: ��İ� ���ϱ�, -: ��İ� ����, *: ��İ� ���ϱ�, %: ��İ� ������)\n");
        //for (i = 0; i < strlen(twoop); i++) printf(", %c", twoop[i]);
        //printf(")\n");
        op = input();
    }
    system("cls");
    for (i = 0; i < C - 1; i++) printf("\t");
    printf("��� A\n");
    outmat(m1);
    printf("\n");
    for (i = 0; i < C - 1; i++) printf("\t");
    printf("��� A %s ", op);
    if (strstr(twoop, op) != NULL)
    {
        system("cls");
        printf("�ι�° ����� ��� ���� ũ�⸦ ��ǥ�� �����Ͽ� �Է����ּ���.\n");
        int c = C - 1;
        scanf("%d,%d", &R, &C);
        while (R < 1 || C < 1)
        {
            printf("�߸� �Է��ϼ̽��ϴ�. ���� ũ�⳪ ���� ũ��� 0���� ū ���������մϴ�.");
            scanf("%d,%d", &R, &C);
        }
        double** m2 = inmat(R, C);
        system("cls");
        for (i = 0; i < c; i++) printf("\t");
        printf("��� A\n");
        outmat(m1);
        printf("\n");
        for (i = 0; i < C - 1; i++) printf("\t");
        printf("��� B\n");
        outmat(m2);
        printf("\n");
        for (i = 0; i < (c + C - 1) / 2; i++) printf("\t");
        printf("��� A %c ��� B\n", op[0]);
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
        printf("�����ڸ� �߸� �Է��ϼ̽��ϴ�.");
        halt();
    }
}