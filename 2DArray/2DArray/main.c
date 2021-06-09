//
//  main.c
//  2DArray
//
//  Created by 김주형 on 2021/06/08.
//

#include <stdio.h>
#include "array2dSimple.h"

int main() {
    int a[3][3] = {{1, 2, 3}, {2, 3, 4}, {1, 2, 2}};
    int b[3][3] = {{2, 4, 3}, {4, 3, 4}, {1, 5, 2}};
    int c[3][3];
    
    matrixPrint(a);
    matrixPrint(b);
    matrixAdd(a, b, c);
    matrixPrint(c);
    matrixMultiply(a, b, c);
    matrixPrint(c);
    
    return 0;
}
