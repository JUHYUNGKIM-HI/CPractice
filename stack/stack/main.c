//
//  main.c
//  stack
//
//  Created by 김주형 on 2021/07/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int main() {
    Stack s;
    int data[] = {10, 5, 8, 1, 6};
    
    init(&s);
    
    for(int i = 0; i < 5; i++){
        push(&s, data[i]);
        printf("Top : %d\n", top(&s));
    }
    
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    
    //stack이 empty이기 때문에 에러가 발생한다.
    printf("%d\n", pop(&s));
}
