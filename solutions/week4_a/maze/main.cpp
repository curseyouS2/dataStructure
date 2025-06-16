#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 

#define MAZE_SIZE 8
#define MAX_STACK_SIZE 100

//element 구조체 정의(위치정보)
typedef struct {
	short r;
	short c;
} element;

typedef struct {	//스택 정의
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
//스택 관련 함수들...
void init_stack(StackType* s) {	
	s->top = -1;	
}

int is_full(StackType* s) {		
	return s->top == MAX_STACK_SIZE - 1;	
};

void push(StackType* s, element item) {
	//overflow check...
	if (is_full(s)) {	
		printf("스택 오버플로우 에러 \n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
};

int is_empty(StackType* s) {
	return s->top == -1;	
};

element pop(StackType* s) {
	//언더플로우 조심(아무것도 없는데 또 뺴기)
	//underflow check...
	if (is_empty(s)) {
		printf("스택이 비어있음");
		exit(1); 
	}
	else {
		return s->data[(s->top)--]; 
	}
};

//미로 구성...
element here = { 1,0 }, entry = { 1,0 }; //현재 위치, 입구

//미로 구조 8x8
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '0', '0', '1' },
	{ '1', '0', '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '1', '1', '0', '1', '1' },
	{ '1', '0', '0', '0', '0', '0', '1', '1' },
	{ '1', '1', '1', '1', '0', '1', '1', '1' },
	{ '1', '1', '1', '0', '0', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1', '1', '1' }
};

//
void pushLocation(StackType* s, int r, int c) {
	if (r < 0 || c < 0) {	//만약 둘 중 하나 음수면 다시
		return;
	}
	if (maze[r][c] != '1' /* && maze[r][c] != '.'*/) {	//만약 벽이 아니고 .도 아니라면
		element tmp;	
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);	//이동경로 스택에 현재 위치 집어넣기
	}
}
void popLocation(StackType* s, int r, int c) {
	if (!is_empty(s)) {
		element top = s->data[s->top];
		if (top.r==r && top.c==c&&maze[r][c]=='.') {
			pop(s);
		}
	}
	}
void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {	//미로 출력
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

void getMovement(StackType* s, int r, int c) {
	char ch;

	printf("\n<<이동 입력>>\n");
	printf("w: 위 | a: 왼쪽 | s: 아래 | d: 오른쪽\n");
	scanf(" %c", &ch);

	switch (ch) {
	case 'w':	//위
		if (maze[r - 1][c] != '1' && maze[r - 1][c] != 'x') {
			maze[r - 1][c] = '.';
			pushLocation(s, r - 1, c);
		}
		else {
			printf("이 앞은 막혀있습니다...\n");
		}
		
		break;
	case 'a':	//왼
		if (maze[r][c - 1] != '1' && maze[r][c - 1] != 'x') {
			maze[r][c - 1] = '.';
			pushLocation(s, r, c - 1);
		}
		else {
			printf("이 앞은 막혀있습니다...\n");
		}
		break;
	case 's':	//아래
		if (maze[r + 1][c] != '1' && maze[r + 1][c] != 'x') {
			maze[r + 1][c] = '.';
			pushLocation(s, r + 1, c);
		}
		else {
			printf("이 앞은 막혀있습니다...\n");
		}
		break;
	case 'd':	//오
		if (maze[r][c + 1] != '1' && maze[r][c + 1] != 'x') {
			maze[r][c + 1] = '.';
			pushLocation(s, r, c + 1);
		}
		else {
			printf("이 앞은 막혀있습니다...\n");
		}
		break;
	}
	if (ch != 'w' && ch != 'a' && ch != 's' && ch != 'd') {
		printf("잘못된 입력...\n");
		ch = '\0';
	}

};

int main(void) {
	int r, c;		//세로 가로
	StackType s;	//이동 경로 저장하는 스택

	init_stack(&s);
	here = entry;	//입구에서 출발~
	maze[here.r][here.c] = '@';
	printf("~~~미로 탈출~~~\n");
	printMaze(maze);
	while (maze[here.r][here.c] != 'x') {	//현재 위치가 출구가 아니면 계속 반복...
		r = here.r;	//현재 위치
		c = here.c;
		maze[r][c] = '.';//이동한 경로는 .으로 표시됨...
		getMovement(&s, r, c);	//이동 입력 받기
		if (is_empty(&s)) {
			printf("\n실패!!\n");
		}
		else {
			here = pop(&s);
			maze[here.r][here.c] = '@';
		}
		printMaze(maze);
	}
	printf("성공!\n");
	return 0;
}