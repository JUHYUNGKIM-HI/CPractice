//
//  main.c
//  linkedListDoubly
//
//  Created by 김주형 on 2021/06/21.
//

#include <stdio.h>
#include "linkedListDoubly.h"

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    LinkedListDoubly list;
    init(&list);
    
    print(&list, 1);
    for(int i = 0; i < sizeof(data) / sizeof(int); i++){
        addFirst(&list, data[i]);
        print(&list, FORWARD);
    }
    print(&list, BACKWARD);
    return 0;
}
