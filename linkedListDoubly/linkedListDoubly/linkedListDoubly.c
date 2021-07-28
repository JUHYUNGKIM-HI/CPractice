//
//  linkedListDoubly.c
//  linkedListDoubly
//
//  Created by 김주형 on 2021/06/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedListDoubly.h"


void init(LinkedListDoubly* list){
    list->size = 0;
    list->head = NULL;
    list->last = NULL;
}


bool isEmpty(const LinkedListDoubly* list){
    if(list->head == NULL) return true;
    else return false;
}


Node* create(Element e, Node* prev, Node* next){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error : creating a new node.\n");
        exit(1);
    }
    
    newNode->data = e;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}


void addFirst(LinkedListDoubly* list, Element data){
    Node* newNode = create(data, NULL, NULL);
    
    if(list->head == NULL){
        list->head = newNode;
        list->head = newNode;
        return;
    }
    
    else{
        list->head->prev = newNode;
        newNode->next = list->head;
        list->head = newNode;
    }
}

void print(const LinkedListDoubly* list, int direction){
    if(direction == FORWARD){
        Node* temp = list->head;
        while(temp != NULL){
            printf("--> %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
