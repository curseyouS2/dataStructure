//�ڷᱸ�� 4���� ����
//���� ����Ͽ� �������� ǥ���ϱ�

#include <stdio.h>

typedef int element;
typedef struct s {
	element* data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 100;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}
int isFull(StackType* s) {
	return (s->top == s->capacity - 1);
}
void push(StackType* s, element item){
	if (isFull(s)) {
		//������ ���� á�ٸ�...������ �� �Ҵ�.
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	else {
		s->data[++(s->top)] = item;//�������...top�� �ҷ���, ++top, data[]�� item�Ҵ�
	}
}
int isEmpty(StackType* s) {
	return (s->top == -1);
}
void pop(StackType* s) {
	if (isEmpty(s)) {
		printf("���� ����÷ο�");
		exit(1);
	}
	else {
		return s->data[(s->top)--]	//�������... top�� �ҷ���, data[]�� ����, top--
	}
}
void getExp() {

}
void whichFirst() {

}
void setpost


int main(void) {
	4
	
	
	
	return 0;
}


