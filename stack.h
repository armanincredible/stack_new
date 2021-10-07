#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <cstdlib>
#include <string.h> 
#include <typeinfo>
/*#include <stdint.h>*/

typedef int elem_t;

struct Stack
{
    int left_canary;

    unsigned int hash;

    int capacity;
    elem_t *data;
    int size;

    const char* status;

    int right_canary;
};

enum mode_of_resize 
{
    PUSH_MODE,
    POP_MODE
};

enum status_working
{
    NO_ERRORS,
    DATA_ADRESS_ERROR,
    STACK_ADRESS_ERROR,
    MOD_VALUE_ERROR,
    DATA_RIGHT_CANARY_ERROR,
    DATA_LEFT_CANARY_ERROR,
    STACK_RIGHT_CANARY_ERROR,
    STACK_LEFT_CANARY_ERROR,
    FILE_ERROR,
    HASH_ERROR
};

#define check_stack_on_errors_(stack)  check_stack_on_errors (stack, __FILE__, __func__, __LINE__)

const int COMMON_RATIO = 2;
const int BASIC_SIZE = 4;
const int Value_Reduce_Memory = 2;
const elem_t POISON_VALUE = 666999;
const int POISON_ADRESS = 0xDEADBEEF;

int     stack_ctor              (Stack* stack, const int size_st);
int     stack_dtor              (Stack* stack);

int     stack_push              (Stack* stack, elem_t value);
int     stack_pop               (Stack* stack, elem_t *variable);
elem_t    stack_top               (const Stack* stack);

int     stack_status            (Stack* stack);
int     check_stack_on_errors   (const Stack* stack, const char* file, const char* funct, const int line);
void    stack_dump              (const Stack* stack, const char* file, const char* funct, const int line);

unsigned int MurmurHash2 (char * key, unsigned int len);

int output_error (const Stack* stack, const char* file, const char* funct, const int line);