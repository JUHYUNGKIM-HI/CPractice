//
//  stack.c
//  stack
//
//  Created by 김주형 on 2021/07/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


//설명 : 스택을 초기화 한다.
//리턴값 : void
//매개변수 : Stack* s :스택 포인터
void init(Stack *s){
    s->top = -1;
}


//설명 : 스택이 비어있는지 검사한다.
//리턴값 : bool(스택이 empty이면 true)
//매개변수 : Stack *s : 스택 포인터
bool isEmpty(const Stack *s){
    return(s->top == -1);
}


// 설명 : 스택의 full인지 검사한다.
// 리턴값 : bool(스택이 fulldlaus true)
// 매개변수 : Stack* s: 스택 포인터
bool isFull(const Stack* s){
    return (s->top == (MAX_STACK_SIZE -1));
}


// 설명 : 스택에 새로운 항목을 추가한다.
// 리턴값 : void
// 매개변수 : Stack* s: 스택 포인터
//         Element item : 추가될 항목
// 비고 : exit() 함수는 에러 발생 시에 프로그램을 종료한다. stdlib.h 헤더 파일을 사용한다.
void push(Stack *s, Element item){
    if(isFull(s)){
        printf("Error : Stack Full\n");
        exit(1);
    }
    else{
        s->top++;
        s->stack[s->top] = item;
        //위 두 문장은 다음과 같이 변경할 수 있다.
        //s->stack[++(s->top)];
    }
}

// 설명 : 스택의 top에서 항목 하나를 삭제하고 이를 반환한다.
// 리턴값 : Element
// 매개변수 : Stack* s : 스택 포인터
// 비고 : exit() 함수는 에러 발생시에 프로그램을 종료한다. stdlib.h 헤더 파일을 사용한다.
Element pop(Stack* s){
    if(isEmpty(s)){
        printf("Error : Stack Empty\n");
        exit(1);
    }
    else{
        return s->stack[(s->top)--];
    }
}

// 설명 : 스택의 top에 있는 항목을 반환한다.
// 리턴값 : Element
// 매개변수 : Stack* s : 스택 포인터
// 비고 : exit() 함수는 에러 발생 시에 프로그램을 종료한다. stdlib.h 헤더 파일을 사용한다.
Element top(const Stack* s){
    if(isEmpty(s)){
        printf("Error : Stack Empty\n");
        exit(1);
    }
    else{
        return s->stack[s->top];
    }
}
