//20250415 자료구조 7주차
//연결 리스트 구현

//EX...다항식의 계산.
//배열을 사용할 시 x의 차수별로 모두 메모리를 할당해야함...
//이러면 막 x의 100승!!!!이다? 가수 배열 100부터 0까지 다 할당해야되는 것임!!!
//그러나 연결리스트를 사용한다면!!!
//계수와 가수를 한 노드에 저장하고 링크해서 메모리를 아낄 수 있다~ 이말이야

#include <stdio.h>
#include <stdlib.h>

typedef int element;
//자기 참조 구조체
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//main함수와 insert_first함수는 head를 공유...
//head는 포인터, 그런데 head의 주소가 필요하다? -> 이중포인터(포인터의 포인터)
//근데 너무 어려우니까 안 쓰고 그냥...head를 리턴하는 걸로~ -> 리턴타입 ListNode* (head의 타입)
ListNode* insert_first(ListNode* head, element value) {	 
	ListNode* p;	//일시적으로 노드의 주소값을 저장할 변수 p
	p = (ListNode*)malloc(sizeof(ListNode));	//malloc한 값을 head와 같은 타입으로 형변환 해주어야 함...
	p->data = value;	//값 노드에 저장
	p->link = head;
	head = p;	//head와 p 모두 지역포인터...함수 실행 이후 사라진다~~~
	return head;	//함수 내에서 개지랄뿅하고 결국엔 main함수의 head로 리턴이 되는 것이다~
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL;p=p->link) {
		printf("%d -> ", p->data);
	}
	printf("\n");
}

ListNode* delete_first(ListNode* head) {
	//동적에서...언더플로우 체크는 해야돼!!!(오버플로우는 보통...안해도 ok)
	if (head == NULL) {
		printf("꺼져!!!!!!");
		return NULL;
	}
	ListNode* removed = head;	//약간 temp 느낌이군...
	head = head->link;	
	free(removed);
	return head;
}

ListNode* search_list(ListNode* head, element x) {
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link;	//link(특: 주소임)를 통해 다음 노드로...(p값 변한 뒤 다시 while문 반복하므로)
	}
}

int main(void) {
	
	ListNode* head = NULL; //노드의 시작 주소...주소값이 없을 때는 NULL
	
	head = insert_first(head, 10);	//헤드 다음에 새 노드를 추가	
	head = insert_first(head, 20);
	head = insert_first(head, 30);
	//30->20->10

	print_list(head);	

	head = delete_first(head);	//헤드 다음 노드를 삭제
	//20->10

	//노드 탐색하기(중간에 생성 / 삭제하기 위해서는 탐색을 먼저 해야해요...찾아서 삭제하는 코드까지 중간 시험 들어감 ㅅㄱ)
	if (search_list(head, 40)==NULL) {
		printf("리스트에 값이 없어요...!!!\n");
	}
	else {
		printf("리스트에 값이 있어요^^푸하하~\n");
	}

	return 0;
}

//시험? ...
//키워드 정리 보세용^^(제발)