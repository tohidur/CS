#include<stdexcept>
#include<iostream>

#include "Vector.h"


// Constructors
Vector::Vector(int s):
    elem{ new double[s] },
    sz{s}
{
    if (s<0) throw std::length_error{"foo"};
}

Vector::Vector(std::initializer_list<double> lst):
    elem{ new double[lst.size()] },
    sz{ (int)lst.size() }
{
    std::copy(lst.begin(), lst.end(), elem);
}


// Copy constructor
Vector::Vector(const Vector& a):
    elem{ new double[a.sz] },
    sz{ a.sz }
{
    std::cout << "copy constructor" << "\n";
    std::cout << "to: " << this->sz << "\n";
    std::cout << "from: " << a.sz << "\n";
    std::cout << "\n \n";
    for (int i=0;i!=sz;++i)
        elem[i] = a.elem[i];
}

// Copy assignment
Vector& Vector::operator=(const Vector& a)
{
    std::cout << "copy assignment" << "\n";
    std::cout << "to: " << this->sz << "\n";
    std::cout << "from: " << a.sz << "\n";
    std::cout << "\n \n";
    double* p = new double[a.sz];
    for (int i=0;i!=a.sz;++i)
        p[i] = a.elem[i];

    delete[] elem;  // delete old elements
    elem = p;
    sz = a.sz;
    return *this;
}


// Move Constructor
Vector::Vector(Vector&& a)
    :elem{a.elem},  // grab elements from a
    sz{a.sz}
{
    std::cout << "move constructor" << '\n';
    std::cout << "a is: " << a.sz << " element object" << "\n";
    std::cout << "moving to: " << this->sz << " element object" << "\n";
    std::cout << "\n \n";
    a.elem = nullptr;  // now a has no elements
    a.sz = 0;
}

Vector& Vector::operator=(Vector&& a)
{
    std::cout << "move assignment" << '\n';
    std::cout << "a is: " << a.sz << " element object" << "\n";
    std::cout << "moving to: " << this->sz << " element object" << "\n";
    std::cout << "\n \n";

    if (&a == this)
        return *this;

    delete[] elem;

    elem = a.elem;
    sz = a.sz;

    a.elem = nullptr;
    a.sz = 0;

    return *this;
}


// Destructors
Vector::~Vector() {
    std::cout << "destructor:: deleting " << this->sz << " elements." << "\n";
    std::cout << "\n \n";
    delete[] elem;
}


// Operator functinos
double& Vector::operator[] (int i) const {
    if (i<0 || size()<=i) throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}


Vector operator+(const Vector& a, const Vector& b) {
    if (a.size()!=b.size())
        // throw Vector_size_mismatch{"vector size is not matching"};
        throw std::length_error{"vector length mismatch"};

    Vector res(a.size());

    for (int i=0;i!=a.size();++i)
        res[i]=a[i]+b[i];

    return res;
}


// Other functions
int Vector::size() const { return sz; }

