//자료구조 4주차 과제
//동적 배열 할당...
//중위표기식 수식 후위표기 수식으로 바꾸고 계산 출력

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

void init_stack(StackType* s) {	//스택 초기화
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int isFull(StackType* s) {	//오버플로우 체크용
	return (s->top == (s->capacity - 1));
}

int isEmpty(StackType* s) {	//언더플로우 체크용
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

// 피크함수
element peek(StackType* s)
{
	if (isEmpty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}


int prec(char op) {	// 연산자 우선순위
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
	for (i = 0;i < len;i++) {	//문자열에 기호 검사!!
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
	printf("중위표시수식 %s\n", s);
	printf("후위표기수식 ");
	in2post(s);
	printf("\n");
	return 0;
}