#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <malloc.h>


/*
typedef int T;
typedef struct Stack_tag {
    T *data;
    size_t size;
    size_t top;
} Stack_t;
*/

#define N 100
#define INIT_SIZE 10
#define MULTIPLIER 2
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

int prior(char c)
{
    switch (c)
    {
        case '(':
            return 1;
        case '+':
            return 2;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 3;
    }
}

/*
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
*/

void deleteStack(Stack_t **stack)
{
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

/*
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

*/

int main()
{
    int i = 0, j = 0;
    Stack_t *s = createStack();

    char buf,str_in[N],str_out[N];

    printf("plz enter ");
    gets(str_in);

    while (str_in[i])
    {
//ÅÑËÈ ÝËÅÌÅÍÒ ÑÒÐÎÊÈ ×ÈÑËÎ ÏÐÎÑÒÎ ÇÀÏÈÑÛÂÀÅÌ ÅÃÎ Â ÑÒÐÎÊÓ
        if ( (str_in[i] >= '0') && (str_in[i] <= '9') )
            {
                str_out[j] = str_in[i];
                ++j;
            }
//ÅÑÈË ÝËÅÌÅÍÒ ÑÒÐÎÊÈ ÎÒÊÐÛÂÀÞÙÀß ÑÊÎÁÊÀ ÇÀÍÎÑÈÌ ÅÅ Â ÑÒÝÊ
        if ( str_in[i] == '(' ) push(s,str_in[i]);
//ÅÑËÈ ÝËÅÌÅÍÒ ÑÒÐÎÊÈ ÇÀÊÐÛÂÀÞÙÀß ÑÊÎÁÊÀ ÇÀÏÈÑÛÂÀÅÌ ÂÑÅ ÝËÅÌÅÍÒÛ ÈÇ ÑÒÝÊ Â ÑÒÐÎÊÓ ÏÎÊÀ ÍÅ ÂÑÒÐÅÒÈÌ ÒÀÌ ÎÒÊÐÛÂÀÞÙÓÞ ÑÊÎÁÊÓ ÅÅ ÏÐÎÑÒÎ ÂÛÊÈÄÛÂÀÅÌ ÊÀÊ È ÇÀÊÐÛÂÀÞÙÓÞ
        if ( str_in[i] == ')' )
            while()
                {
                    buf = pop(s);
                    if ( buf != '(' )
                        {
                            str_out[j]=buf;
                            ++j;
                        }
                    else
                        break;
                }
//ÅÑËÈ ÝËÅÌÅÍÒ ÑÒÐÎÊÈ ÝÒÎ ÎÏÅÐÀÒÎÐ + - * /
        if ( (prior(str_in[i]) == 2) || (prior(str_in[i]) == 3) )
            {
                if ( s->top == 0 ) push(s,str_in[i]);
                else
                {
                    while ()
                    {
                        if ( (prior(str_in[i]) > prior(s->top)) || (s->top == 0) )
                            {
                                push(s,str_in[i]);
                                break;
                            }
                        else
                            {
                                buf = pop(s);
                                str_out[j] = buf;
                                ++j;
                            }
                    }
                }
            }
        ++i;
    }
//ÂÑÅ ÎÑÒÀÂØÈÅÑß ÝËÅÌÅÍÒÛ ÑÒÝÊÀ ÇÀÏÈÑÛÂÀÅÌ Â ÑÒÐÎÊÓ
    while ( s->top != 0 )
    {
        str_out[j]=pop(s);
        ++j;
    }


    deleteStack(&s);
    system("pause");
}
