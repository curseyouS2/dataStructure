//자료구조 2주차 과제
//구조체로 복소수 계산하는 프로그램 만들기
//2491040 강주현

//솔루션 탐색기 컨알엘

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	double real;
	double imagine;
};

//덧셈 함수
void sum(struct complex* p1, struct complex* p2) {
	printf("두 복소수의 합은...%2lf + %2lfi", p1->real + p2->real, p1->imagine + p2->imagine);
};
//뺄셈 함수
double min(struct complex* p, struct complex* p2) {
	return 0;
};
//곱셈 함수
double mul(struct complex* p, struct complex* p2) {
	return 0;
};
//나눗셈 함수
double div(struct complex* p, struct complex* p2) {
	return 0;
};

int main(void) {
	struct complex num1;
	struct complex num2;
	struct complex* nump1 = &num1;
	struct complex* nump2 = &num2;
	int menu;

	printf("◆작업할 번호를 입력>>");
	scanf("%d", &menu);

	switch (menu) {
	case 1:	//복소수 입력받기
		scanf("%lf lf", &num1.real, &num1.imagine);
		scanf("%lf lf", &num2.real, &num2.imagine);
		break;
	case 2:	//덧셈
		sum(nump1, nump2);
		break;
	case 3:	//뺄셈
		break;
	case 4:	//곰셈
		break;
	case 5:	//나눗셈
		break;
	case 6:	//종료
		break;

	}
}