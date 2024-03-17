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

	if (L->head == NULL) { //처음 들어오는 경우
		L->head = L->cur = L->tail = newNode; /*수정*/
	}
	else { //노드가 있는 경우
		//1) head 삽입
		if (L->head != NULL && L->cur == NULL) {
			newNode->next = L->head;
			L->head->prev = newNode;
			L->head = newNode;
		}
		//2) tail 삽입
		else if (L->cur->next == NULL) {
			L->cur->next = newNode;
			newNode->prev = L->cur;
			L->tail = newNode;
		}
		//3) middle 삽입
		else {
			newNode->prev = L->cur;
			newNode->next = L->cur->next;
			L->cur->next->prev = newNode;
			L->cur->next = newNode;
		}

		//cur 위치 변경
		L->cur = newNode;
	}
}

//마지막 삭제
void deleteNode(list* L) {
	//리스트에 노드 X
	if (L->head == NULL) return;

	//현재 맨 앞 커서인 경우
	if (L->cur == NULL) return;

	//리스트에 노드 1개
	if (L->head->next == NULL) {
		L->head = L->tail = L->cur = NULL;
		/*free(L->head);
		free(L->tail);
		free(L->cur);*/
	}
	//리스트에 노드 여러개
	else {
		//1) tail 삭제
		if (L->cur->next == NULL) {
			L->cur->prev->next = NULL;
			L->tail = L->cur->prev;
			L->cur = L->cur->prev;
		}
		//2) head 삭제
		else if (L->cur->prev == NULL) {
			L->cur->next->prev = NULL;
			L->head = L->cur->next;
			L->cur = NULL;	//head의 경우 삭제하면 커서 맨 앞에 위치
		}
		//4) middle 삭제
		else {
			L->cur->next->prev = L->cur->prev;
			L->cur->prev->next = L->cur->next;
			L->cur = L->cur->prev;
		}
	}
}


//'<' 왼쪽 이동 / head 끝까지 가는 경우 cur=  NULL
void moveLeft(list* L) {
	//노드 없는 경우
	if (L->head == NULL) return;
	//커서 맨 앞인 경우
	else if (L->cur == NULL) return;
	else {
		if (L->cur->prev == NULL) {
			L->cur = NULL;
		}
		else {
			L->cur = L->cur->prev;
			//printf("현재 커서 위치[%c]\n", L->cur->data);
		}
	}
}

//'>' 오른쪽 이동 / tail 끝까지가도 cur = tail값을 유지
void moveRight(list* L) {
	//노드 없는 경우
	if (L->head == NULL) return;
	else {
		//노드는 있는데 맨 앞에 커서 위치한 경우
		if (L->cur == NULL && L->head != NULL) {
			L->cur = L->head;
			return;
		}

		//커서 맨 끝에 위치한 경우
		if (L->cur->next != NULL) {
			L->cur = L->cur->next;
			//printf("현재 커서 위치[%c]\n", L->cur->data);
		}
	}
}


void printNode(list* L) {
	node* cur = L->head;	//시작 node

	while (cur != NULL) {
		printf("%c", cur->data);
		cur = cur->next;
	}
}

void password(char* code) {
	//Linked List 초기화
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