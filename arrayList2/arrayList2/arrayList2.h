//
//  arrayList2.h
//  arrayList2
//
//  Created by 김주형 on 2021/06/14.
//

#ifndef arrayList2_h
#define arrayList2_h

#include <stdio.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 10

typedef int Element; // 리스트 항목의 자료형을 int로 설정

//  배열 리스트를 위한 구조체. 배열과 배열의 크기를 가진다.
typedef struct{
    Element buf[MAX_LIST_SIZE];
    int size;
}ArrayList;

void init(ArrayList* list);
bool isEmpty(const ArrayList* list);
bool isFull(const ArrayList* list);
void print(const ArrayList* list);
bool isInList(const ArrayList* list, Element elem);
void addLast(ArrayList* list, Element elem);
void addPos(ArrayList* list, int pos, Element elem);
void Remove(ArrayList* list, Element elem);


//  검색 함수
int searchLinear(const ArrayList* list, Element elem);
int searchLinearOnSorted(const ArrayList* list, Element elem);
int searchBinaryOnSorted(const ArrayList* list, Element elem);
int searchBinaryOnSortedRecursively(const ArrayList* list, Element elem, int first, int last);
bool searchByC(const ArrayList* list, Element);


//  정렬 함수
void sort(ArrayList* list);
void sortByC(ArrayList* list);

#endif /* arrayList2_h */
