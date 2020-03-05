#ifndef _INCLUDE_MAT_
#define _INCLUDE_MAT_

// ũ�� ������� �Է� �Լ�
char* input(void);

/*
int r: ������ ����� ��ũ��
int c: ������ ����� ��ũ��
���: ���� �Է¹޾� ������ ����� ��ȯ
*/
double** inmat(int r, int c);

/*
double **m: ����� ���
���: ��� ���
*/
void outmat(double** m);

/*
int *l: ��ũ��, ��ũ�⸦ ���� �迭
double **m: Ȯ���� ���
char* type: ����� �ڷ���
���: ��ũ��� ��ũ�⸦ ���
*/
void rowcol(int* l, double** m, char* type);

/*
int s: ��������� ũ��
���: ������� ��ȯ
*/
double** IDmat(int s);

/*
double** m1: ��� A
double** m2: ��� B
���: AxB=C�� ��� C�� ��ȯ
*/
double** matmul(double** m1, double** m2);

/*
double** m1: ��� A
double** m2: ��� B
���: A+B=C�� ��� C�� ��ȯ
*/
double** matsum(double** m1, double** m2);

/*
double** m1: ��� A
double** m2: ��� B
���: A-B=C�� ��� C�� ��ȯ
*/
double** matsub(double** m1, double** m2);

/*
double** m1: ��� A
���: A�� ������� ��ȯ
����: ���콺�ҰŹ��� �����.
*/
double** revmat(double** m1);

/*
double** m1: ��� A
double** m2: ��� B
���: AxC=B�� ��� C�� ��ȯ
*/
double** matdiv(double** m1, double** m2);

/*
double** m1: ��� A
���: A�� ��ġ����� ��ȯ
*/
double** transpose(double** m1);

/*
double** m1: ��� A
���: A�� �밢���� ���� ũ�� 1�� �迭�� ��ȯ
*/
double** trace(double** m1);

/*
double** m1: ��� A
���: A�� ��Ľ��� ��ȯ
*/
double** determinant(double** m1);

/*
double** m1: ��� A
int n0: ��
int n1: ��
���: A�� n0�� n1�������� ������� ��ȯ
*/
double** minor(double** m1, int n0, int n1);

/*
double** m1: ��� A
���: A�� ��������� ��ȯ
*/
double** adj(double** m1);

/*
double** m1: ��� A
���: A�� ������� ��ȯ
����: https://namu.wiki/w/%ED%96%89%EB%A0%AC%EC%8B%9D#toc
*/
double** invmat(double** m1);

/*
double** m1: ��� A
double n: �¼�
���: A�� n�� ��Į����Ͽ� ��ȯ
*/
double** scalamul(double** m1, double n);

/*
double** m1: ��� A
double n: ����
���: A�� n�� ��Į�󳪴����Ͽ� ��ȯ
*/
double** scaladiv(double** m1, double n);

/*
double** m1: ��� A
double n: ������
���: A�� n�����Ͽ� ��ȯ
*/
double** powermat(double** m1, int n);

/*
���: ��� ���
*/
double** calc();

/*
���: �ƹ�Ű�� ������ ���α׷� ����
*/
void halt();

#endif _INCLUDE_MAT_
