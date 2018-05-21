#include <stdio.h>
#include "vector.h"
#include "parser.h"
#include "solve_sle.h"
#include "writer.h"

int main()
{
    FILE * fp = fopen("../input.txt","r");

    if(!fp)
    {
        perror("fopen file fail");
        return EXIT_FAILURE;
    }
    vector * line_vec = create_vector(VECTOR_INIT_CAPACITY);
    parse_file(line_vec,fp);
    fclose(fp);
    vector * equalities_vec = create_vector(VECTOR_INIT_CAPACITY);
    parse_equalities(equalities_vec, line_vec);
    delete_vec_and_items(line_vec);
    vector * calculated_var_vec = create_vector(VECTOR_INIT_CAPACITY);
    solve_system_linear_equations(equalities_vec, calculated_var_vec);

    fp = fopen("../output.txt","w");

    write_file(calculated_var_vec,fp);
    delete_equalities_vec(equalities_vec);
    delete_vector(calculated_var_vec);
    fclose(fp);
    return 0;
}