//
// Created by cucaracha on 20.05.18.
//

#ifndef VECTOR_MATHSYMBOLS_H
#define VECTOR_MATHSYMBOLS_H

#include <stdbool.h>

#define MAX_NAME_VAR 32

typedef struct
{
    char name_var[MAX_NAME_VAR];
    int value;
    bool is_computed;
}variable;

typedef struct
{
    int value;
}constant;

#endif //VECTOR_MATHSYMBOLS_H
