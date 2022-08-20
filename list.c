#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* list = (List*)calloc(1,sizeof(List));
  list->head = NULL;
  list->current = NULL;
  list->tail = NULL;
     return list;
}

void * firstList(List * list) {
  //La primera retorna el dato del primer nodo de la lista (`head`) y actualiza el current para que apunte a ese nodo.
    list->current = list->head;
    return NULL;
}

void * nextList(List * list) {
  // La segunda función retorna el dato del nodo continuación del current y actualiza el current para que apunte a ese nodo.
    return NULL;
}

void * lastList(List * list) {
  //La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. 
    return NULL;
}

void * prevList(List * list) {
  //La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.
    return NULL;
}

void pushFront(List * list, void * data) {
  //la cual agrega un dato al comienzo de la lista. 
  
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  //la cual agrega un dato a continuación del nodo apuntado por `list->current`.
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  
  Node *current = list->current;
  if (current == NULL){
    return NULL;
  }
  
  if (list -> head == current){
    current->next->prev = NULL;
    list->head = current->next;        
  }
  
  current->prev->next = list->current->next;
  current->next->prev = list->current->prev;
  //free(current);
  
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}