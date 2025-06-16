//250325 자료구조 4주차
//동적 메모리 할당
//왜 자꾸 다른 프로젝트가 실행되는지 해결?

#include <stdio.h>
#include <stdlib.h>

typedef int element;	//스택의 요소(의미의 측면)

//스택 선언
typedef struct {	//동적이기때문에 구조체 내 배열 선언 필요 x
	element* data;	//동적할당할 메모리를 가르키는 포인터변수
	int capacity;	//메모리 공간 수
	int top;		//스택이면 있어야됨 ㅋㅋ

}StackType;

void init_stack(StackType* s) {
	s->top = -1;		//넣는 위치 초기화...
	s->capacity = 1;	
	s->data = (element*)malloc(s->capacity * sizeof(int));	//element(사실 int임) 
															//타입의 포인터 변수 data에 메모리 할당...'크기 X 각 자료형의 크기'...
}
int isFull(StackType* s) {
	return s->top == (s->capacity - 1);	//top과크기비교...(자꾸 '->' 까먹어 ㅠㅠ) 
}

void push(StackType* s, element item) {	
	//오버플로우 체크
	if (isFull(s)) {	//'==1'꼭 안써도 됨... 왜? if(1)이면 무조건 실행, if(0)이면 실행 X...
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(int));			//malloc말고 realloc...기존 데이터 그대로 두고 메모리 할당
	}
	s->data[++(s->top)] = item;	//top이 -1부터 시작하기때문에...top
}

int isEmpty(StackType* s) {
	return s->top == -1;	//스택은 구조체니까 '->' 써야된다고!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!(제발)
}

element pop(StackType* s) {
	//언더플로우 체크
	if (isEmpty(s)) {
		printf("꺼져!!!!!");
		exit(1);
	}
	else {
		return s->data[s->top--];	//일단 빼오고 -1...
		//포인터변수 data가 가르키는 할당된 메모리에서 순서대로 가져오세요~
	}
}

void main() {
	StackType s;	//스택을 선언(구조체 변수s)
	init_stack(&s);
	
	push(&s, 10);
	push(&s, 20);

	printf("Pop value: %d\n", pop(&s));	//20
	printf("Pop value: %d\n", pop(&s));	//10

	printf("Pop value: %d\n", pop(&s));	//error!!(underflow)
	//동적 메모리 반환
	free(s.data);	//s가 두 개라서 헷갈릴 수 있음...하지만 둘은 다르다 !!! (하나는 구조체 변수s 하나는 구조체를 가르키는 포인터...)
					//free에서의 s는 구조체 변수 ('.'사용)
}