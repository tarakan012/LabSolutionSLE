//
// Created by cucaracha on 20.05.18.
//

#ifndef VECTOR_MATH_EQUALITY_H
#define VECTOR_MATH_EQUALITY_H

#include "algebraic_expression.h"
#include "math_symbols.h"
#include <stdbool.h>

typedef struct
{
    variable * left_hand_side;
    alg_expression * right_hand_side;
    bool is_solution;
} math_equality;

math_equality * create_equality();

void delete_equality(math_equality * equality);

void delete_equalities_vec(vector * equalities_vec);

#endif //VECTOR_MATH_EQUALITY_H
