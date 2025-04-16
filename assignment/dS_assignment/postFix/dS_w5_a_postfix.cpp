//자료구조 4주차 과제
//스택 사용하여 후위수식 표기하기

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
void pop(StackType* s) {
	if (isEmpty(s)) {
		printf("스택 언더플로우");
		exit(1);
	}
	else {
		return s->data[(s->top)--]	//실행순서... top값 불러옴, data[]값 리턴, top--
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


