//
//  linkedListDoubly.h
//  linkedListDoubly
//
//  Created by 김주형 on 2021/06/21.
//

#ifndef linkedListDoubly_h
#define linkedListDoubly_h

#include <stdbool.h>

#define FORWARD 1
#define BACKWARD 2

typedef int Element;

typedef struct Node{
    Element data;
    struct Node* prev;
    struct Node* next;
}Node;


typedef struct {
    struct Node* head;
    struct Node* last;
    int size;
}LinkedListDoubly;


void init(LinkedListDoubly* list);
bool isEmpty(const LinkedListDoubly* list);
void print(const LinkedListDoubly* list, int direction);
Node* create(Element e, Node* prev, Node* next);
void addFirst(LinkedListDoubly* list, Element data);

#endif /* linkedListDoubly_h */
