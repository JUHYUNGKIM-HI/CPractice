//
//  linkedList.h
//  linkedList
//
//  Created by 김주형 on 2021/06/17.
//

#ifndef linkedList_h
#define linkedList_h

#include <stdbool.h>

typedef int Element; // 노드안의 데이터 항목의 자료형


//노드 구조체
typedef struct {
    Element data;
    struct Node* next;
}Node;


// 단일 연결 리스트 구조체
// 연결 리스트의 첫 항목을 가리키는 포인터 변수와, 리스트의 노드 개수를 가지고 있다.
typedef struct{
    Node* head; // 리스트의 첫 항목을 가르키는 포인터 변수
    int size; // 노드의 갯수
}LinkedList;


void init(LinkedList* list); // 리스트 생성 및 초기화
int getSize(LinkedList* list); // 리스트의 크기
void addPos(LinkedList* list, int pos, Element data); // 리스트의 원하는 위치에 추가
void addFirst(LinkedList* list, Element data); // 리스트의 처음에 항목 추가
void addLast(LinkedList* list, Element data); // 리스트의 끝에 항목 추가
Node* create(Element data, Node* next); // 노드를 동적으로 생성(할당)하는 함수가 필요하다.

void Remove(LinkedList* list, Element data); // 리스트에서 항목 삭제
void print(LinkedList* list); // 리스트 출력
void dispose(LinkedList* list); // 리스트의 모든 항목 삭제

bool isEmpty(LinkedList* list); //  리스트가 비어있는지 체크
bool isInList(LinkedList* list, Element elem); // 리스트에 원하는 항목이 있는지 체크

#endif /* linkedList_h */
