//�ڷᱸ�� 2���� ����
//����ü�� ���Ҽ� ����ϴ� ���α׷� �����
//2491040 ������

//�ַ�� Ž���� ���˿�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	double real = 0;;
	double imagine = 0;;
};

//���� �Լ�
double sum(struct complex num) {
	return 0;
};
//���� �Լ�
double min(struct complex num) {
	return 0;
};
//���� �Լ�
double mul(struct complex num) {
	return 0;
};
//������ �Լ�
double div(struct complex num) {
	return 0;
};

int main(void) {
	struct complex num;
	struct complex* nump = &num;

	
														
	printf("���۾��� ��ȣ�� �Է�>>");
	scanf("%lf", &num.real);
	printf("%.2lf\n", num.real);
	scanf("%lf", &num.imagine);
	printf("%.2lf\n", num.imagine);


}