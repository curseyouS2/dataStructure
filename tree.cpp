#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	struct TreeNode* left;
	int data;
	struct TreeNode* right;
}TreeNode;

//	  15
//  4	  20
// 1    16	25 

TreeNode n1 = { NULL, 1 , NULL };
TreeNode n2 = { &n1, 4, NULL };
TreeNode n3 = { NULL, 16 , NULL };
TreeNode n4 = { NULL, 25 , NULL  };
TreeNode n5 = { &n3, 20 , &n4 };
TreeNode n6 = { &n2, 15 , &n5 };
TreeNode* root = &n6;

// ================ 원형큐 코드 시작 =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void level_order(TreeNode* ptr)
{
	QueueType q;

	init_queue(&q);	 // 큐 초기화

	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}
//		  15
//	   4		 20
//    1	      16  25
void postorder(TreeNode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		printf("[%d]\n", root->data);
		postorder(root->right);
	}
}

int main(void)
{
	postorder(root);
	printf("레벨 순회");
	level_order(root);
	printf("\n");
	return 0;
}