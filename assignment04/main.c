#include<assert.h>
#include "stack.h"

int main()
{
    int result1;
    int result2;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    init_stack();
    
    // Act:
    result1 = pop(&testInt);
      
    // Assert:
    assert(-1 == result1);
    assert(0 == testInt);
    
    
    // *******************************************************************
    // Test2: Fill stack and push again
    // *******************************************************************
    init_stack();
    assert(0 == push(1));
    assert(0 == push(2));
    assert(0 == push(3));
    
    // Should fail
    assert(-1 == push(4));
    
    // *******************************************************************
    // Test3: Push onto stack, then retrieve
    // *******************************************************************
    init_stack();
    assert(0 == push(5));
    
    result1 = pop(&testInt);
    
    assert(0 == result1);
    assert(5 == testInt);
    
    
}