// 202505020 자료구조
// 연결리스트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element[50];
typedef struct DListNode 
{
	struct DListNode* llink;
	element data;
	struct DListNode* rlink;
}DListNode;

DListNode* current;

void init(DListNode* phead)	//리스트 초기화
{
	phead->llink = phead;
	phead->rlink = phead;
}
void dinsert(DListNode* before, const element data) 
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newNode->data, data);
	newNode->llink = before;
	newNode->rlink = before->rlink; //중요
	//3, 4 순서 바뀌면 안 됨!!!
	before->rlink->llink = newNode;
	before->rlink = newNode;
}
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead;p = p->rlink)
	{
		if (p == current)
		{
			printf("<-| #%s# |->\n", p->data);
		}
		else
		{
			printf("<-| %s |->\n", p->data);
		}
	}
}
int main()
{
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	dinsert(head, "Mamamia");
	dinsert(head, "DancingQueen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do
	{
		printf("명령어를 입력하세요(<, >, q): ");
		ch = getchar();
		if (ch == '<')
		{
			current = current->llink;
			if (current == head)
			{
				current = current->llink;
			}
		}
		else if (ch == '>')
		{
			current = current->rlink;
			if (current == head)
			{
				current = current->rlink;	//계속 페르난도...
			}
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');	//굳이 q의 경우를 작성하지 않아도 된다
	print_dlist(head);
	getchar();
}