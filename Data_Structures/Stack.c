#include <stdio.h>


#define StackEntry int
#define MAXSTACK   5


typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK]; 

}Stack;

void Initialize( Stack* ps )
{
    ps->top = -1;
}

int StackFull(Stack* ps)
{
    return ps->top >= MAXSTACK;
}

int StackEmpty(Stack *ps)
{
    return ps->top == -1;
}


void Push(Stack* ps , StackEntry value)
{

    if(!StackFull(ps))
    {
        ps->top++;        
        ps->entry[ps->top] = value ;

    }
}

StackEntry Pop(Stack *ps)
{
    int value;

    if(!StackEmpty(ps))
    {
        value = ps->entry[ps->top];
        ps->top--;
        return value;
    }

}

void Print_Stack(Stack *ps)
{

    if(!StackEmpty(ps))
    {
        for(int i = ps->top ; i >= 0 ; i-- )
        {
            printf("%d " , ps->entry[i] );
        }
    }
    printf("\n");
}

void StackTop( StackEntry * data , Stack * ps)
{
    if(!StackEmpty(ps))
    {
        *data = ps->entry[ps->top];
    }

}

void ClearStack(Stack * ps)
{
    ps->top = -1;
}


void Display(StackEntry e)
{
    printf("%d " , e);
}

void TraverseStack(Stack * ps , void(*pf)(StackEntry))
{
    for(int i = ps->top ; i >= 0 ; i--)
    {
        (*pf)(ps->entry[i]);
    }
    printf("\n");
}



int main(void)
{
    Stack s1;

    Initialize (&s1);


    Push(&s1 , 10);
    Push(&s1 , 20);
    Push(&s1 , 30);
    Push(&s1 , 40);
    Push(&s1 , 50);

    TraverseStack(&s1 , &Display);


    //Print_Stack(&s1);

    //Pop(&s1);
    //Pop(&s1);
    //Pop(&s1);
    //Pop(&s1);
    //Pop(&s1);

    //int value;
    //StackTop(&value , &s1);
    //printf("%d\n" , value);


    /*
    printf("%d " , Pop(&s1));
    printf("%d " , Pop(&s1));
    printf("%d " , Pop(&s1));
    printf("%d " , Pop(&s1));
    printf("%d " , Pop(&s1));
    */

    //printf("\n");
    //Print_Stack(&s1);



    return 0;
}