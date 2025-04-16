//250325 �ڷᱸ�� 4����
//���� �޸� �Ҵ�
//�� �ڲ� �ٸ� ������Ʈ�� ����Ǵ��� �ذ�?

#include <stdio.h>
#include <stdlib.h>

typedef int element;	//������ ���(�ǹ��� ����)

//���� ����
typedef struct {	//�����̱⶧���� ����ü �� �迭 ���� �ʿ� x
	element* data;	//�����Ҵ��� �޸𸮸� ����Ű�� �����ͺ���
	int capacity;	//�޸� ���� ��
	int top;		//�����̸� �־�ߵ� ����

}StackType;

void init_stack(StackType* s) {
	s->top = -1;		//�ִ� ��ġ �ʱ�ȭ...
	s->capacity = 1;	
	s->data = (element*)malloc(s->capacity * sizeof(int));	//element(��� int��) 
															//Ÿ���� ������ ���� data�� �޸� �Ҵ�...'ũ�� X �� �ڷ����� ũ��'...
}
int isFull(StackType* s) {
	return s->top == (s->capacity - 1);	//top��ũ���...(�ڲ� '->' ��Ծ� �Ф�) 
}

void push(StackType* s, element item) {	
	//�����÷ο� üũ
	if (isFull(s)) {	//'==1'�� �Ƚᵵ ��... ��? if(1)�̸� ������ ����, if(0)�̸� ���� X...
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(int));			//malloc���� realloc...���� ������ �״�� �ΰ� �޸� �Ҵ�
	}
	s->data[++(s->top)] = item;	//top�� -1���� �����ϱ⶧����...top
}

int isEmpty(StackType* s) {
	return s->top == -1;	//������ ����ü�ϱ� '->' ��ߵȴٰ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!(����)
}

element pop(StackType* s) {
	//����÷ο� üũ
	if (isEmpty(s)) {
		printf("����!!!!!");
		exit(1);
	}
	else {
		return s->data[s->top--];	//�ϴ� ������ -1...
		//�����ͺ��� data�� ����Ű�� �Ҵ�� �޸𸮿��� ������� ����������~
	}
}

void main() {
	StackType s;	//������ ����(����ü ����s)
	init_stack(&s);
	
	push(&s, 10);
	push(&s, 20);

	printf("Pop value: %d\n", pop(&s));	//20
	printf("Pop value: %d\n", pop(&s));	//10

	printf("Pop value: %d\n", pop(&s));	//error!!(underflow)
	//���� �޸� ��ȯ
	free(s.data);	//s�� �� ���� �򰥸� �� ����...������ ���� �ٸ��� !!! (�ϳ��� ����ü ����s �ϳ��� ����ü�� ����Ű�� ������...)
					//free������ s�� ����ü ���� ('.'���)
}