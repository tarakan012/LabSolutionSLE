//
// Created by cucaracha on 21.05.18.
//

#include "vector.h"

vector * create_vector(int capacity)
{
    vector * vec = malloc(sizeof(vector));

    vec->capacity = capacity;
    vec->size=0;
    vec->items = malloc(sizeof(void*) * capacity);
    return vec;
}

void delete_vector(vector *vec)
{


    vec->capacity = 0;
    vec->size = 0;
    free(vec->items);
    vec->items = NULL;
    free(vec);
    vec = NULL;
}

void delete_from_vector(vector *vec,int position)
{
    if(0 <=position && position <= vec->size)
    {
        free(vec->items[position]);
        vec->items[position] = NULL;
        for(int i = position; i < vec->size;i++)
        {
            vec->items[i] = vec->items[i+1];
        }
        vec->size--;
    }
    if(vec->size > 0 && vec->size == vec->capacity / 4)
    {
        vector_resize(vec, vec->capacity / 2);
    }

}

void delete_vec_and_items(vector *vec)
{
    for(int i = 0; i < vec->size; ++i)
    {
        delete_from_vector(vec, i);
    }
    delete_vector(vec);
}

void vector_resize(vector *vec, int new_capacity)
{
    printf("Vector resize: %d to %d\n", vec->capacity, new_capacity);
    vec->items = realloc(vec->items, sizeof(void*) * new_capacity);
    vec->capacity = new_capacity;
}

void push_back_vector(vector *vec, void *item)
{
    if(vec->size == vec->capacity) {
        vector_resize(vec, vec->capacity * 2);
    }
    vec->items[vec->size++] = item;
}

void *vector_get(vector *vec, int position)
{
    if(0 <=position && position < vec->size)
        return vec->items[position];
    return NULL;
}
