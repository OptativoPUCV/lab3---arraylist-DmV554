#include "arraylist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// normal array
typedef struct ArrayList {
  void **data;
  int capacity;
  int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
  list->capacity = 2;
  list->data = (void **)malloc(sizeof(void *) * list->capacity);

  list->size = 1;
  return list;
}

void append(ArrayList *l, void *data) {
  if (l->capacity == l->size) {
    l->capacity = l->capacity * 2;

    l->data = realloc(l->data, sizeof(void *) * l->capacity);
  }

  l->data[l->size] = data;
  l->size++;
}

void push(ArrayList *l, void *data, int i) {
  if (l->capacity == l->size) {
    l->capacity = l->capacity * 2;

    l->data = realloc(l->data, sizeof(void *) * l->capacity);
  }

  if (i > l->size) {
    return;
  }

  for (int j = l->size - 1; j >= i; j--) {
    l->data[j + 1] = l->data[j];
  }

  l->data[i] = data;
  l->size++;
}

void *get(ArrayList *l, int i) {
  if (i >= l->size)
    return NULL;

  if (i < 0) {
    i = i + l->size;
  }

  return l->data[i];
}

void *pop(ArrayList *l, int i) { 
  if (i < 0) {
        i = l->size + i;
    }
  
    if (i >= l->size) {
        return NULL; 
    }

  void *datoAEliminar = l->data[i];

  for (int j = i; j < l->size-1; j++) {
    l->data[j] = l->data[j+1];
  }

  l->size--;

  
  return datoAEliminar;
}



int get_size(ArrayList *l) { return l->size; }

// remove elements
void clean(ArrayList *l) {}
