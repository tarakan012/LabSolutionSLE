//
// Created by cucaracha on 21.05.18.
//

#include "algebraic_expression.h"

alg_expression * create_expression()
{
    alg_expression * expression = malloc(sizeof(alg_expression));
    expression->variable_vec = create_vector(VECTOR_INIT_CAPACITY);
    expression->constant_vec = create_vector(VECTOR_INIT_CAPACITY);
    expression->num_unknows_var = 0;
    return expression;
}

void delete_expression(alg_expression *expression)
{
    delete_vec_and_items(expression->variable_vec);
    delete_vec_and_items(expression->constant_vec);
    free(expression);
    expression = NULL;
}
