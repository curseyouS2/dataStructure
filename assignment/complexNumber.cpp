//�ڷᱸ�� 2���� ����
//����ü�� ���Ҽ� ����ϴ� ���α׷� �����
//2491040 ������

//�ַ�� Ž���� ���˿�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	double real;
	double imagine;
};

//���� �Լ�
void sum(struct complex* p1, struct complex* p2) {
	printf("�� ���Ҽ��� ����...%2lf + %2lfi", p1->real + p2->real, p1->imagine + p2->imagine);
};
//���� �Լ�
double min(struct complex* p, struct complex* p2) {
	return 0;
};
//���� �Լ�
double mul(struct complex* p, struct complex* p2) {
	return 0;
};
//������ �Լ�
double div(struct complex* p, struct complex* p2) {
	return 0;
};

int main(void) {
	struct complex num1;
	struct complex num2;
	struct complex* nump1 = &num1;
	struct complex* nump2 = &num2;
	int menu;

	printf("���۾��� ��ȣ�� �Է�>>");
	scanf("%d", &menu);

	switch (menu) {
	case 1:	//���Ҽ� �Է¹ޱ�
		scanf("%lf lf", &num1.real, &num1.imagine);
		scanf("%lf lf", &num2.real, &num2.imagine);
		break;
	case 2:	//����
		sum(nump1, nump2);
		break;
	case 3:	//����
		break;
	case 4:	//����
		break;
	case 5:	//������
		break;
	case 6:	//����
		break;

	}
}