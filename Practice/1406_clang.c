#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

typedef struct NODE {
	char data;
	struct NODE* next;	//next link
	struct NODE* prev;	//prev link
}node;

typedef struct __list {
	node* head;
	node* tail;
	node* cur;
}list;


void insertNode(list* L, char key) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->next = newNode->prev = NULL;
	newNode->data = key;

	if (L->head == NULL) { //ó�� ������ ���
		L->head = L->cur = L->tail = newNode; /*����*/
	}
	else { //��尡 �ִ� ���
		//1) head ����
		if (L->head != NULL && L->cur == NULL) {
			newNode->next = L->head;
			L->head->prev = newNode;
			L->head = newNode;
		}
		//2) tail ����
		else if (L->cur->next == NULL) {
			L->cur->next = newNode;
			newNode->prev = L->cur;
			L->tail = newNode;
		}
		//3) middle ����
		else {
			newNode->prev = L->cur;
			newNode->next = L->cur->next;
			L->cur->next->prev = newNode;
			L->cur->next = newNode;
		}

		//cur ��ġ ����
		L->cur = newNode;
	}
}

//������ ����
void deleteNode(list* L) {
	//����Ʈ�� ��� X
	if (L->head == NULL) return;

	//���� �� �� Ŀ���� ���
	if (L->cur == NULL) return;

	//����Ʈ�� ��� 1��
	if (L->head->next == NULL) {
		L->head = L->tail = L->cur = NULL;
		/*free(L->head);
		free(L->tail);
		free(L->cur);*/
	}
	//����Ʈ�� ��� ������
	else {
		//1) tail ����
		if (L->cur->next == NULL) {
			L->cur->prev->next = NULL;
			L->tail = L->cur->prev;
			L->cur = L->cur->prev;
		}
		//2) head ����
		else if (L->cur->prev == NULL) {
			L->cur->next->prev = NULL;
			L->head = L->cur->next;
			L->cur = NULL;	//head�� ��� �����ϸ� Ŀ�� �� �տ� ��ġ
		}
		//4) middle ����
		else {
			L->cur->next->prev = L->cur->prev;
			L->cur->prev->next = L->cur->next;
			L->cur = L->cur->prev;
		}
	}
}


//'<' ���� �̵� / head ������ ���� ��� cur=  NULL
void moveLeft(list* L) {
	//��� ���� ���
	if (L->head == NULL) return;
	//Ŀ�� �� ���� ���
	else if (L->cur == NULL) return;
	else {
		if (L->cur->prev == NULL) {
			L->cur = NULL;
		}
		else {
			L->cur = L->cur->prev;
			//printf("���� Ŀ�� ��ġ[%c]\n", L->cur->data);
		}
	}
}

//'>' ������ �̵� / tail ���������� cur = tail���� ����
void moveRight(list* L) {
	//��� ���� ���
	if (L->head == NULL) return;
	else {
		//���� �ִµ� �� �տ� Ŀ�� ��ġ�� ���
		if (L->cur == NULL && L->head != NULL) {
			L->cur = L->head;
			return;
		}

		//Ŀ�� �� ���� ��ġ�� ���
		if (L->cur->next != NULL) {
			L->cur = L->cur->next;
			//printf("���� Ŀ�� ��ġ[%c]\n", L->cur->data);
		}
	}
}


void printNode(list* L) {
	node* cur = L->head;	//���� node

	while (cur != NULL) {
		printf("%c", cur->data);
		cur = cur->next;
	}
}

void password(char* code) {
	//Linked List �ʱ�ȭ
	list* L = (list*)malloc(sizeof(list));
	L->head = NULL;
	L->tail = NULL;
	L->cur = NULL;

	int len = strlen(code);
	for (int i = 0; i < len; i++) {
		switch (code[i]) {
		case '<':
			moveLeft(L);
			break;
		case '>':
			moveRight(L);
			break;
		case '-':
			deleteNode(L);
			break;
		default:
			insertNode(L, code[i]);
			break;
		}
	}
	printNode(L);
	printf("\n");

	free(L);
}


int main() {
	int N;
	scanf(" %d", &N);

	char** code = (char**)malloc(sizeof(char*) * N);
	

	for (int i = 0; i < N; i++) {
		code[i] = (char*)malloc(sizeof(char) * 1000000);
		scanf("%s", code[i]);
		password(code[i]);
	}

	for (int i = 0; i < N; i++) {
		free(code[i]);
	}

	free(code);
	return 0;
}