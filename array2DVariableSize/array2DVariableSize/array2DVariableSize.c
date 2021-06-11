//
//  array2DVariableSize.c
//  array2DVariableSize
//
//  Created by 김주형 on 2021/06/11.
//  내용 : 가변적인 크기의 2차원 배열의 덧셈, 곱셈 연산

#include <stdio.h>
#include <stdlib.h> // malloc()함수를 사용하기 위해 호출
#include <string.h>
#include "array2DVariableSize.h"


// 함수명 : matrixNew(int row, int col)
// 설명 : 새로운 행렬을 생성한다.
// 파라미터로 받은 row, col에 맞게 2차원 배열을 동적으로 할당한다. 3단계로 할당 받는다.
// 1. Matrix 구조체 변수 메모리 할당
// 2. 행의 갯수에 맞게 메모리 동적 할당
// 3. 각 행의 열의 갯수에 맞게 메모리 할당
// 리턴값 : Matrix*
// 매개변수 : 생성할 행렬의 row와 col
Matrix* matrixNew(int row, int col){
    Matrix* m;
    
    m = (Matrix*)malloc(sizeof(Matrix)); // Matrix 구조의 변수를 위한 메모리 할당.
    m->row = row;
    m->col = col;
    m->var = (item**)malloc(sizeof(item*)*row); // 행의 갯수 만큼 메모리 할당
    
    for(int i = 0; i < row; i++){
        m->var[i] = (item*)malloc(sizeof(item)*col); // 각 행의 칼럼만큼 메모리 할당
        memset(m->var[i], 0, sizeof(item)*col); // memset() 함수는 각 행의 모든 칼람을 0으로 초기화 한다.
    }
    return m;
}


// 함수명 : matrixFree(Matrix* m)
// 설명 : 행렬의 메모리를 해제한다.
// 구조체 형식의 배열을 순차적으로 해제한다.
// 해제하는 순서는 할당 받은 역순이다.
// 리턴값 : void
// 매개변수 : 해제할 행렬의 Matrix*
void matrixFree(Matrix* m){
    for(int i = 0; i < m->row; i++){
        free(m->var[i]); // 열의 포인터 변수 해제
    }
    free(m->var); // 행의 포인터 변수 해제
    free(m); // Martix 구조 변수 해제
}


// 함수명 : matrixInit(Matrix* m, Item* src)
// 설명 : 1차원 배열 형식의 데이터를 파라미터로 받아서 2차원 배열을 초기화한다.
// 리턴값 : void
// 매개변수 : 행렬의 Matrix*, 초기화에 사용할 Item*
void matrixInit(Matrix* m, item* src){
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->col; j++){
            m->var[i][j] = src[i * m->col + j];
        }
    }
}


// 함수명 : matrixAdd(Matrix* a, Matrix* b)
// 설명 : 2개의 행열의 합
// 두 배열의 행과 열의 숫자가 동일한지 체크해야한다.
// 행렬의 합 결과값은 동적으로 할당받은 메모리를 이용해서 반환값으로 돌려준다.
// 리턴값 : 합 행렬의 Matrix*
// 매개변수 : Matrix*의 2개의 행렬
Matrix* matrixAdd(const Matrix* a, const Matrix* b){
    Matrix* m;
    if(a->col != b->col || a->row != b->row) return NULL;
    
    m = matrixNew(a->row, a->col);
    for(int i = 0; i < a->row; i++){
        for(int j = 0; j < a->row; j++){
            m->var[i][j] = a->var[i][j] + b->var[i][j];
        }
    }
    return m;
}


// 함수명 : matrixMultiply(Matrix* a, Matrix* b)
// 설명 : 2개의 행열의 곱
// 곱하는 행렬 중에서 앞의 행령의 열과 뒤의 행렬의 행 숫자가 동일한지 체크해야한다.
// 행렬의 곱 결과값은 동적으로 할당받은 메모리를 이용해서 반환값(return value)으로 돌려준다.
// 리턴값 : 곱 행렬의 Matrix*
// 매개변수 : Matrix*의 2개의 행렬
Matrix* matrixMultiply(const Matrix* a, const Matrix* b){
    Matrix* m;
    int row, col, iter;
    
    if(a->col != b->row) return NULL;
    
    row = a->row;
    col = b->col;
    iter = a->col;
    
    m = matrixNew(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int k = 0; k < iter; k++){
                m->var[i][j] += a->var[i][k] * b->var[k][j];
            }
        }
    }
    return m;
}


// 함수명 : matrixPrint(Matrix* a)
// 설명 : 행렬을 화면에 출력
// 리턴값 : void
// 매개변수 : Matrix*의 행렬
void matrixPrint(Matrix* m){
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->col; j++){
            printf("%5d ", m->var[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
