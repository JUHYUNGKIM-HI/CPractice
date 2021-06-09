//
//  array.h
//  Array
//
//  Created by 김주형 on 2021/06/08.
//

#ifndef array_h
#define array_h

#define MAX_SIZE 10 // 현재 배열의 항목 개수

//배열의 파라미터를 const 형으로 전달하면 함수에게 넘겨주는 배열을 수정하지 않는다는 의미이다.
void print(const int data[]); // 배열의 모든 요소 출력
int isInArray(const int data[], int e); // 배열에 item이 있으면 그 위치를 반환, 없으면 -1을 반환
int max(const int data[]); // 배열에서의 최대값 반환
int min(const int data[]); // 배열에서의 최소값 반환
double avg(const int data[]); // 배열에서의 평균값 반환

#endif /* array_h */
