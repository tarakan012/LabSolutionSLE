//
// Created by cucaracha on 21.05.18.
//

#include "solve_sle.h"
#include "math_symbols.h"

variable * find_calculated_var_by_name(vector * calculated_var_vec, char * var_name)
{
    for(int i =0 ;i < calculated_var_vec->size;++i)
    {
        variable * var = vector_get(calculated_var_vec,i);
        if(!strcmp(var->name_var, var_name))
        {
            return var;
        }
    }
    return NULL;
}

int calculate_sum_constant(alg_expression * expression)
{
    int sum = 0;
    for(int i = 0; i < expression->constant_vec->size; ++i)
    {
        constant * constant = vector_get(expression->constant_vec,i);
        sum += constant->value;
    }
    return sum;
}

int calculate_sum_var(alg_expression * expression)
{

    int sum = 0;
    for(int i = 0; i < expression->variable_vec->size; ++i)
    {
        variable * var = vector_get(expression->variable_vec,i);
        sum +=var->value;
    }
    return sum;
}

bool try_solution_equation(math_equality * equality, vector * calculated_var_vec)
{

    if(!equality->is_solution && equality->right_hand_side->num_unknows_var == 0)
    {
        int val_left = 0;
        val_left += calculate_sum_var(equality->right_hand_side);
        val_left += calculate_sum_constant(equality->right_hand_side);
        equality->left_hand_side->value = val_left;
        equality->left_hand_side->is_computed = true;
        equality->is_solution = true;
        push_back_vector(calculated_var_vec, equality->left_hand_side);
        return true;
    }
    return false;
}

bool update_var_in_expression(alg_expression * expression,  vector * calculated_var_vec)
{
    bool updated = false;
    for(int i = 0; i < expression->variable_vec->size; ++i) {
        variable * var = vector_get(expression->variable_vec, i);
        if(!var->is_computed)
        {
            variable *calc_var = find_calculated_var_by_name(calculated_var_vec, var->name_var);
            if(calc_var != NULL) {
                var->value = calc_var->value;
                var->is_computed = true;
                expression->num_unknows_var--;
                updated = true;
            }
        }
    }
    return updated;
}

void solve_system_linear_equations(vector * equalities_vec, vector * calculated_var_vec)
{
    printf("Solving system of linear equations...\n");
    int number_equalities = equalities_vec->size;
    while(calculated_var_vec->size < number_equalities) {
        for(int i = 0; i < number_equalities; ++i) {
            math_equality *equality = (math_equality*)vector_get(equalities_vec, i);
            if(!try_solution_equation(equality, calculated_var_vec))
            {
                if(calculated_var_vec->size != 0 && !equality->is_solution)
                    if(update_var_in_expression(equality->right_hand_side, calculated_var_vec))
                    {
                        try_solution_equation(equality, calculated_var_vec);
                    }
            }
        }
    }
    printf("Solve system of linear equations succes\n");
}