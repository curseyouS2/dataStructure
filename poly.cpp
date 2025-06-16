//20250429 자료구조 9주차
//동적 단순 연결리스트
//단순 연결 리스트로 다항식 덧셈 구현하기

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {	//리스트의 노드 정의
	int coef;
	int expon;
	struct ListNode* link;	//자기참조 구조체...아직 struct 써주어야함(별명 밑에서 정의되기 때문에...순차실행)
}ListNode;

//가변길이의 리스트의 정보를 저장하는 구조체 (시작과 끝, 길이)
typedef struct ListType {
	int size;				//리스트 길이
	ListNode* head;			//시작 노드의 주소
	ListNode* tail;			//끝 노드의 주소
}ListType;
 
ListType* create()	//list에 저장을 할거기때문에 리턴값 listType*...(같아야함) 
{	
	//ListType(리스트의 정보가 저장된 주소) plist...
	ListType* plist = (ListType*)malloc(sizeof(ListType));	//리스트타입의크기만큼 할당하고 그 시작 주소를 plist에 할당
	
	plist->size = 0;					//리스트 초기화
	plist->head = plist->tail = NULL;	//시작과 끝 노드의 주소가 같다...(노드가 없다)
	
	return plist;	//plist(주소)를 반환...반환 후 plist 메모리 사라짐 (지역변수)
	//-> 리스트
}

void insert_last(ListType* plist, int coef, int expon)	//리스트의 정보의 주소, 지수, 가수 전달
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));	//ListNode 크기만큼 할당, 시작주소 ListNode* 타입으로 temp에 할당
	temp->coef = coef;	
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL)	//만약 첫 노드라면
	{
		plist->head = plist->tail = temp;
	}
	else
	{
		plist->tail->link = temp;	//둘다 같은 노드를 가르키는 상황
		plist->tail = temp;			//전 노드와 새 노드 연결
	}
	plist->size++;
}

//리스트 출력 함수...리스트의 정보 포인터 전달
void poly_print(ListType* plist) 
{
	ListNode* p = plist->head;
	printf("다항식 A는...");
	for (;p/*p != NULL*/;p = p->link)	//c언어 특: 값이 없으면 거짓임 그래서 p만 써도 됨
	{									//p(노드임)에 저장된 링크 따라감
		printf("%dx^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

//쉬프트 누르고 화살표 누르면 선택가능 
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;
	while (a && b)	//a와 b는 리스트의 헤드값임
	{
		if (a->expon == b->expon)
		{
			sum = a->coef + b->coef;
			if (sum != 0) 
			{
				insert_last(plist3, sum, a->expon);
			}
			a = a->link;
			b = b->link;
		}
		else if (a->expon > b->expon)	//a지수가 더 크면
		{
			insert_last(plist3, a->coef, a->expon);	//a의 노드를 list3에 추가
			a = a->link;							//a의 다음 노드로 이동
		}
		else										//b지수가 더 크면
		{
			insert_last(plist3, b->coef, b->expon);	//b의 노드를 list3에 추가
			b = b->link;							//b의 다음 노드로 이동
		}
	}
	for (;a;a->link)
	{
		insert_last(plist3, a->coef, a->expon);
	}
	for (;b;b->link)
	{
		insert_last(plist3, b->coef, b->expon);
	}
}


int main(void) 
{
	ListType* list1, * list2, * list3;	//리스트정보의 주소
	list1 = create();
	list2 = create();
	list3 = create();

	//식 A
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);			//2번 노드의 주소를 테일에넣고 1번 노드와 2번 노드 연결...
	insert_last(list1, 1, 9);			//ㄴ>첫 노드의 주소는 tail->link가 가지고 있다

	
	//식B
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);	
	insert_last(list2, 10, 6);

	poly_print(list1);	// 3x^12 + 2x^8 + 1x^0
	poly_print(list2);

	poly_add(list1, list2, list3);	//더할 리스트 2개, 결과 저장할 리스트 1개 ... 총 3개
	
	poly_print(list3);
}