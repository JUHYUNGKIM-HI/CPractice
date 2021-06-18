//
//  main.c
//  linkedList
//
//  Created by 김주형 on 2021/06/17.
//

#include <stdio.h>
#include "linkedList.h"

int main() {
    LinkedList list;
    
    init(&list);
    print(&list);
    
    addFirst(&list, 10);
    print(&list);
    
    addFirst(&list, 20);
    print(&list);
    
    addPos(&list, 1, 30);
    print(&list);
    
    addPos(&list, 2, 40);
    print(&list);
    
    addLast(&list, 50);
    print(&list);
    
    Remove(&list, 20);
    print(&list);
    
    Remove(&list, 10);
    print(&list);
    
    Remove(&list, 50);
    print(&list);
    
    Remove(&list, 30);
    print(&list);
    
    addFirst(&list, 90);
    print(&list);
    
    addPos(&list, 10, 80);
    print(&list);
    
    dispose(&list);
    print(&list);
}
