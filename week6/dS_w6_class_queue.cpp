//250408 �ڷᱸ�� 6����
//ť
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct q {
	int front;	//ù �� ��ġ�� �ٷ� �� dequeue�� ����
	int rear;	//�� ���� ��ġ	enque
	element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType* q) {
	q->front = 0;	//���� ť���� front�� rear�� 0...
	q->rear = 0;	//������ -1
}

//�Լ� ���ο� �ִ� �Լ��� ���� ���ϰ��� �ִ�...(isfull,isempty����)
//�ٵ� ����ť�� ��á������ ����������� ������ �ȵ�
//�ذ�?? front==r+1�̸� full�̶�� �Ǻ�(�޸� 1�� ����)
//���� ť �϶��� isfull 
/*int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}*/
int is_full(QueueType* q) {	//���� ť�϶��� isfull�Լ�
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
int is_empty(QueueType* q) {
	return ((q->rear) == (q->front));
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("�� á���.\n");
		return;
	}
	else {
		q->rear = (q->rear++) % MAX_QUEUE_SIZE;	//���� ť ������ ���� �ڵ�...
		q->data[(q->rear)] = item;	//���� ť���� ù ���� �ε��� 1�� ���� �ȴ�(�ڵ��ؼ��ϸ�  rear++�ϰ� ť������� �����⶧����)
	}	
}

element dequeue(QueueType* q) {
	//����÷ο� üũ
	if (is_empty(q)) {
		printf("�����");
		exit(1);
	}
	q->front = (q->front++) % MAX_QUEUE_SIZE;	//���� ť ������ ���� �ڵ�
	return q->data[++q->front];
}

//ť ��� �Լ�
void print_queue(QueueType* q) {
	printf("QUEUE(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;	
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf(" %d |", q->data[i]);
			if (i == q->rear)	//front==rear�̸� ���� �ִ� ��� ����� ��!
				break;
		} while (i != q->front);
	}
	printf("\n");
}
element peek(QueueType* q) {
	if (is_empty(q)) {
		printf("������ �����!!!!!!!\n");
	}
}
int main(void) {
	QueueType q;	//�Ϲ� �޸𸮿� �Ҵ�(malloc�Ƚ��ݾ�)
	init_queue(&q);
	int a = 10, b = 20, c = 30;
	enqueue(&q, a);	//rear=0
	enqueue(&q, b);	//rear=1
	enqueue(&q, c);	//rear=2

	//element item = dequeue(&q);

	/*for (int i = q.front + 1;i <= q.rear;i++) {	//���⼭�� q�� �����Ͱ� �ƴ϶� ����ü �����̱� ������ ��Ʈ������ ����ؾ���
		printf("%3d ", q.data[i]);				// .�� ->�� ���̸� �ٽ� �ѹ� Ȯ�� ����...(�����ʹ� �ּҴϱ� �ַο��� �����ϸ� ���ؿ�)
	}											//�׸��� .+�� �ؼ� �ַο�� ���� ����
	printf("\n");*/

	//ť ����ϱ�
	print_queue(&q);

	return 0;
}