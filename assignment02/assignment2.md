Assignment 2

1. 	a. -2147483648
	b. 0x80000000
	c. N is set because this is a negative number.
	   V is set because it is an overflow condition since we incremented the highest value for a signed 32 bit value, 0x7FFFFFFF.
	   
2.	a. counter goes from -1 (0xFFFFFFF) to 0 when incremented.
	b. N is not set after the increment because 0 is not negative.
	   V is also not set as no overflow occurred going from -1 to 0.
	   
3.	a. 2147483648
	b. N is set to one despite counter being an unsigned int.  This must be because N is set to one whenever the MSB is 1.
	   V is set as well. This processor must consider it an overflow if an operation causes the MSB to change from 0 to 1.
	   
4.	a. counter goes from 4294967295 to 0 when incremented.
	b. N is 0 because MSB is 0.
	   V is 0 since there was no overflow - MSB was 0 and remained 0.
	   
5.	a. global scope
	b. no
	c. watch window
	d. 0x2000000
	
6.	a. 4
	b. Line 3 sets the value of the pointer to the address location where counter is stored.  In the subsequent lines, the pointer is dereferenced (and now contains the value of counter) and then incremented.  This is done 3 times, giving counter the value of 3, then counter is incremented directly to give it the value of 4.
	
7.	a. 0x2000000, just like in the simulator.
	b. RAM.  ROM is read only, and we can change the value of counter.
	c. 4, just like in the simulator.