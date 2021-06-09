//
//  test1.c
//  Array
//
//  Created by 김주형 on 2021/06/08.
//

#include <stdio.h>
#include "array.h"

int main()
{
    int data[MAX_SIZE] = {23, 42, 52, 12, 5, 19, 100, 33, 54, 2};
    
    print(data);
    
    printf("%d\n", isInArray(data, 12));
    
    printf("%d\n", isInArray(data, 11));
    
    printf("MAX : %d\n", max(data));
    
    printf("MIN : %d\n", min(data));
    
    printf("AVG : %f\n", avg(data));
}

