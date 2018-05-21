//
// Created by cucaracha on 21.05.18.
//

#include "parser.h"

int parse_file(vector * vec_strings, FILE * fp)
{
    printf("Parsing file...\n");
    char buffer[MAX_LEN_STR_FILE];

    while(fgets(buffer, MAX_LEN_STR_FILE, fp) != NULL)
    {
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len-1]=='\n')
        {
            buffer[len-1] = '\0';
            char * str_line = malloc(sizeof(char) * MAX_LEN_STR_FILE);
            memcpy(str_line,buffer,len);
            push_back_vector(vec_strings, (void*)str_line);
        }
    }
    for(int i =0 ; i<vec_strings->size;i++)
    {
        char * data_vector = (char*)vector_get(vec_strings, i);
        printf("line : %s\n",data_vector);
    }
    printf("Parsed file succes\n");
}

int find_pos_sign(char * line, char sign)
{
    char * sign_ptr = strchr(line,sign);
    if(sign_ptr == NULL)
    {
        return  -1;
    }
    int position = sign_ptr - line;
    return position;
}

void remove_spaces(char* restrict str_trimmed, const char* restrict str_untrimmed)
{
    while (*str_untrimmed != '\0')
    {
        if(!isspace(*str_untrimmed))
        {
            *str_trimmed = *str_untrimmed;
            str_trimmed++;
        }
        str_untrimmed++;
    }
    *str_trimmed = '\0';
}

void push_symbol_to_expression(alg_expression * expression, char * symbol)
{
    if(isdigit(*symbol))
    {
        constant * constant = malloc(sizeof(constant));
        constant->value = atoi(symbol);
        push_back_vector(expression->constant_vec,constant);
    }
    else
    {
        variable * var = malloc(sizeof(variable));
        memcpy(var->name_var,symbol,strlen(symbol) + 1);
        var->value = -1;
        var->is_computed = false;
        push_back_vector(expression->variable_vec,var);
        expression->num_unknows_var++;
    }
}

bool parse_expression(alg_expression * expression, char * str_expr)
{
    int len = strlen(str_expr);
    int len_sub_str = len;
    int pos_plus = 0;
    bool parse_completed = false;
    char * temp_symbol = (char*)malloc(sizeof(char) * 32);
    char * sub_str_expr = str_expr;
    do
    {
        pos_plus = find_pos_sign(sub_str_expr, '+');

        if(pos_plus == -1)
        {
            memcpy(temp_symbol, sub_str_expr,len_sub_str);
            temp_symbol[len] = '\0';
            push_symbol_to_expression(expression,temp_symbol);
            parse_completed = true;
        } else
        {
            memcpy(temp_symbol, sub_str_expr,pos_plus);
            temp_symbol[pos_plus] = '\0';
            push_symbol_to_expression(expression,temp_symbol);
            //skip plus
            sub_str_expr = sub_str_expr + pos_plus + 1;
            len_sub_str -= pos_plus + 1;
        }

    } while(!parse_completed);
    return parse_completed;
}

int parse_equalities(vector * equalities_vec, vector * line_vec)
{
    printf("Parsing equalities...\n");
    for(int n = 0; n < line_vec->size; ++n)
    {
        char * line = (char*)vector_get(line_vec,n);
        int size_line = strlen(line);
        int pos_equals = find_pos_sign(line, '=');
        if(pos_equals == -1)
            continue;
        int len_left = pos_equals + 1;
        int len_right = size_line - pos_equals;
        char * str_left = malloc(sizeof(char) * len_left);
        char * str_right = malloc(sizeof(char) * len_right);
        memcpy(str_left, line, len_left);
        str_left[len_left-1] = '\0';
        memcpy(str_right, line + len_left, len_right);

        remove_spaces(str_left,str_left);
        remove_spaces(str_right, str_right);

        math_equality * equality = create_equality();

        memcpy(equality->left_hand_side->name_var,str_left, len_left);
        parse_expression(equality->right_hand_side, str_right);

        push_back_vector(equalities_vec, equality);
    }
    printf("Parsed equalities succes\n");
}
