//
//  stack.h
//  stack
//
//  Created by 김주형 on 2021/07/28.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 5

typedef int Element; // 리스트도 int형이다.

typedef struct{
    Element stack[MAX_STACK_SIZE];
    int top;
}Stack;

void init(Stack *s);
bool isEmpty(const Stack *s);
bool isFull(const Stack *s);
void push(Stack *s, Element item);
Element pop(Stack *s);
Element top(const Stack *s);

#endif /* stack_h */
