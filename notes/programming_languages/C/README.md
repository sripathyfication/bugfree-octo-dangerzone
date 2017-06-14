### The C Memory Layout:-
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


# Text :- 
----------

Read from the executable file and loaded into memory. It contains the code segment (aka
executable instructions). It is read only.

# Initialized Data:- 
---------------------

The initialized data segment contains static and global variables defined and
initialized by the programmer. For e.g. global int i = 10 will go there.
It is a virtual address space. It is split into initialized read-only and initialized read-write
area.

E.g. const char c will go to initialized read-only


# Unitialized Data (BSS):-
---------------------------

This portion of global or static variables declared by the programmer but not initialized are put
the kernel here and initialized to 0.
For. e.g: global int it


