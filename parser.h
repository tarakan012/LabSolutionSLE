//
// Created by cucaracha on 15.05.18.
//

#ifndef VECTOR_PARCER_H
#define VECTOR_PARCER_H

#include "vector.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h> //isdigit
#include "math_equality.h"
#include "algebraic_expression.h"
#include "math_symbols.h"

#define MAX_LEN_STR_FILE 64

int parse_file(vector * vec_strings, FILE * fp);

int find_pos_sign(char * line, char sign);

void remove_spaces(char* restrict str_trimmed, const char* restrict str_untrimmed);

void push_symbol_to_expression(alg_expression * expression, char * symbol);

bool parse_expression(alg_expression * expression, char * str_expr);

int parse_equalities(vector * equalities_vec, vector * line_vec);

#endif //VECTOR_PARCER_H
