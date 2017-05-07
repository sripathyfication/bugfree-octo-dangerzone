#include <iostream>
#include <boost>

class B {
    private:
        int i = 10;
};

class A {
    private:
        boost::shared_ptr<class B *> _bshared_ptr;

};

class C {
    C(boost::shared_ptr<class B*> &b) : _bRef(b)
    {}

    private:
        boost::shared_ptr<class B *> &_bRef;
};


int main() {

    boost::shared_ptr<class B *> obj (new(class B *));
    C my (obj);

    obj.reset();

}
