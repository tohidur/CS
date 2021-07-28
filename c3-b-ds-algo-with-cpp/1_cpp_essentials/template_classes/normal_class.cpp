class Arithmetic
{
    private:
        int a;
        int b;

    public:
        Arithmetic(int a, intb);
        int add();
        int sub();
};


Arithmetic::Arithmetic(int a, int b)
{
    this -> a = a;
    this -> b;
};


int Arithmetic::add()
{
    int c;
    c = a + b;
    return c;
}


int Arithmetic::sub()
{
    int c;
    c = a - b;
    return c;
}

