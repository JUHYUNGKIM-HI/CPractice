//
//  linkedListCircular.c
//  linkedListCircular
//
//  Created by 김주형 on 2021/06/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linkedListCircular.h"


void init(LinkedList* list){
    list->size = 0;
    list->head = NULL;
}


bool isEmpty(const LinkedList* list){
    if(list->head == NULL) return true;
    else return false;
}


// 함수명 : void print(const LinkedList* list)
// 설명 : 원형 리스트를 출력하는 함수
// 리턴값 : void
// 매개변수 : const LinkedList* list : 연결 리스트의 헤더 노드
void print(const LinkedList* list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }
    
    Node* cursor = list->head;
    do{
        printf("--> %d ", cursor->next->data);
        cursor = cursor->next;
    }while(cursor != list->head); // 원형 리스트의 끝을 판별하기 위해서
    printf("\n");
}


// 함수명 : bool isInList(LinkedList* list, Element elem)
// 설명 : 리스트에 원하는 항목이 있는지 검색
// 리턴값 : bool
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 노드
//         Element elem : 찾고자 하는 값
bool isInList(LinkedList* list, Element elem){
    if(list->head == NULL){
        return false;
    }
    
    Node* cursor = list->head;
    do{
        if(IS_EQUAL(cursor->next->data, elem)) return true;
        cursor = cursor->next;
    }while (cursor != list->head);
    return false;
}


// 설명 : 새로운 노드를 생성한다.
// 리턴값 : Node*
// 매개변수 : Elememt e : 추가될 데이터
//         Node* : 생성된 노드가 가르킬 포인터 값(보통은 NULL)
Node* create(Element e, Node* next){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error : creating a new node.\n");
        exit(1);
    }
    newNode->data = e;
    newNode->next = next;
    return newNode;
}


// 함수명 : void add(Linkedlist* list, Element data)
// 설명 : 마지막에 새로운 노드를 추가하는 함수
// 리턴값 : void
// 매개변수 : LinkedList* list : 연결 리스트의 헤더 함수
//         Element data : 추가하고자 하는 값
void add(LinkedList* list, Element data){
    Node* newNode = (Node*)malloc(sizeof(newNode));
    if(newNode == NULL){
        printf("Error : Memory Allocation Error\n");
        exit(0);
    }
    newNode->data = data;
    
    if(list->head == NULL){
        list->head = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = list->head->next;
        list->head->next = newNode;
        list->head = newNode;
    }
    (list->size)++;
}
