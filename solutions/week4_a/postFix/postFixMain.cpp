//�ڷᱸ�� 4���� ����
//���� �迭 �Ҵ�...
//����ǥ��� ���� ����ǥ�� �������� �ٲٰ� ��� ���

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element* data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType* s) {	//���� �ʱ�ȭ
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int isFull(StackType* s) {	//�����÷ο� üũ��
	return (s->top == (s->capacity - 1));
}

int isEmpty(StackType* s) {	//����÷ο� üũ��
	return (s->top == -1);
}

void push(StackType* s, element item) {
	if (isFull(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(int));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "no exist\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

// ��ũ�Լ�
element peek(StackType* s)
{
	if (isEmpty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}


int prec(char op) {	// ������ �켱����
	switch (op) {
	case'(': case')': return 0;
	case'+': case'-': return 1;
	case'*': case'/': return 2;
	}
	return -1;
}

void in2post(char exp[]) {
	int i;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init_stack(&s);
	for (i = 0;i < len;i++) {	//���ڿ��� ��ȣ �˻�!!
		ch = exp[i];
		switch (ch) {
		case'+':case'-':case'*':case'/':
			while (!isEmpty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", pop(&s));
				push(&s, ch);
				break;
			}
		case'(': 
			push(&s, ch);
			break;
		case')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		}
	default:
		printf("%c", ch);
		break;
	}
	while (!isEmpty(&s)) {
		printf("%c", pop(&s));
	}
}

int eval(char exp[]) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stack(&s);
}

int main(void) {
	char* s = "(2+3)*4+9";
	printf("����ǥ�ü��� %s\n", s);
	printf("����ǥ����� ");
	in2post(s);
	printf("\n");
	return 0;
}