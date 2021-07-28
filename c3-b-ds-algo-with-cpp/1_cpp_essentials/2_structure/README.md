### Structure

#### Definition and Declaration
```cpp
struct Reactangle
{
    int length;
    int breadth;
};

int main() {
    struct Reactangle r;
    r.length = 15;
    r.breadth = 10;

    struct Reactangle s={10, 5};
}
```

#### Examples
```cpp

//Complex number
// a + ib
struct Complex
{
    int real;
    int img;
}

// Student info
struct Student
{
    int rool;
    char name[25];
    char dept[10];
    char address[50];
}
```

