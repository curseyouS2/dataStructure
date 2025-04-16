#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 

#define MAZE_SIZE 8
#define MAX_STACK_SIZE 100

//element ����ü ����(��ġ����)
typedef struct {
	short r;
	short c;
} element;

typedef struct {	//���� ����
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
//���� ���� �Լ���...
void init_stack(StackType* s) {	
	s->top = -1;	
}

int is_full(StackType* s) {		
	return s->top == MAX_STACK_SIZE - 1;	
};

void push(StackType* s, element item) {
	//overflow check...
	if (is_full(s)) {	
		printf("���� �����÷ο� ���� \n");
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
	//����÷ο� ����(�ƹ��͵� ���µ� �� ����)
	//underflow check...
	if (is_empty(s)) {
		printf("������ �������");
		exit(1); 
	}
	else {
		return s->data[(s->top)--]; 
	}
};

//�̷� ����...
element here = { 1,0 }, entry = { 1,0 }; //���� ��ġ, �Ա�

//�̷� ���� 8x8
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
	if (r < 0 || c < 0) {	//���� �� �� �ϳ� ������ �ٽ�
		return;
	}
	if (maze[r][c] != '1' /* && maze[r][c] != '.'*/) {	//���� ���� �ƴϰ� .�� �ƴ϶��
		element tmp;	
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);	//�̵���� ���ÿ� ���� ��ġ ����ֱ�
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
void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {	//�̷� ���
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

	printf("\n<<�̵� �Է�>>\n");
	printf("w: �� | a: ���� | s: �Ʒ� | d: ������\n");
	scanf(" %c", &ch);

	switch (ch) {
	case 'w':	//��
		if (maze[r - 1][c] != '1' && maze[r - 1][c] != 'x') {
			maze[r - 1][c] = '.';
			pushLocation(s, r - 1, c);
		}
		else {
			printf("�� ���� �����ֽ��ϴ�...\n");
		}
		
		break;
	case 'a':	//��
		if (maze[r][c - 1] != '1' && maze[r][c - 1] != 'x') {
			maze[r][c - 1] = '.';
			pushLocation(s, r, c - 1);
		}
		else {
			printf("�� ���� �����ֽ��ϴ�...\n");
		}
		break;
	case 's':	//�Ʒ�
		if (maze[r + 1][c] != '1' && maze[r + 1][c] != 'x') {
			maze[r + 1][c] = '.';
			pushLocation(s, r + 1, c);
		}
		else {
			printf("�� ���� �����ֽ��ϴ�...\n");
		}
		break;
	case 'd':	//��
		if (maze[r][c + 1] != '1' && maze[r][c + 1] != 'x') {
			maze[r][c + 1] = '.';
			pushLocation(s, r, c + 1);
		}
		else {
			printf("�� ���� �����ֽ��ϴ�...\n");
		}
		break;
	}
	if (ch != 'w' && ch != 'a' && ch != 's' && ch != 'd') {
		printf("�߸��� �Է�...\n");
		ch = '\0';
	}

};

int main(void) {
	int r, c;		//���� ����
	StackType s;	//�̵� ��� �����ϴ� ����

	init_stack(&s);
	here = entry;	//�Ա����� ���~
	maze[here.r][here.c] = '@';
	printf("~~~�̷� Ż��~~~\n");
	printMaze(maze);
	while (maze[here.r][here.c] != 'x') {	//���� ��ġ�� �ⱸ�� �ƴϸ� ��� �ݺ�...
		r = here.r;	//���� ��ġ
		c = here.c;
		maze[r][c] = '.';//�̵��� ��δ� .���� ǥ�õ�...
		getMovement(&s, r, c);	//�̵� �Է� �ޱ�
		if (is_empty(&s)) {
			printf("\n����!!\n");
		}
		else {
			here = pop(&s);
			maze[here.r][here.c] = '@';
		}
		printMaze(maze);
	}
	printf("����!\n");
	return 0;
}