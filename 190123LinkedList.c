#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* previous;
	struct node* next;
}Node;
typedef struct list {
	struct node* head; //struct node head?
	struct node* tail;
	int size;
}List;

List* initList(); //List*
void add(List** list, int index, int data); 
void addFirst(List** list, int data);
void addLast(List** list, int data);
Node* removeNode(List** list, int index);
Node* removeFirstNode(List** list);
Node* removeLastNode(List** list);
void removeAll(List** list);
int size(List** list); 
void printAll(List** list);
void println();
void increaseSize(List** list);
void decreaseSize(List** list);
int IsEmpty(List** list);
int isIndexZero(int index);

int main(void) {
	List* list = initList();
	
	add(&list, 0, 10);
	add(&list, 1, 20);
	add(&list, 2, 30);
	add(&list, 3, 40);
	add(&list, 4, 50);
	add(&list, 5, 60);
	add(&list, 6, 70);
	printAll(&list);
	free(removeNode(&list, 0));
	printAll(&list);
	free(removeNode(&list, 3));
	printAll(&list);
	free(removeNode(&list, 1));
	printAll(&list);
	free(removeNode(&list, 2));
	printAll(&list);
	printf("%d",size(&list));
	println();
	removeAll(&list);
	printAll(&list);
	return 0;
}
List* initList() {
	List* list= (List*)malloc(sizeof(List));
	list->head = NULL; //이것도 모르겠다 List** List* 이게 너무 헷갈린다.
	list->tail = NULL;
	list->size = 0;
	
	return list;
}
void add(List** list, int index, int data) {
	if (!(*list)) {
		printf("list is null");
		return;
	}
	if (isIndexZero(index) && IsEmpty(list)) { //맨처음생성
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->previous = NULL;
		newNode->next = NULL;
		(*list)->head = newNode;
		(*list)->tail = newNode;
		increaseSize(list);
	}
	
	else if (isIndexZero(index)) { //인덱스가 0일경우 노드생성
		addFirst(list, data);
	}
	
	else if(index == size(list)){ //맨끝에 노드생성
		addLast(list, data);
	}
	else {  //중간에 생성
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		Node* tmp = (*list)->head;
		for (int i = 0; i < index-1; i++) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		newNode->previous = tmp;
		tmp->next = newNode;
		increaseSize(list);
	}
}
void addFirst(List** list, int data) { //맨 앞에 노드생성
	if (IsEmpty(list)) { //add함수의 두번째 if문으로 이동
		add(list,0,data);
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->previous = NULL;
	newNode->next = (*list)->head;
	(*list)->head->previous = newNode;
	(*list)->head = newNode;
	increaseSize(list);
}
void addLast(List** list, int data) { //맨 뒤에 노드생성
	if (IsEmpty(list)) { //add함수의 두번째 if문으로 이동
		add(list, 0, data);
		return;
	}
	//Node* tail = (*list)->tail;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->previous = (*list)->tail;
	newNode->next = NULL;
	(*list)->tail->next = newNode;
	(*list)->tail = newNode;
	increaseSize(list);
}
Node* removeNode(List** list, int index) { 
	if (!(*list)) { //리스트가 없는 경우
		printf("list is null");
		println();
		exit(1);
	}
	if (index == -1) { //데이터가 빈 경우 //걍 -1으로해도 되나?
		printf("data is empty");
		println();
		exit(1);
	}
	if (size(list) <= index) { //데이터 사이즈보다 인덱스가 큰경우
		printf("invalid index");
		exit(1);
	}
	if (isIndexZero(index)) { //인덱스가 0일경우 removefirst호출
		removeFirstNode(list);
	}
	else if (index+1 == size(list)) { //인덱스가 마지막노드를 가리킬경우 removelast호출
		removeLastNode(list);
	}
	else { //중간일 경우
		Node* del = (*list)->head;
		for (int i = 0; i < index; i++) {
			del = del->next;
		}
		/*Node *prev = del->previous;
		prev->next = del->next;
		Node *next = del->next;
		next->previous = prev;*/
		del->previous->next = del->next;
		del->next->previous = del->previous;
		decreaseSize(list);
		return del;
	}
}
Node* removeFirstNode(List** list) {
	if (!(*list)) {
		removeNode(list, -1); 
	}
	if (IsEmpty(list)) {
		removeNode(list, -1);
	}
	Node* del = (*list)->head;
	(*list)->head = (*list)->head->next;
	decreaseSize(list);
	return del;
}
Node* removeLastNode(List** list) {
	if (!(*list)) {
		removeNode(list, -1);
	}
	if (IsEmpty(list)) {
		removeNode(list, -1);
	}
	Node* del = (*list)->tail;
	(*list)->tail = (*list)->tail->previous;
	decreaseSize(list);
	return del;
}
void removeAll(List** list) {
	if (!(*list)) {
		printf("list is null");
		return;
	}
	if (IsEmpty(list)) {
		printf("data is empty");
		return;
	}
	/*int num = size(list);
	for (int i = 1; i < num--;) { //case1
		Node* tmp = (*list)->head;
		(*list)->head = tmp->next;
		free(tmp);
	}*/
	/*for (int i = 1; i < size(list); i++) { //case2
		Node* tmp = (*list)->head;
		(*list)->head = tmp->next;
		free(tmp);
	}*/
	for (int i = 1; i < (*list)->size--;) {
		Node* tmp = (*list)->head;
		(*list)->head = tmp->next;
		free(tmp);
	}
}
int size(List** list) {
	return (*list)->size;
}
void printAll(List** list) { 
	if (IsEmpty(list)) { //리스트가 빈 경우
		printf("data is empty");
		return;
	}
	if (!list) { //리스트가 널인 경우
		printf("list is empty");
		return;
	}
	Node* tmp = (*list)->head;
	for (int i = 0; i < size(list); i++) { //size-1이 아니다. 확인해볼것
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	println();
}
void println() {
	printf("\n");
}
void increaseSize(List** list) {
	(*list)->size++;
}
void decreaseSize(List** list) {
	(*list)->size--;
}
int IsEmpty(List** list) {
	return (*list)->size == 0;
}
int isIndexZero(int index) {
	return index == 0;
}
