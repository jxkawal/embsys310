Assignment 4:

1.	To enable the clock to GPIOA, we must set bit 0 of the address 0x4002104C to 1.  This address is within the bit banding region, so we can use this technique to set this bit.  To write to this particular bit using bit banding, we actually write to a different bit which is an alias of 0x4002104C.

a.	The instructions for enabling the clock were the only significant difference when using bit binding, as this was the only code that changed in the program.  The assembly instructions for enabling the clock when using bit binding was:
	MOVS 	R0, #1
	LDR.N	R1, [PC, #0x38]
	STR		R0, [R1]
	
The instructions for doing this without bit binding was:
	LDR.N	R0, [PC, #0x3c]
	LDR		R1, [R0]
	ORRS.W	R1, R1, #1
	STR		R1, [R0]
	
b. The instructions for writing to GPIOx_ODR (which in our case is GIOA_ODR) did not change between the bit-binding and non-bit-binding versions because this part of the code did not change.  The code is both cases was simply ORing with what was already there to set the bit.  In C, this was
GPIOA_ODR |= ORD5;
And the assembly for this was:
  0x800'0056: 0x480b         LDR.N     R0, [PC, #0x2c]         ; 0x4800'0014
   0x800'0058: 0x6801         LDR       R1, [R0]
   0x800'005a: 0xf051 0x0120  ORRS.W    R1, R1, #32             ; 0x20
   0x800'005e: 0x6001         STR       R1, [R0]
   0x800'0060: 0xe00a         B.N       0x800'0074
   
  The only change was a difference in where the code branches to at the end, because the ORR needed for the non-bit-banding instruction was pushing out the rest of the code.
  
2.	a. The calling function first moves all of the arguments into registers.  When there are too many values, it will also use the STR instruction to store the data in memory with some offset.  
	b. Once all the arguments have been stored, the code uses the BL instruction to jump to the func1 code.
	c. Inside func1, after the code the function performs, there is extra code to pop the stack, getting back the address we left off from, and then a branch to jump to that address.
	d. After we return from func1, the very first instruction executed is to pop the stack as we are done with func1 and the data we passed to it.
	
3. Shown in source files.
