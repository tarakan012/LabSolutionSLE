//
// Created by cucaracha on 20.05.18.
//

#ifndef VECTOR_CALCULATE_VARIABLE_H
#define VECTOR_CALCULATE_VARIABLE_H

#include "vector.h"
#include "math_equality.h"
#include "algebraic_expression.h"
#include "math_symbols.h"
#include <stdbool.h>

variable * find_calculated_var_by_name(vector * calculated_var_vec, char * var_name);

int calculate_sum_constant(alg_expression * expression);

int calculate_sum_var(alg_expression * expression);

bool try_solution_equation(math_equality * equality, vector * calculated_var_vec);

bool update_var_in_expression(alg_expression * expression,  vector * calculated_var_vec);

void solve_system_linear_equations(vector * equalities_vec, vector * calculated_var_vec);

#endif //VECTOR_CALCULATE_VARIABLE_H
