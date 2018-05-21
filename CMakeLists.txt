cmake_minimum_required(VERSION 3.9)
project(SolutionSLE C)

set(CMAKE_C_STANDARD 11)

add_executable(vector main.c vector.h parser.h math_symbols.h algebraic_expression.h math_equality.h solve_sle.h writer.h parser.c solve_sle.c algebraic_expression.c math_equality.c vector.c)