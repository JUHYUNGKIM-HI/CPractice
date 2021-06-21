//
//  linkedListCircular.h
//  linkedListCircular
//
//  Created by 김주형 on 2021/06/21.
//

#ifndef linkedListCircular_h
#define linkedListCircular_h

#include <stdbool.h>
#define IS_EQUAL(a, b) (a == b)

typedef int Element;


typedef struct Node{
    Element data;
    struct Node* next;
}Node;


typedef struct{
    Node *head;
    int size;
}LinkedList;


void init(LinkedList* list);
bool isEmpty(const LinkedList* list);
void print(const LinkedList* list);
Node* create(Element e, Node* next);
void add(LinkedList* list, Element data);

#endif /* linkedListCircular_h */
