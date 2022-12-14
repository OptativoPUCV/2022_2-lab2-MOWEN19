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
  if (!list->head){
    return NULL;
  }    
  else{
    list->current = list->head; 
    return list->current->data;
  }
}

void * nextList(List * list) {
  // La segunda función retorna el dato del nodo continuación del current y actualiza el current para que apunte a ese nodo.
  
  if (list->current == NULL){
    return NULL;
  }
  else if(list->current->next == NULL){
    return NULL;
  }
  else{
    list->current = list->current->next;
    return list->current->data;
  }
    
  
}

void * lastList(List * list) {
  //La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. 
  if (!list->tail){
    return NULL;
  }    
  else{
    list->current = list->tail; 
    return list->current->data;
  }
    return NULL;
}

void * prevList(List * list) {
  //La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.
  if (!list->head){
    return NULL;
  }
  else if (list->current== NULL){
    return NULL;
  }
  else if(list->current == list->head){
    return NULL;
  }    
  else{
    list->current = list->current->prev;
    return list->current->data;
  }
}

void pushFront(List * list, void * data) {
  //la cual agrega un dato al comienzo de la lista. 
  Node *dato = createNode(data);
  if (!list->head){
    list->head = dato;
    list->tail = dato;
    return ;
  }
  list->head->prev = dato;
  dato->next = list->head;
  list->head = dato;
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  //la cual agrega un dato a continuación del nodo apuntado por `list->current`.
  Node *dato = createNode(data);
  if (!list->head){
  // // .// // // hola / comoestas //
    // //. . fgbhsdj
    list->head = dato;
    list->tail = dato;
    return ;
  }
  else{
    list->current->next = dato;
    dato->prev = list->current;
    list->tail = dato;
  }
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
    current = current->next;
    list->head->prev = NULL;
    return NULL;
  }
  else if (list->head == current){
    Node *dato = list->head->data;
    list->head = current->next;
    list->head->prev = NULL;
    list->current = list->head;
    return dato;
    
  }
  else if(list->tail == current){
    Node *dato = list->tail->data;
    list->tail = current->prev;
    list->tail->next = NULL;
    list->current = list->tail;
    return dato;
  }
  else{
    Node *dato = list->current->data;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    return dato;
  }
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}