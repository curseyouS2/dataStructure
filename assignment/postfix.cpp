//자료구조 4주차 과제
//스택 사용하여 후위수식 표기하기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
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

void push(StackType* s, element item) {
	if (isFull(s)) {
		//스택이 가득 찼다면...공간을 더 할당.
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	else {
		s->data[++(s->top)] = item;//실행순서...top값 불러옴, ++top, data[]에 item할당
	}
}

int isEmpty(StackType* s) {
	return (s->top == -1);
}

element pop(StackType* s) {
	if (isEmpty(s)) {
		printf("스택 언더플로우");
		exit(1);
	}
	else {
		return s->data[(s->top)--];	//실행순서... top값 불러옴, data[]값 리턴, top--
	}
}

int prec(char op) {
	switch(op) {
		case'(':case')': return 0;
		case'+':case'-': return 1;
		case'*':case'/': return 2;
	}
	return -1;
}
void make_postfix(char str[]) {
	StackType s;
	int len = strlen(str);
	init_stack(&s);

	for (int i = 0;i < len;i++) {
		if (prec(str[i] == 0) {
			push(&s, str[i])
		}
	}
}


int main(void) {
	char str1[100] = "2+3*4";
	char str2[500] = "(1+2)*(3+4)-(5+6)*(7-8)+(9+10)*(11-12)+(13*14)-(15/3)+(16+17)-(18*19)+(20/2)";
	make_postfix(str1);
	
	return 0;
}