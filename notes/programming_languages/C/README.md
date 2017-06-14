# The C Memory Layout:-
-------------------------


                      high address  
                      ..........+--------------------+
                                | cmdling args,      |
                                | global vars        |
                                +--------------------+
                                |     stack growing  |
                                |       downwards    |
                                |....................|
                                |                    |
                                |                    |
                                |                    |
                                |....................|
                                |   heap growing     |
                                |       upwards      |
                                +--------------------+
                                |  uninitiazed data  |
                                |     (BSS)          |
                                +--------------------+
                                |  initialized data  |
                                +--------------------+
                     low address|       text         |
                     ...........+--------------------+


### Text :- 
----------

* Read from the executable file and loaded into memory. 
* It contains the code segment (aka executable instructions). 
* It is read only.

### Initialized Data:- 
---------------------

* The initialized data segment contains static and global variables defined and
initialized by the programmer. For e.g. global int i = 10 will go there.
* It is a virtual address space. 
* It is split into initialized read-only and initialized read-write
area.

E.g. const char c will go to initialized read-only


### Unitialized Data (BSS):-
---------------------------

* This portion of global or static variables declared by the programmer but not initialized are put
the kernel here and initialized to 0.
For. e.g: global int it

### Stack:-
----------
* Stack grows towards zero ( and towards the heap).
* It stores at a minimum the return address to where it was called from.
* Stack and heap grow in opposite directions. 
* A functions locally defined variables go here.
* A register called the Stack pointer keeps track of the top of the stack.
* It follows a LIFO structure.

### Heap:-
---------
* Heap begins where BSS ends and grows towards a higher memory address.
* The moment heap and stack meet, we say the memory is exhausted.
* All dynamically allocated memory comes from here.
* It is managed by malloc,realloc, brk,sbrk system calls.
* The heap is shared by all dynamically loaded libraries, shared libraries loaded by a program.


# SBRK & BRK:-
--------------

Brk and Sbrk set the programs break. I.e. the lowest addressable memory location which is just
above the BSS. 
* Brk sets this addr .
* Sbrk increments this addr by (increment) bytes. When called with 0 it returns the current program break. 
* The addressable memory now becomes from addr to the lowest stack pointer. This defines the heap region.



