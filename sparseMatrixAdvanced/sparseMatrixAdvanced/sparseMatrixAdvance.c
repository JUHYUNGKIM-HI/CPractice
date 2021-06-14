//
//  sparseMatrixAdvance.c
//  sparseMatrixAdvanced
//
//  Created by 김주형 on 2021/06/13.
//  내용 : sparse Matrix의 체계적인 자료구조 구현

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sparseMatrixAdvance.h"


// 함수명 : SparseMatrix* create(int row, int col, int* array)
// 설명 : 희소 행렬 초기화, 희소 행렬의 행의 수, 열의 수를 초기화 하고, 아이템의 개수를 0으로 초기화
// 리턴값 : void
// 매개변수 : SparseMatrix* sp, row, col
SparseMatrix* create(int row, int col, int* array){
    //sparse Matrix 표현을 위한 동적 메모리 할당
    int size = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(array[i * col + j] != 0) size++;
        }
    }
    
    SparseMatrix* sp = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sp -> data = (Element*)malloc(sizeof(Element)*size);
    
    // 일반 행렬을 sparse Matrix로 변환
    sp -> rowNo = row;
    sp -> colNo = col;
    sp -> valueNo = size;
    
    int k = 0;
    for(int i = 0; i < 4; i++)
        for(int j =0; j < 5; j++)
            if(array[i * col +j] != 0){
                sp -> data[k].row = i;
                sp -> data[k].col = j;
                sp -> data[k].value = array[i * col + j];
                k++;
            }
    return sp;
}


// 함수명 : void print(const SparseMatrix* sp)
// 설명 : 희소 행렬을 2차원 행렬 모양으로 화면에 출력하는 함수.
// 리턴값 : void
// 매개변수 : const SparseMatrix* sp
void print(const SparseMatrix* sp){
    printf("Original form\n");
    for(int i = 0; i < sp->rowNo; i++){ // 각 행에 대하여
        for(int j = 0; j < sp->colNo; j++){ // 각 열에 대하여
            bool found = false;
            // 희소행렬의 모든 항목을 차례로 검색하면서 해당하는 위치의 항목을 찾아서 출력
            for(int k = 0; k < sp->valueNo; k++){
                if(i == sp->data[k].row && j == sp->data[k].col){
                    printf("%2d ", sp->data[k].value);
                    found = true; // 찾았으면 중간에 검색 종료
                    break;
                }
            }
            if(!found) printf("%2d ", 0);
        }
        printf("\n");
    }
    return;
}


// 함수명 : void printOriginal(const SparseMatrix* sp)
// 설명 : 희소 행렬을 그대로 화면에 출력하는 함수, SparseMatrix를 순서대로 출력함
// 리턴값 : void
// 매개변수 : const SparseMatrix* sp
void printOriginal(const SparseMatrix* sp){
    printf("Sparse matrix form\n");
    for(int i = 0; i < sp->valueNo; i++){
        printf("%2d %2d %2d\n", sp->data[i].row, sp->data[i].col, sp->data[i].value);
    }
}


// 함수명 : int get(const SparseMatrix* sp, int a, int b)
// 설명 : 배열의 [a][b]에 있는 원소를 반환
// 리턴값 : 정수값, 반환값이 0이면 원소가 없음을 의미한다.
// 매개변수 : const SparseMatrix* sp, int row, int col
int get(const SparseMatrix* sp, int a, int b){
    for(int i = 0; i < sp->valueNo; i++){
        if(a == sp->data[i].row && b == sp->data[i].col){
            return sp->data[i].value;
        }
    }
    return 0;
}


//  함수명 : void set(SparseMatrix* sp, int a, int b, int value)
//  설명 : 배열의 [a][b]에 새로운 값 value를 추가, 이미 [a][b]에 값이 있으면 이를 수정, 정렬해서 넣어야함.
//  리턴값 : void
//  매개변수 : SparseMatrix* sp, int row, int col
void set(SparseMatrix* sp, int a, int b, int value){
    if(a >= sp->rowNo || b >= sp->colNo) return;
    if(value == 0) return;
    
    Element newElem = {a, b, value};
    int p, pNew;
    
    //  항목이 하나도 없으면 바로 0번째에 추가
    if(sp->valueNo == 0){
        sp->data[sp->valueNo + 1] = newElem;
    }
    
    //  항목이 이미 하나라도 존재하면 row-major 순서에 따라 자신의 자리에 삽입
    else{
        //  끝에서 부터 자기 자리를 찾아서
        for(int i = sp->valueNo - 1; i >= 0; i--){
            p = sp->data[i].row * sp->colNo + sp->data[i].col;
            pNew = a * sp->colNo + b;
            
            //  기존에 동일한 위치에 이미 항목이 있으면 변경
            if(pNew == p){
                sp->data[i].value = value;
                return;
            }
            
            // 중간에 끼워 넣어야 하는 경우
            else if (pNew > p){
                //  배열이 가득찬 경우에는 추가할 수 없음.
                if(sp->valueNo > MAX_SIZE - 1) return;
                //  추가할 위치 이후의 항목을 한칸씩 뒤로 이동
                for(int j = sp->valueNo - 1; j >= i + 1; j--){
                    sp->data[j + 1] = sp->data[j];
                }
                sp->data[i + 1] = newElem;
                sp->valueNo = sp->valueNo + 1;
                return;
            }
        }
    }
    
}
