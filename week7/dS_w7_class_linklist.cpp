//20250415 �ڷᱸ�� 7����
//���� ����Ʈ ����

//EX...���׽��� ���.
//�迭�� ����� �� x�� �������� ��� �޸𸮸� �Ҵ��ؾ���...
//�̷��� �� x�� 100��!!!!�̴�? ���� �迭 100���� 0���� �� �Ҵ��ؾߵǴ� ����!!!
//�׷��� ���Ḯ��Ʈ�� ����Ѵٸ�!!!
//����� ������ �� ��忡 �����ϰ� ��ũ�ؼ� �޸𸮸� �Ƴ� �� �ִ�~ �̸��̾�

#include <stdio.h>
#include <stdlib.h>

typedef int element;
//�ڱ� ���� ����ü
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//main�Լ��� insert_first�Լ��� head�� ����...
//head�� ������, �׷��� head�� �ּҰ� �ʿ��ϴ�? -> ����������(�������� ������)
//�ٵ� �ʹ� �����ϱ� �� ���� �׳�...head�� �����ϴ� �ɷ�~ -> ����Ÿ�� ListNode* (head�� Ÿ��)
ListNode* insert_first(ListNode* head, element value) {	 
	ListNode* p;	//�Ͻ������� ����� �ּҰ��� ������ ���� p
	p = (ListNode*)malloc(sizeof(ListNode));	//malloc�� ���� head�� ���� Ÿ������ ����ȯ ���־�� ��...
	p->data = value;	//�� ��忡 ����
	p->link = head;
	head = p;	//head�� p ��� ����������...�Լ� ���� ���� �������~~~
	return head;	//�Լ� ������ ���������ϰ� �ᱹ�� main�Լ��� head�� ������ �Ǵ� ���̴�~
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL;p=p->link) {
		printf("%d -> ", p->data);
	}
	printf("\n");
}

ListNode* delete_first(ListNode* head) {
	//��������...����÷ο� üũ�� �ؾߵ�!!!(�����÷ο�� ����...���ص� ok)
	if (head == NULL) {
		printf("����!!!!!!");
		return NULL;
	}
	ListNode* removed = head;	//�ణ temp �����̱�...
	head = head->link;	
	free(removed);
	return head;
}

ListNode* search_list(ListNode* head, element x) {
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link;	//link(Ư: �ּ���)�� ���� ���� ����...(p�� ���� �� �ٽ� while�� �ݺ��ϹǷ�)
	}
}

int main(void) {
	
	ListNode* head = NULL; //����� ���� �ּ�...�ּҰ��� ���� ���� NULL
	
	head = insert_first(head, 10);	//��� ������ �� ��带 �߰�	
	head = insert_first(head, 20);
	head = insert_first(head, 30);
	//30->20->10

	print_list(head);	

	head = delete_first(head);	//��� ���� ��带 ����
	//20->10

	//��� Ž���ϱ�(�߰��� ���� / �����ϱ� ���ؼ��� Ž���� ���� �ؾ��ؿ�...ã�Ƽ� �����ϴ� �ڵ���� �߰� ���� �� ����)
	if (search_list(head, 40)==NULL) {
		printf("����Ʈ�� ���� �����...!!!\n");
	}
	else {
		printf("����Ʈ�� ���� �־��^^Ǫ����~\n");
	}

	return 0;
}

//����? ...
//Ű���� ���� ������^^(����)