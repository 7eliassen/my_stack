#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {

    int *collection;
    int capacity;
    int size;

} Stack;

Stack* create_stack(int capacity);
void delete_stack(Stack *stack);
bool pop(Stack *stack, int *value);
bool push(Stack *stack, int value);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);


int main()
{
    Stack *my_stack = create_stack(3);
    push(my_stack, 3);
    push(my_stack, 5);
    push(my_stack, 11);
    int buf;
    pop(my_stack, &buf);
    printf("%d\n", buf);
    pop(my_stack, &buf);
    printf("%d\n", buf);
    pop(my_stack, &buf);
    printf("%d\n", buf);
    delete_stack(my_stack);
    return 0;
}

Stack *create_stack(int capacity) {
    Stack *stack = malloc(sizeof(Stack));

    if (stack == NULL) {
        return NULL;
    }

    stack->collection = malloc(sizeof(int) * capacity);

    if (stack->collection == NULL) {
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;

}

void delete_stack(Stack *stack) {
    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack) {
    if (stack->size == stack->capacity) {
        return true;
    } else {
        return false;
    }
}

bool is_empty(Stack *stack) {
    if (stack->size == 0) return true;
    else return false;
}

bool push(Stack *stack, int value) {
    if (!is_full(stack)) {
        stack->collection[stack->size] = value;
        stack->size++;
        return true;
    } else {
        return false;
    }
}

bool pop(Stack* stack, int *value) {
    if (is_empty(stack)) return false;
    *value = stack->collection[stack->size - 1];
    stack->size--;
}


