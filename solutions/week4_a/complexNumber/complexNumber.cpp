//자료구조 2주차 과제
//구조체로 복소수 계산하는 프로그램 만들기
//2491040 강주현

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	double real;
	double imagine;
};

//덧셈 함수
void sum(struct complex* p1, struct complex* p2) {
	printf("\n두 복소수의 합은...%.2lf + %.2lfi\n\n", p1->real + p2->real, p1->imagine + p2->imagine);
}
//뺄셈 함수
void min(struct complex* p1, struct complex* p2) {
	printf("\n두 복소수의 차는...%.2lf + %.2lfi\n\n", p1->real - p2->real, p1->imagine - p2->imagine);
}
//곱셈 함수
void mul(struct complex* p1, struct complex* p2) {
	printf("\n두 복소수의 곱은...%.2lf + %.2lfi\n\n", (p1->real * p2->real) - (p1->imagine * p2->imagine), (p1->real * p2->imagine) + (p1->imagine * p2->real));
}
//나눗셈 함수
void div(struct complex* p1, struct complex* p2) {
	printf("\n두 복소수의 나눗셈은...%.6lf + %.6lfi\n\n",
		((p1->real * p2->real) + (p1->imagine * p2->imagine)) / ((p2->real * p2->real) + (p2->imagine * p2->imagine)),
			(((p1->imagine * p2->real) - (p1->real * p2->imagine)) / ((p2->real * p2->real) + (p2->imagine * p2->imagine))));
}

int main(void) {
	struct complex num1;
	struct complex num2;
	struct complex* nump1 = &num1;
	struct complex* nump2 = &num2;
	int menu;
	int stop = 1;
	while (stop) {
		printf("***복소수 연산***\n");
		printf("1.데이터 입력\n");
		printf("2. 복소수 덧셈\n");
		printf("3. 복소수 뺄셈\n");
		printf("4. 복소수 곱셈\n");
		printf("5. 복소수 나눗셈\n");
		printf("6. 프로그램 종료\n");
		printf("◆작업할 번호를 입력>>");
		scanf("%d", &menu);

		switch (menu) {

		case 1:	//복소수 입력받기
			num1.real = 0; num2.real = 0; num1.imagine = 0; num2.imagine = 0;
			printf("\n첫번째 복소수 입력: ");
			scanf("%lf %lf", &num1.real, &num1.imagine);
			printf("두번째 복소수 입력: ");
			scanf("%lf %lf", &num2.real, &num2.imagine);
			printf("\n");
			break;
		case 2:	//덧셈
			sum(nump1, nump2);
			break;
		case 3:	//뺄셈
			min(nump1, nump2);
			break;
		case 4:	//곱셈
			mul(nump1, nump2);
			break;
		case 5:	//나눗셈
			div(nump1, nump2);
			break;
		case 6:	//종료
			stop = 0;
			break;
		default:
			printf("\n잘못된 입력\n\n");
			break;
		}
	}
	
}