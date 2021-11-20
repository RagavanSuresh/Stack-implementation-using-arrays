/*
     Complete program of implementation and algorithms of
             stack data structures using
                        ARRAYS
                                -K.S.Ragavan
*/

/*
    Definition:
        A collection of items in which only the most recently added item may be removed.
    A real-life example is a stack of plates,
    you can only take a plate from the top of the stack,
    you can only add a plate to the top of the stack.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack  // implementing the necessary properties of the stack.
{
    int size; // since implementing stack using array maximum number of data to be hold needs to be defined before hand
    int top;  // tracks the top position element of the stack
    int stackarr[]; // stack array collection
};

struct stack* constructor(struct stack*);  // initializes and creates stack data structure
bool push(struct stack*); // to push an element at the top of the data structure
bool pop(struct stack*); // to pop the element from the top of the data structure
int peek(struct stack*); // to peek on the top most element of the data structure
bool isempty(struct stack*); // to check whether the stack is empty or not
bool isfull(struct stack*); // to check whether the stack is full or not

struct stack* constructor(struct stack* s)
{
    int size;
    printf("Enter stack capacity: ");
    scanf("%d",&size);
    s = malloc(sizeof(*s)+sizeof(int)*size); // allocates memory for the stack in computer
    s->size = size; // initializes the stack capacity
    s->top = -1; // top is -1 since start of the stack is counted from 0.
    return s;
}

// since counting starts from 0, (size-1) concludes the total number to be equal to the size

bool push(struct stack* s)
{
    if(s->top == (s->size-1))  // indicates that the stack is full and element cannot be pushed into this
        return false;
    else
    {
        int key;
        printf("Enter the value to be pushed in: ");
        scanf("%d",&key);
        s->top++; // top index is uploaded
        s->stackarr[s->top] = key; // top index is updated
        return true;
    }
}

bool pop(struct stack* s)
{
    if(s->top == -1) // indicates that the stack is empty and cannot be popped
        return false;
    else
    {
        s->top--; // index is lowered updating the top most element to the pen ultimate element
        return true;
    }
}

int peek(struct stack* s)
{
    if(s->top == -1) // indicates the stack is empty
        return;
    else
        return s->stackarr[s->top]; // the top most element is given
}

bool isempty(struct stack* s)
{
    if(s->top == -1)
        return true;
    else
        return false;
}

bool isfull(struct stack* s)
{
    if(s->top == s->size-1)
        return true;
    else
        return false;
}

int main()
{
    struct stack *s = constructor(s); // creating the stack data structure
    system("cls");
    label:
    printf("\t\t\tMenu Bar\n"); // Menu driven user interface to explore various functions of the stack
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. check empty\n");
    printf("4. check full\n");
    printf("5. Peek\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            if(!push(s))
                printf("Stack Overflow\n");
        }
        break;
        case 2:
        {
            if(!pop(s))
                printf("Stack Underflow\n");
        }
        break;
        case 3:
        {
            if(isempty(s))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
        }
        break;
        case 4:
        {
            if(isfull(s))
                printf("Stack is full\n");
            else
                printf("Stack is not full\n");
        }
        break;
        case 5:
        {
            printf("Top of the stack is: %d\n",peek(s));
        }
        break;
        default:
            printf("Enter a valid choice.\n");
    }
    char control;
    printf("Do you want to continue[Y/N]: ");
    scanf(" %c",&control);
    if(control=='y'||control=='Y')
    {
        system("pause");
        system("cls");
        goto label;
    }
    return 0;
}

/* Since stack is implemented through array the memory allocation is static hence the number of elements in the stack is limited */
