//250408 자료구조 6주차
//큐
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct q {
	int front;	//첫 값 위치의 바로 앞 dequeue와 관련
	int rear;	//끝 값의 위치	enque
	element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType* q) {
	q->front = 0;	//원형 큐에서 front와 rear은 0...
	q->rear = 0;	//선형은 -1
}

//함수 내부에 있는 함수는 보통 리턴값이 있다...(isfull,isempty같이)
//근데 원형큐는 꽉찼을때랑 비어있을때의 구분이 안됨
//해결?? front==r+1이면 full이라고 판별(메모리 1개 포기)
//선형 큐 일때의 isfull 
/*int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}*/
int is_full(QueueType* q) {	//원형 큐일때의 isfull함수
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
int is_empty(QueueType* q) {
	return ((q->rear) == (q->front));
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("다 찼어요.\n");
		return;
	}
	else {
		q->rear = (q->rear++) % MAX_QUEUE_SIZE;	//원형 큐 구현을 위한 코드...
		q->data[(q->rear)] = item;	//원형 큐에서 첫 값은 인덱스 1에 들어가게 된다(코드해석하면  rear++하고 큐사이즈로 나누기때문에)
	}	
}

element dequeue(QueueType* q) {
	//언더플로우 체크
	if (is_empty(q)) {
		printf("없어요");
		exit(1);
	}
	q->front = (q->front++) % MAX_QUEUE_SIZE;	//원형 큐 구현을 위한 코드
	return q->data[++q->front];
}

//큐 출력 함수
void print_queue(QueueType* q) {
	printf("QUEUE(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;	
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf(" %d |", q->data[i]);
			if (i == q->rear)	//front==rear이면 값이 있는 모두 출력한 것!
				break;
		} while (i != q->front);
	}
	printf("\n");
}
element peek(QueueType* q) {
	if (is_empty(q)) {
		printf("꺼낼게 없어요!!!!!!!\n");
	}
}
int main(void) {
	QueueType q;	//일반 메모리에 할당(malloc안썼잖어)
	init_queue(&q);
	int a = 10, b = 20, c = 30;
	enqueue(&q, a);	//rear=0
	enqueue(&q, b);	//rear=1
	enqueue(&q, c);	//rear=2

	//element item = dequeue(&q);

	/*for (int i = q.front + 1;i <= q.rear;i++) {	//여기서의 q는 포인터가 아니라 구조체 변수이기 때문에 도트연산자 사용해야함
		printf("%3d ", q.data[i]);				// .와 ->의 차이를 다시 한번 확인 가능...(포인터는 주소니까 애로우라고 생각하면 편해요)
	}											//그리고 .+탭 해서 애로우로 변경 가능
	printf("\n");*/

	//큐 출력하기
	print_queue(&q);

	return 0;
}