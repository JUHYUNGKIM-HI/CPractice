//
//  array2DVariableSize.h
//  array2DVariableSize
//
//  Created by 김주형 on 2021/06/11.
//

#ifndef array2DVariableSize_h
#define array2DVariableSize_h

typedef int item;
typedef struct {
    int col;
    int row;
    item** var; // 2차원 배열을 표현하기 위해서 2중 포인터를 사용하였다.
}Matrix;

// 함수 선언
Matrix* matrixNew(int row, int col);
void matrixInit(Matrix* m, item* src);
void matrixFree(Matrix* m);
void matrixPrint(Matrix* m);
Matrix* matrixMultiply(const Matrix* a, const Matrix* b);
Matrix* matrixAdd(const Matrix* a, const Matrix* b);

#endif /* array2DVariableSize_h */
