#ifndef _INCLUDE_MAT_
#define _INCLUDE_MAT_

// 크기 상관없는 입력 함수
char* input(void);

/*
int r: 생성될 행렬의 행크기
int c: 생성될 행렬의 열크기
결과: 값을 입력받아 생성된 행렬을 반환
*/
double** inmat(int r, int c);

/*
double **m: 출력할 행렬
결과: 행렬 출력
*/
void outmat(double** m);

/*
int *l: 행크기, 열크기를 받을 배열
double **m: 확인할 행렬
char* type: 행렬의 자료형
결과: 행크기와 열크기를 계산
*/
void rowcol(int* l, double** m, char* type);

/*
int s: 단위행렬의 크기
결과: 단위행렬 반환
*/
double** IDmat(int s);

/*
double** m1: 행렬 A
double** m2: 행렬 B
결과: AxB=C인 행렬 C를 반환
*/
double** matmul(double** m1, double** m2);

/*
double** m1: 행렬 A
double** m2: 행렬 B
결과: A+B=C인 행렬 C를 반환
*/
double** matsum(double** m1, double** m2);

/*
double** m1: 행렬 A
double** m2: 행렬 B
결과: A-B=C인 행렬 C를 반환
*/
double** matsub(double** m1, double** m2);

/*
double** m1: 행렬 A
결과: A의 역행렬을 반환
참고: 가우스소거법을 사용함.
*/
double** revmat(double** m1);

/*
double** m1: 행렬 A
double** m2: 행렬 B
결과: AxC=B인 행렬 C를 반환
*/
double** matdiv(double** m1, double** m2);

/*
double** m1: 행렬 A
결과: A의 전치행렬을 반환
*/
double** transpose(double** m1);

/*
double** m1: 행렬 A
결과: A의 대각합을 담은 크기 1의 배열을 반환
*/
double** trace(double** m1);

/*
double** m1: 행렬 A
결과: A의 행렬식을 반환
*/
double** determinant(double** m1);

/*
double** m1: 행렬 A
int n0: 행
int n1: 열
결과: A의 n0행 n1열에서의 소행렬을 반환
*/
double** minor(double** m1, int n0, int n1);

/*
double** m1: 행렬 A
결과: A의 수반행렬을 반환
*/
double** adj(double** m1);

/*
double** m1: 행렬 A
결과: A의 역행렬을 반환
참고: https://namu.wiki/w/%ED%96%89%EB%A0%AC%EC%8B%9D#toc
*/
double** invmat(double** m1);

/*
double** m1: 행렬 A
double n: 승수
결과: A에 n을 스칼라곱하여 반환
*/
double** scalamul(double** m1, double n);

/*
double** m1: 행렬 A
double n: 제수
결과: A에 n을 스칼라나눗셈하여 반환
*/
double** scaladiv(double** m1, double n);

/*
double** m1: 행렬 A
double n: 제곱수
결과: A를 n제곱하여 반환
*/
double** powermat(double** m1, int n);

/*
결과: 행렬 계산
*/
double** calc();

/*
결과: 아무키나 누르면 프로그램 종료
*/
void halt();

#endif _INCLUDE_MAT_
