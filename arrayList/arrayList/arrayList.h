//
//  arrayList.h
//  arrayList
//
//  Created by 김주형 on 2021/06/14.
//

#ifndef arrayList_h
#define arrayList_h

#include <stdbool.h>

#define MAX_LIST_SIZE 10

typedef int Element; // 리스트 항목의 자료형을 int로 설정

//  배열 리스트를 위한 구조체. 배열과 배열의 크기를 가진다.
typedef struct{
    Element buf[MAX_LIST_SIZE];
    int size;
}ArrayList;

void init();
bool isEmpty();
bool isFull();
void print();
bool isInList(Element elem);
int whereIsInList(Element elem);
int getSize();
void addLast(Element elem);
void addPos(int pos, Element elem);
void Remove(Element elem);


#endif /* arrayList_h */
