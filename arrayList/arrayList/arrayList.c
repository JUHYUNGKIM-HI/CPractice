//
//  arrayList.c
//  arrayList
//
//  Created by 김주형 on 2021/06/14.
//  설명 : 자료구조의 linked list를 포인터를 이용해서 구현


#include <stdio.h>
#include <stdbool.h> // bool 자료형을 사용하기 위해서
#include "arrayList.h"

ArrayList list; //  배열 리스트 변수


//  함수명 : void init()
//  설명 : 배열 리스트 초기화, 항목의 개수를 0으로 초기화
void init(){
    list.size = 0;
}


//  함수명 : bool isEmpty(void)
//  설명 : 리스트가 Empty인지를 반환. 항목이 0개면 true를 반환, 아니면 false를 반환
bool isEmpty(){
    return (list.size == 0);
}

//  함수명 : bool isFull(void)
//  설명 : 리스트가 Full인지를 반환. 항목이 최대 개수이면 true반환, 아니면 false를 반환
bool isFull(){
    return (list.size == MAX_LIST_SIZE);
}


//  함수명 : void print(void)
//  설명 : 리스트의 모든 항목을 순서대로 출력.
void print(){
    for(int i = 0; i < list.size; i++){
        printf("%d -> ", list.buf[i]);
    }
    printf("\n");
}


//  함수명 : bool isInList(Element elem)
//  설명 : 리스트에 원하는 값이 있는지 검사. 있으면 true반환, 없으면 false 반환
bool isInList(Element elem){
    for(int i =0; i < list.size; i++){
        if(list.buf[i] == elem) return true;
    }
    return false;
}


//  함수명 : int whereIsInList(Element elem)
//  설명 : 리스트에 파라미터로 넘겨받은 항목의 위치를 반환. 파라미터로 받은 elem이 리스트에 있으면 그 위치를 반환. 없으면 -1
int whereIsInList(Element elem){
    for(int i = 0; i < list.size; i++){
        if(list.buf[i] == elem) return i;
    }
    return -1;
}

//  함수명 : int getSize()
//  설명 : 리스트의 항목 개수를 반환
int getSize(){
    return list.size;
}


//  함수명 : void addLast(Elemet elem)
//  설명 : 리스트의 끝에 파라미터로 받은 elem을 추가. 항목을 추가할 여유 공간이 있으면 항목을 추가하고 리스트의 크기(list.size)를 1만큼 증가시키니다. 추가할 공간이 없으면 error 출력
void addLast(Element elem){
    if(!isFull()){
        list.buf[list.size] = elem;
        list.size++;
    }
    else printf("Error : List is Full\n");
}


//  함수명 : void addPos(int pos, Element elem)
//  설명 : 리스트의 pos 위치에 파라미터로 받은 elem을 추가한다. pos 위치 이후의 항목들을 한칸씩 뒤로 이동시켜야한다. pos 위치에 elem 항목을 추가하면 리스트의 크기(list.size)를 1증가시킨다.
void addPos(int pos, Element elem){
    //  Full이 아니고 파라미터로 받은 pos 위치가 리스트의 내부이면 추가
    if(!isFull() && pos >= 0 && pos <= list.size){
        //  pos 위치 이후의 항목을 한칸씩 뒤로 옮기고
        for(int i = list.size - 1; i >= pos; i--){
            list.buf[i + 1] = list.buf[i];
        }
        //  pos 위치에 항목 추가
        list.buf[pos] = elem;
        list.size++;
    }
    else printf("Error : List Full or Position Error\n");
}


//  함수명 : void Remove(Element elem)
//  설명 : 파라미터로 받은 elem을 삭제. 존재하지 않으면 에러 출력. 리스트가 비어있으면 return. 삭제된 항목 이후의 항목들은 한 칸씩 앞으로 이동 시켜야 한다. 항목을 삭제하면 리스트의 크기(list.size)를 1 감소
void Remove(Element elem){
    //  삭제한 elem이 없으면 에러 출력
    if(!isInList(elem)){
        printf("Error : not exists\n");
        return;
    }
    
    if(!isEmpty()){
        //  삭제할 항목을 찾아서
        for(int i = 0; i < list.size; i++){
            if(list.buf[i] == elem){
                // 삭제할 항목 이후의 데이터를 한칸씩 앞으로 이동
                for(int j = i + 1; j < list.size; j++){
                    list.buf[j - 1] = list.buf[j];
                }
                list.size--;
                return;
            }
        }
    }
    else
        printf("Error : List Empty\n");
}
