//
//  array2dSimple.c
//  2DArray
//
//  Created by 김주형 on 2021/06/08.
//

// 내용 : 3*3으로 정해진 크기의 2차원 배열의 덧셈, 곱셈 연산
// 제한사항 : 현재는 크기가 3으로 고정, 크기를 define을 사용해서 수정하면 더 편함.


#include "array2dSimple.h"
#include <stdio.h>


// 함수명 : matrixPrint(int a[3][3])
// 설명 : 2차원 행렬을 파라미터로 받아서 화면에 출력하는 함수
// 리턴값 : void
// 매개변수 : 2차원 행렬 1개
void matrixPrint(const int a[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// 함수명 : martixAdd(int a[3][3], int b[3][3], int result[3][3])
// 설명 : 2개의 행렬의 합
// 리턴값 : void
// 매개변수 : 2차원 행렬 2개 a와 b와, 그 '합'을 전달받은 result 배열
void matrixAdd(const int a[3][3], const int b[3][3], int result[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}


// 함수명 : matrixMultiply(int a[3][3], int b[3][3], int result[3][3])
// 설명 : 2개의 행렬의 곱
// 리턴값 : void
// 매개변수 : 2차원 행렬 2개 a, b와 그 곱을 전달받은 result 배열
void matrixMultiply(const int a[3][3], const int b[3][3], int result[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
