//�ڷᱸ�� 2���� ����
//����ü�� ���Ҽ� ����ϴ� ���α׷� �����
//2491040 ������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	double real;
	double imagine;
};

//���� �Լ�
void sum(struct complex* p1, struct complex* p2) {
	printf("\n�� ���Ҽ��� ����...%.2lf + %.2lfi\n\n", p1->real + p2->real, p1->imagine + p2->imagine);
}
//���� �Լ�
void min(struct complex* p1, struct complex* p2) {
	printf("\n�� ���Ҽ��� ����...%.2lf + %.2lfi\n\n", p1->real - p2->real, p1->imagine - p2->imagine);
}
//���� �Լ�
void mul(struct complex* p1, struct complex* p2) {
	printf("\n�� ���Ҽ��� ����...%.2lf + %.2lfi\n\n", (p1->real * p2->real) - (p1->imagine * p2->imagine), (p1->real * p2->imagine) + (p1->imagine * p2->real));
}
//������ �Լ�
void div(struct complex* p1, struct complex* p2) {
	printf("\n�� ���Ҽ��� ��������...%.6lf + %.6lfi\n\n",
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
		printf("***���Ҽ� ����***\n");
		printf("1.������ �Է�\n");
		printf("2. ���Ҽ� ����\n");
		printf("3. ���Ҽ� ����\n");
		printf("4. ���Ҽ� ����\n");
		printf("5. ���Ҽ� ������\n");
		printf("6. ���α׷� ����\n");
		printf("���۾��� ��ȣ�� �Է�>>");
		scanf("%d", &menu);

		switch (menu) {

		case 1:	//���Ҽ� �Է¹ޱ�
			num1.real = 0; num2.real = 0; num1.imagine = 0; num2.imagine = 0;
			printf("\nù��° ���Ҽ� �Է�: ");
			scanf("%lf %lf", &num1.real, &num1.imagine);
			printf("�ι�° ���Ҽ� �Է�: ");
			scanf("%lf %lf", &num2.real, &num2.imagine);
			printf("\n");
			break;
		case 2:	//����
			sum(nump1, nump2);
			break;
		case 3:	//����
			min(nump1, nump2);
			break;
		case 4:	//����
			mul(nump1, nump2);
			break;
		case 5:	//������
			div(nump1, nump2);
			break;
		case 6:	//����
			stop = 0;
			break;
		default:
			printf("\n�߸��� �Է�\n\n");
			break;
		}
	}
	
}