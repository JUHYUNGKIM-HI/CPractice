//
//  arrayList2.c
//  arrayList2
//
//  Created by 김주형 on 2021/06/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> //  sorting 함수의 구현에서 floor() 함수를 위해서
#include "arrayList2.h"


void init(ArrayList* list){
    list->size = 0;
}


bool isEmpty(const ArrayList* list){
    return (list->size == 0);
}


bool isFull(const ArrayList* list){
    return (list->size == MAX_LIST_SIZE);
}


void print(const ArrayList* list){
    for(int i = 0; i < MAX_LIST_SIZE; i++){
        printf("%d ", list->buf[i]);
    }
    printf("\n");
}


bool isInList(const ArrayList* list, Element elem){
    for(int i = 0; i < list->size; i++){
        if(list->buf[i] == elem) return true;
    }
    return false;
}


int getSize(const ArrayList* list){
    return list->size;
}


void addLast(ArrayList* list, Element elem){
    if(!isFull(list)){
        list->buf[list->size] = elem;
        list->size++;
    }
    else printf("ERROR : List is Full\n");
}


void addPos(ArrayList *list, int pos, Element elem){
    if(!isFull(list) && pos >= 0 && pos <= list->size){
        for(int i = list->size - 1; i >= pos; i--){
            list->buf[i + 1] = list->buf[i];
        }
        list->buf[pos] = elem;
        list->size++;
    }
    else
        printf("ERROR : List is Full or Position Error\n");
}


void Remove(ArrayList* list, Element elem){
    if(!isInList(list, elem)){
        printf("Not exist\n");
        return;
    }
    
    if(!isEmpty(list)){
        for(int i = 0; i < list->size; i++){
            if(list->buf[i] == elem){
                for(int j = i + 1; j < list->size; j++){
                    list->buf[j - 1] = list->buf[j];
                }
                list->size--;
                return;
            }
        }
    }
    else
        printf("ERROR : List Empty\n");
}


// 정렬되지 않은 배열에서의 순차 검색
int searchLinear(const ArrayList* list, Element elem){
    for(int i = 0; i < list->size; i++){
        if(list->buf[i] == elem) return i;
    }
    return -1;
}


//  정렬된 배열에서의 순차 검색
int searchLinearOnSorted(const ArrayList* list, Element elem){
    for(int i = 0; i < list->size; i++){
        if(list->buf[i] == elem) return i;
        else if(list->buf[i] > elem) return -1;
    }
    return -1;
}


//  정렬된 배열에서의 이진 검색
int searchBinaryOnSorted(const ArrayList* list, Element elem){
    int first = 0;
    int last = list->size - 1;
    
    while(first <= last){
        int middle = (int)floor((first + last) / 2);
        
        if(list->buf[middle] == elem)
            return middle;
        else if(list->buf[middle] < elem)
            first = middle + 1;
        else
            last = middle - 1;
    }
    return -1;
}


//  정렬된 배열에서의 재귀 함수를 이용한 이진 검색
int searchBinaryOnSortedRecursively(const ArrayList* list, Element elem, int first, int last){
    if(last >= first){
        int middle = (int)floor((first + last) / 2);
        
        if(list->buf[middle] == elem)
            return middle;
        else if(list->buf[middle] < elem)
            return searchBinaryOnSortedRecursively(list, elem, middle + 1, last);
        else
            return searchBinaryOnSortedRecursively(list, elem, first, middle - 1);
    }
    return -1;
}


// c 언어에서 제공하는 이진 검색
int cmpfunc4Search(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

bool searchByC(const ArrayList* list, Element elem){
    int *result = (int*)bsearch(&elem, list->buf, list->size, sizeof(int), cmpfunc4Search);
    
    if(result) return true;
    else return false;
}


//  직접 구현한 선택 정렬 함수
void sort(ArrayList* list){
    Element temp;
    
    //  리스트가 비어있으면 정렬할 필요가 없으니 return
    if(isEmpty(list)) return;
    
    for(int i = 0; i < list->size - 1; i++){
        int jmin = i;
        for(int j = i + 1; j < list->size; j++){
            if(list->buf[j] < list->buf[jmin]){
                jmin = j;
            }
        }
        if(jmin != i){
            temp = list->buf[i];
            list->buf[i] = list->buf[jmin];
            list->buf[jmin] = temp;
        }
    }
    return;
}

//  C 언어에서 제공하는 Quick Sorting 함수 사용
int cmpfunc4Sort(const void* a, const void* b){
    return (*(int*)a > *(int*)b);
}

void sortByC(ArrayList* list){
    qsort(list->buf, list->size, sizeof(int), cmpfunc4Sort);
}
