//
//  main.c
//  arrayList2
//
//  Created by 김주형 on 2021/06/14.
//

#include <stdio.h>
#include "arrayList2.h"

int main() {
    ArrayList data;
    
    init(&data);
    print(&data);
    
    addLast(&data, 1);
    addLast(&data, 2);
    addLast(&data, 3);
    print(&data);
    
    Remove(&data, 3);
    print(&data);
    
    Remove(&data, 1);
    addLast(&data, 13);
    addLast(&data, 33);
    addLast(&data, 37);
    addLast(&data, 15);
    addLast(&data, 21);
    
    print(&data);
    
    printf("%d is %d-th item.\n", 2, searchLinear(&data, 2));
    
    sortByC(&data);
    print(&data);
    
    printf("%d is %d-th item.\n", 2, searchLinearOnSorted(&data, 2));
    printf("%d is %d-th item.\n", 2, searchBinaryOnSorted(&data, 2));
    printf("%d is %d-th item.\n", 2, searchBinaryOnSortedRecursively(&data, 2, 0, data.size));
    
    
    printf("%d is %d-th item.\n", 37, searchLinearOnSorted(&data, 37));
    printf("%d is %d-th item.\n", 37, searchBinaryOnSorted(&data, 37));
    printf("%d is %d-th item.\n", 37, searchBinaryOnSortedRecursively(&data, 37, 0, data.size));
    
    
    printf("%d is %d-th item.\n", 32, searchLinearOnSorted(&data, 32));
    printf("%d is %d-th item.\n", 32, searchBinaryOnSorted(&data, 32));
    printf("%d is %d-th item.\n", 32, searchBinaryOnSortedRecursively(&data, 32, 0, data.size));
    
    
    if(searchByC(&data, 2)) printf("%d exist.\n", 2);
    else printf("%d is not exist.\n", 2);
}
