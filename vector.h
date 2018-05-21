//
// Created by cucaracha on 04.05.18.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VECTOR_INIT_CAPACITY 16

typedef struct
{
    void ** items;
    int size;
    int capacity;
} vector;

vector * create_vector(int capacity);

void delete_vector(vector *vec);

void delete_from_vector(vector *vec,int position);

void delete_vec_and_items(vector * vec);

void vector_resize(vector *vec, int new_capacity);

void push_back_vector(vector *vec, void *item);

void *vector_get(vector *vec, int position);

#endif //VECTOR_VECTOR_H
