# ft_smart_pointers
Two smart pointers that normally came with c++11 made usable in c++98.
The purpose of smart pointers is to delegate the responsability to allocate
and free the memory so that you no longer have to manually say you want to free
the allocated space, and giving you more control over the ownership of the memory.
### Disclaimer
I cannot guarantee that they will work in every cases, I did test them but I'm
just a human being. If you encounter any issue with them, please report it.

## Member functions

### Constructors
default constructor : Construct a pointer that owns nothing.
Constructing a pointer with the address of a variable will dynamically allocate
enough memory to create a COPY of said pointer. 
On the other hand if you simply give a variable to them it shall pointer toward
the address of that variable and still be able to modify it like a pointer would.
Copy constructor depends on the type of pointers (See Below)

### Member functions
release(void)
return a pointer to the managed variable and release the ownership.
You might need to free it yourself if it was dynamically allocated.

get(void)
returns a pointer to the managed object it was overloaded to handle with const
smart pointers.

### Operators
The \* operator works just like with real pointers and dereferences it.Same goes
for the -> operator.
The = operator depends on the type but ensure that the pointer is moved or shared.
Also any comparaison of pointers still work like real pointers by comparing them
directly.

## Shared Pointers
Shared_pointers are the one that resemble traditional pointers the most,
any number of them can point to the same element and there will be no issues,
with that. The memory will still be freed automatically. 

## Unique Pointers
Unique pointers on the other hands are there to prevent the issue of shared,
states. If you try to assign one of them to another with the = operator or the
copy constructor the first pointers will loose ownership of the pointer while
the second one gains the ownership of the address.


