#include <iostream>
#include <stdlib.h>


class A {
    public:
        A () { std::cout << "In Base constructor" << std::endl; }
        virtual ~A () { std::cout << "In Base destructor" << std::endl; }
};

class B : public A {
    public:
        B () { std::cout << " In derived constructor " << std::endl;}
        ~B () { std::cout << " In derived destructor " << std::endl;}
};

int main() {

    A *b = new B();
    delete(b);

    return 0;
}
