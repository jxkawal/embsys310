/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping chars
*******************************************************************************/   

    //EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm       // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Swaps the dereferenced values of two pointers
C Prototype     : void swapCharsAsm(char* ptr1, char* ptr2)
                : Where ptr1 is a pointer to the first char, and ptr2
                : is a pointer to the second char
Parameters      : R0: char pointer, R1: char pointer
Return value    : void
*******************************************************************************/  
  
swapCharsAsm                       
    LDRB R2, [R0]        // Loads value of address of R0 (ptr1) into R2 (temp)
    LDRB R3, [R1]        // Load value of address of R1 (ptr2) into R3
    STRB R3, [R0]        // Store value of R3 into dereferenced address of R0 (ptr1)
    STRB R2, [R1]        // Store value of R2 (temp) into address of R1 (ptr2)
    
    BX LR                // return (with function result in R0)

    END
