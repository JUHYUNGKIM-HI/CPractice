//
//  main.c
//  arrayList
//
//  Created by 김주형 on 2021/06/14.
//

#include <stdio.h>
#include "arrayList.h"

int main() {
    init();
    print();
    
    for(int i = 0; i < 10; i++){
        addLast(i);
    }
    print();
    
    Remove(3);
    print();
    
    addLast(10);
    print();
    
    Remove(3);
    Remove(5);
    Remove(7);
    print();
    
    addPos(0, 8);
    print();
    
    addPos(1, 20);
    print();
    
    Remove(1);
    print();
    
    printf("the number of elements : %d\n", getSize());
    printf("%d is %d-th item\n", 4, whereIsInList(4));
}
