//
// Created by cucaracha on 21.05.18.
//

#ifndef VECTOR_WRITER_H
#define VECTOR_WRITER_H

#include <stdio.h>

#include "vector.h"
#include "math_symbols.h"

void write_file(vector * calculated_var_vec, FILE * fp)
{
    printf("Writing solution in file...\n");
    for(int i = 0; i < calculated_var_vec->size; ++i)
    {
        variable * var = vector_get(calculated_var_vec, i);
        fprintf(fp, "%s = %d\n",var->name_var, var->value);
        printf("line: %s = %d\n",var->name_var, var->value);
    }
    printf("Write solution in file succes\n");
}

#endif //VECTOR_WRITER_H
