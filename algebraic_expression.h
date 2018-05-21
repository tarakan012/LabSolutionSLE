//
// Created by cucaracha on 20.05.18.
//

#ifndef VECTOR_ALGEBRAIC_EXPRESSION_H
#define VECTOR_ALGEBRAIC_EXPRESSION_H

#include "math_symbols.h"
#include "vector.h"

typedef struct
{
    vector * constant_vec;
    vector * variable_vec;
    int num_unknows_var;
} alg_expression;

alg_expression * create_expression();

void delete_expression(alg_expression * expression);

#endif //VECTOR_ALGEBRAIC_EXPRESSION_H
