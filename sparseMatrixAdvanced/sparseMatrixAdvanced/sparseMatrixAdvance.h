//
//  sparseMatrixAdvance.h
//  sparseMatrixAdvanced
//
//  Created by 김주형 on 2021/06/13.
//

#ifndef sparseMatrixAdvance_h
#define sparseMatrixAdvance_h

#define MAX_SIZE 20

// 희소 행렬 하나의 항목을 위한 구조체
typedef struct{
    int row;
    int col;
    int value;
}Element;

//희소 행렬 전체를 위한 구조체
typedef struct{
    int rowNo; // 행렬의 행의 개수
    int colNo; // 행렬의 열의 개수
    int valueNo; // 행렬의 0이 아닌 항목의 개수
    Element* data;
}SparseMatrix;

SparseMatrix* create(int row, int col, int* array);
void print(const SparseMatrix* sp);
void printOriginal(const SparseMatrix* sp);

// 희소 행렬에서 행번호와 열번호로 항목을 검색하거나 수정하는 함수
int get(const SparseMatrix* sp, int r, int c);
void set(SparseMatrix* sp, int r, int c, int value);

#endif /* sparseMatrixAdvance_h */
