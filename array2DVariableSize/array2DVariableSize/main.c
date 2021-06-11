//
//  main.c
//  array2DVariableSize
//
//  Created by 김주형 on 2021/06/11.
//

#include <stdio.h>
#include "array2DVariableSize.h"

int main() {
    item a[] = {1, 2, 3, 2, 3, 4, 1, 2, 2};
    item b[] = {2, 4, 3, 4, 3, 4, 1, 5, 2};
    
    //행렬 생성
    Matrix* m1 = matrixNew(3, 3);
    matrixInit(m1, a);
    matrixPrint(m1);
    
    Matrix* m2 = matrixNew(3, 3);
    matrixInit(m2, b);
    matrixPrint(m1);
    
    //덧셈
    Matrix* m3;
    m3 = matrixAdd(m1, m2);
    matrixPrint(m3);
    
    //곱셈
    Matrix* m4;
    m4 = matrixMultiply(m1, m2);
    matrixPrint(m4);
    
    matrixFree(m1);
    matrixFree(m2);
    matrixFree(m3);
    matrixFree(m4);
    
    return 0;
}
