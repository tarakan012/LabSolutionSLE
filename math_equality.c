//
// Created by cucaracha on 21.05.18.
//

#include "math_equality.h"
#include "vector.h"

math_equality * create_equality()
{
    math_equality * equality = malloc(sizeof(math_equality));

    variable * computed_variable = malloc(sizeof(variable));
    computed_variable->value = -1;
    computed_variable->is_computed = false;
    equality->left_hand_side = computed_variable;

    equality->right_hand_side = create_expression();
    equality->is_solution = false;
    return equality;
}

void delete_equality(math_equality *equality)
{
    free(equality->left_hand_side);
    equality->left_hand_side = NULL;
    delete_expression(equality->right_hand_side);
    free(equality);
    equality = NULL;
}

void delete_equalities_vec(vector * equalities_vec)
{
    for(int i = 0; i<equalities_vec->size; ++i)
    {
        math_equality * equality = vector_get(equalities_vec,i);
        delete_equality(equality);
        equality = NULL;
    }
    delete_vector(equalities_vec);
}


