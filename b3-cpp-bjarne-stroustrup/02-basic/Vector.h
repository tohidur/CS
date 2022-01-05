#include<initializer_list>

using namespace std;


class Vector {
private:
    double* elem;
    int sz;
public:
    // Constructors
    Vector(int s);
    Vector(std::initializer_list<double>);

    // Copy Constructors
    Vector(const Vector& a);  // copy constructor
    Vector& operator=(const Vector& a);  // copy assignment

    // Move Constructors
    Vector(Vector&& a);
    Vector& operator=(Vector&& a);

    // destructor
    ~Vector();

    // operator methods
    double& operator[] (int i) const;

    // other methods
    int size() const;
    void push_back(double);
};

