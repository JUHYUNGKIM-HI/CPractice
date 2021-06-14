//
//  main.c
//  sparseMatrixAdvanced
//
//  Created by 김주형 on 2021/06/12.
//

#include <stdio.h>
#include "sparseMatrixAdvance.h"

int main() {
    //  배열을 초기화하고 set() 함수로 값을 대입
    int data1[4][5] =
    {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    
    int data2[4][5] =
    {
        {1, 0, 0, 0, 4},
        {0, 3, 0, 7, 0},
        {0, 0, 2, 2, 0},
        {0, 2, 0, 0, 0}
    };
    
    SparseMatrix* sp1 = create(4, 5, (int *)data1);
    print(sp1);
    printOriginal(sp1);
    
    printf("value of [%d][%d] : %d\n", 0, 2, get(sp1, 0, 2));
    
    printf("after changing Array[0][2] into 10\n");
    set(sp1, 0, 2, 10);
    print(sp1);
    printOriginal(sp1);
    
    printf("after inserting Array[2][1] as 20\n");
    set(sp1, 2, 1, 20);
    print(sp1);
    printOriginal(sp1);
}
