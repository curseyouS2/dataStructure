//250318 �ڷᱸ�� 4���� 
//�ڷᱸ��: ����

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10	

typedef int element; 
typedef struct sample {
	element data[MAX_STACK_SIZE];	
	int top;			
}StackType;				

void init_stack(StackType* s) {	
	s->top = -1;	
}

int is_full(StackType* s) {		
	return s->top == MAX_STACK_SIZE - 1;	
};

//���ÿ� �����͸� ����ִ� �Լ�
void push(StackType* s, element item) {
	
	if (is_full(s)) {	
		printf("���� �����÷ο� ���� \n");
		return;
	}
	else {
		s->data[++s->top = item];
	}
};

int is_empty(StackType* s) {
	return s->top == -1;	
};

element pop(StackType* s) {
	
	//underflow check...
	if (is_empty(s)) {
		printf("������ �������");
		exit(1); 
	}
	else {
		return s->data[(s->top)--]; 
	}
};

//�̷����� ��ġ�� ��Ÿ���� ����ü ����
typedef struct {
	//2����Ʈ¥�� ������ short
	short r;		
	short c;	
} element;

element here = { 1, 0 }, entry = { 1, 0 };	//����ü �ʱ�ȭ

int main(void) {

}