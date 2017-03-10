#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
typedef int T;
typedef struct Stack_tag {
    T *data;
    size_t size;
    size_t top;
} Stack_t;

#define INIT_SIZE 10
#define MULTIPLIER 2
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

Stack_t* createStack()
{
    Stack_t *out = NULL;
    out = (Stack_tag*)malloc(sizeof(Stack_t));
    if (out == NULL)
        {
        exit(OUT_OF_MEMORY);
        }
    out->size = INIT_SIZE;
    out->data = (int*)malloc(out->size *sizeof(T));
    if (out->data == NULL)
        {
        free(out);
        exit(OUT_OF_MEMORY);
        }
    out->top = 0;
    return out;
}

void deleteStack(Stack_t **stack)
{
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize(Stack_t *stack)
{
    stack->size *= MULTIPLIER;
    stack->data = (int*)realloc(stack->data, stack->size * sizeof(T));
    if (stack->data == NULL)
        {
        exit(STACK_OVERFLOW);
        }
}
void push(Stack_t *stack, T value)
{
    if (stack->top >= stack->size)
        {
        resize(stack);
        }
    stack->data[stack->top] = value;
    stack->top++;
}
T pop(Stack_t *stack)
 {
    if (stack->top == 0)
        {
        exit(STACK_UNDERFLOW);
        }
    stack->top--;
    return stack->data[stack->top];
}
T peek(const Stack_t *stack)
{
    if (stack->top <= 0)
        {
        exit(STACK_UNDERFLOW);
        }
    return stack->data[stack->top - 1];
}
void implode(Stack_t *stack)
{
    stack->size = stack->top;
    stack->data = (int*)realloc(stack->data, stack->size * sizeof(T));
}
int main()
{
    int i;
    Stack_t *s = createStack();

    for (i = 0; i < 10; i++)
        {
        push(s, i);
        }
    for (i = 0; i < 10; i++)
        {
        printf("%d ", peek(s));
        printf("%d ", pop(s));
        }

    deleteStack(&s);
    _getch();
}
