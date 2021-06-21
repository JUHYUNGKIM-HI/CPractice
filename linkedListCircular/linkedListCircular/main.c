//
//  main.c
//  linkedListCircular
//
//  Created by 김주형 on 2021/06/21.
//

#include <stdio.h>
#include "linkedListCircular.h"

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    LinkedList list;
    init(&list);
    print(&list);
    
    for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++){
        add(&list, data[i]);
        print(&list);
    }
}
