//
//  linkedList.c
//  linkedList
//
//  Created by 김주형 on 2021/06/17.
//


#include <stdio.h>
#include <stdlib.h> // 동적 메모리 할당(malloc, free)를 위해
#include "linkedList.h"

#define IS_EQUAL(a, b) (a == b)

// 설명 : 단일 연결 리스트를 초기화 한다. head 노드를 NUELL, size를 0으로 설정
// 리턴값 : void
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 노드
void init(LinkedList* list){
    list->head = NULL;
    list->size = 0;
}


// 설명 : 연결 리스트의 노드 개수 반환
// 리턴값 : int(리스트의 크기)
// 매개변수 :LinkedList* list : 연결 리스트의 헤더 노드
int getSize(LinkedList* list){
    return list->size;
}


// 설명 : 리스트의 정해진 위치에 노드를 추가한다.
// 리턴값 : void
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 노드
//         int pos : 항목이 추가될 위치
//         Element data : 추가될 항목
// 비고 : pos 위치가 리스트 내부의 위치인지 점검 필요
//       리스트의 첫번째 항목으로 추가하는지에 따라 다르게 처리해야 한다.
void addPos(LinkedList* list, int pos, Element data){
    if(pos > (list->size) + 1 || pos < 1){
        printf("Error : Position is out of range!\n");
        exit(1);
    }
    else{
    // 노드를 생성하고
    Node* newNode = create(data, NULL);
    
        // 리스트의 처음에 추가하려면
        if(pos == 1){
            // head가 가르키던 노드를 추가될 새로운 노드가 가르키게 하고
            newNode->next = list->head;
            // head가 새로운 노드를 가르키게 된다.
            list->head = newNode;
        }
    
        // 리스트의 처음이 아닌 곳에 추가하려면
        else{
            //pos 이전 위치까지 탐색해서 추가될 위치를 찾아간 후에
            Node* temp = list->head;
            for(int i = 1; i < pos - 1; i++)
                temp = temp->next;
            
            // temp 노드 다음에 추가될 것이라서, 새로운 노드가 temp가 가르키는 노드를 가르키게 하고
            newNode->next = temp->next;
            
            // temp가 새로운 노드를 가르키게 한다.
            temp->next = newNode;
        }
    (list->size)++; // 항목의 개수를 1증가
    }
}


// 설명 : 리스트의 가장 앞에 노드를 추가한다.
// 리턴값 : void
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 노드
//         Element data : 추가될 항목
void addFirst(LinkedList* list, Element data){
    addPos(list, 1, data);
}


// 설명 : 리스트의 가장 뒤에 노드를 추가한다.
// 리턴값 : void
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 노드
//         Element data : 추가될 항목
void addLast(LinkedList* list, Element data){
    addPos(list, (list->size) + 1, data);
}


// 설명 : 새로운 노드를 추가한다.
// 리턴값 : Node*
// 매개변수 : Element* : 추가될 데이터
//          Node* : 생성될 노드가 가르킬 포인터 값(보통은 NULL)
Node* create(Element data, Node* next){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error : create a new node\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = next;
    
    return newNode;
}


// 설명 : 리스트에서 원하는 항목 1개를 찾아서 삭제한다.
// 리턴값 : void
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 노드
// 비고 : 리스트의 첫 노드는 조금 특수하게 처리한다.
//       리스트가 empty거나 elem이 없으면 아무 일도 일어나지 않는다.
void Remove(LinkedList* list, Element elem){
    Node* cursor = list->head;
    Node* prev = NULL;
    
    if(IS_EQUAL(cursor->data, elem)){ // 삭제할 노드가 첫 노드이면
        list->head = cursor->next; // head가 삭제될 노드의 다음 노드를 가르키게 한다.
        free(cursor); // 삭제할 노드를 해제한다.
        (list->size)--;
    }
    else{
        // 삭제할 노드를 찾아서 cursor가 가르키게 한다.
        while(cursor != NULL){
            if(IS_EQUAL(cursor->data, elem))break;
            prev = cursor;
            cursor = cursor->next;
        }
        // 삭제할 노드가 있으면, 해당 노드를 삭제한다.
        if(cursor != NULL){
            prev->next = cursor->next;
            free(cursor);
            (list->size)--;
        }
    }
}


// 설명 : 단일 연결 리스트의 모든 노드들의 메모리를 해제한다.
// 리턴값 : void
// 매개변수 : LikedList* list : 연결 리스트의 헤더 노드
void dispose(LinkedList* list){
    Node* temp;
    Node* cursor = list->head;  // cursor는 head 노드부터 NULL이 될때까지 리스트를 순서대로 탐방
    list->head = NULL;
    
    while(cursor != NULL){
        temp = cursor->next; // 아래 줄에서 cursor가 가르키는 노드를 해제할 것이라서 temp에 보관
        free(cursor);
        cursor = temp;
    }
    list->size = 0;
}


// 설명 : 단일 연결 리스트가 Empty인지 반환. 단일 연결 리스트가 비어있으면 true를 반환, 그렇지 않으면 false를 반환
// 리턴값 : bool
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 노드
// 비고 : 리스트의 헤더 노드의 size 멤버 변수의 값을 보고 판단할 수 있다.
bool isEmpty(LinkedList* list){
    return (list->head == NULL);
}


// 설명 : 단일 연결 리스트에서 원하는 항목을 검색
// 리턴값 : bool
// 매개변수 : Linkedlist* list : 연결 리스트의 헤더 노드
//          Element elem : 검색을 원하는 값
bool isInList(LinkedList* list, Element elem){
    Node* cursor = list->head;
    while(cursor != NULL){
        if(IS_EQUAL(cursor->data, elem)) return true;
        cursor = cursor->next;
    }
    return false;
}


// 설명 : 연결 리스트 출력
// 리턴값 : void
// 매개변수 : Linkedlist* list : 연결 리스트의 헤더 노드
void print(LinkedList* list){
    Node* current = list->head;
    while(current != NULL){
        printf("--> %d", current->data);
        current = current->next;
    }
    printf("\n");
}
