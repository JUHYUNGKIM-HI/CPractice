//
//  array.c
//  Array
//
//  Created by 김주형 on 2021/06/08.
//  내용 : 배열의 기초적인 사용법 예시

#include <stdio.h>
#include "array.h"


//함수명 : void print(const int data[])
//설명 : 배열의 모든 항목을 출력
//리턴값 : void
//매개변수 : const int data[]
void print(const int data[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}


//함수명 : int isInArray(const int data[], int e)
//설명 : 배열에 원하는 항목이 있는지 검색. 존재하면 그 인덱스를 반환, 존재하지 않느면 -1을 반환
//      동일한 값이 2개 이상 존재하는 경우에는 처음 1개의 위치를 검색
//리턴값 : int
//매개변수 : const int data[], int e
int isInArray(const int data[], int e)
{
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if(data[i] == e) return i;
    }
    return -1;
}


//함수명 : int max(const int data[])
//설명 : 배열에서 최대값을 반환한다.
//리턴값 : int
//매개변수 : const int data[]
int max(const int data[])
{
    int max = data[0];
    
    for (int i = 1; i < MAX_SIZE; i++)
    {
        if(data[i] > max)
        {
            max = data[i];
        }
    }
    return max;
}


//함수명 : int min(const int data[])
//설명 : 배열에서 최소값을 반환한다.
//리턴값 : int
//매개변수 : const int data[]
int min(const int data[])
{
    int min = data[0];
    
    for(int i = 1; i < MAX_SIZE; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }
    return min;
}

//함수명 : int avg(const int data[])
//설명 : 배열에서 최소값을 반환한다.
//리턴값 : double
//매개변수 : const int data[]
double avg(const int data[])
{
    int x = 0;
    
    for(int i = 0; i < MAX_SIZE; i++)
    {
        x += data[i];
    }
    return (x / MAX_SIZE);
}
