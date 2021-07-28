#include <iostream>


template <class T>
class Arithmetic
{
    private:
        T a;
        T b;

    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
};


template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}


template <class T>
T Arithmetic<T>::add()
{
    T c;
    c = a + b;
    return c;
}


template <class T>
T Arithmetic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}


int main()
{
    Arithmetic<int> ar(10, 5);
    std::cout<<ar.add()<<"\n\n";

    Arithmetic<float> ar1(2.4, 3.6);
    std::cout << ar1.sub();
}

