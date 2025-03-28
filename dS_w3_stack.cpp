//250318 �ڷᱸ�� 3���� 
//�ڷᱸ��: ����
//���õ� �����͸� �Լ��� �Ű������� �����ϴ� ��� 
//����: ���� ����, �ҹ��....

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5	//5�� MAX_STACK_SIZE�� �θ��Կ�(�ǹ̺ο�)

//���� �������� ���̸� �����ϴ� top���� ����(����ü��...��?) 
typedef int element; //int��� �ᵵ �ǰ� element��� �ᵵ �� (�ǹ̺ο��� ���� �ٲ� ����)
typedef struct sample {
	element data[MAX_STACK_SIZE];	//�ǹ��� ���鿡�� int -> element, MAX_STACK_SIZE �����̵���
	int top;			//�׳� �ε����̱� ������  int�� �ص� ����
}StackType;				//����ü�� ���ο� Ÿ�� �̸�

//struct smaple x;	//x�� �޸� 
//StackType x;

void init_stack(StackType *s) {	//main�Լ��� ������ �������� ���ϱ� ������ top�� �Ű������� ���� -> �޸� ������ ���� �޸��� �ּҰ��� �����Ѵ�(������)	
	s->top = -1;	//���ο�(->)���
}

int is_full(StackType *s) {		//0�Ǵ� 1 ��ȯ...��ȯ�� int
	return s->top == MAX_STACK_SIZE - 1;	// top�� MAX_STACK_SIZE�� ������ 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
};

//���ÿ� �����͸� ����ִ� �Լ�
void push(StackType *s, element item) {	
	//�迭 ũ�⸸ŭ�� �����ϵ��� �����ؾߵ�(�� �̻� ->�����÷ο�)
	//overflow check...
	if (is_full(s)) {	//*s��� �ع����� �ּҰ� �ƴ϶� ���� �������� �Ǿ����
		printf("���� �����÷ο� ���� \n");
		return;
	}
	else {
		//s->top += 1 �Ǵ�...	
		++(s->top);	//������ �켱���� �߿�...(������ �ַο찡 �����̱� ��)
		s->data[s->top] = item;//��� ->�� ����ϴ±���...
	}
	//else�� �ִ� ��� �̷��� ������ ����(������)
	//s->data[++s->top = item];
};

int is_empty(StackType* s) {
	return s->top == -1;	// top�� -1�̸� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
};
//���� ���� �� ������ �Լ�
element pop(StackType *s) {//�Լ� �̸��� element�� �ᵵ �Ǵ±���...(�ǹ�!!)
	//����÷ο� ����(�ƹ��͵� ���µ� �� ����)
	//underflow check...
	if (is_empty(s)) {//if(1)�̸�...(while(1)ó��)
		printf("������ �������");
		exit(1); //Ż��(���ϰ��� ���⶧���� exit�� ���)
	}
	else {
		int res;
		res = s->data[s->top];
		s->top = s->top - 1;
		return res;
		//return s->data[(s->top)--]; //���� �� �� �� �ٷ� �����ϴ�!!
	}
};

int main(void) {

	StackType s;

	init_stack(&s);	//top���� -1�� �ʱ�ȭ�ϴ� �Լ�(�ּҰ��� �Ű�������)
	push(&s, 10); push(&s, 20); push(&s, 30);

	int res;	//.c������ �� �����Լ� ���� ���� �����ϵ��� �Ѵ�...

	res = pop(&s);	//30		//���� �����ϱ� ������ �Լ�pop���� return�� ����... 
	printf("pop vallue is %d\n", res);

	res = pop(&s);  //20
	printf("pop vallue is %d\n", res);

	return 0;
}