//250318 자료구조 4주차 
//자료구조: 스택

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

//스택에 데이터를 집어넣는 함수
void push(StackType* s, element item) {
	
	if (is_full(s)) {	
		printf("스택 오버플로우 에러 \n");
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
		printf("스택이 비어있음");
		exit(1); 
	}
	else {
		return s->data[(s->top)--]; 
	}
};

//미로판의 위치를 나타내는 구조체 정의
typedef struct {
	//2바이트짜리 정수형 short
	short r;		
	short c;	
} element;

element here = { 1, 0 }, entry = { 1, 0 };	//구조체 초기화

int main(void) {

}