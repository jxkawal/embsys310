#include "stack.h"

#define STACK_SIZE 3



int store[STACK_SIZE];
int size = 0;

void init_stack() {
    size = 0;
    for (int i = 0; i < STACK_SIZE; ++i) {
        store[i] = 0;
    }
}

// push(int element)
// pushes an element on to the stack
int push(int data) {
    if (size == STACK_SIZE) {
        return -1;
    }
    
    store[size] = data;
    ++size;
    
    return 0;
}

// pop()
// pops an element off the top of the stack
// returned values are error codes
int pop(int* data) {
    if (size == 0) {
        return -1;
    }
    
    *data = store[size - 1];
    --size;
    
    return 0;
}