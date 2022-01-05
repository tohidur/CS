#include<iostream>

#include "Vector.h"

int main()
{
    Vector v1 = { 30, 32, 32, 33, 34, 35 };
    Vector v2 = { 40, 41, 42, 43, 44, 45 , 46, 47 };
    Vector v3 = { 50, 51, 52, 53, 54, 55 , 56, 57 };

    // test copy
    // v2 = v1;
    // Vector v3 {v1};

    // Test move
    // Vector v4 = std::move(v3);
    Vector v4 = v3;
    for (int i=0;i!=8;++i) {
        v4[i]+=10;
        // std::cout << v4[i] << "--" << "v3[i]" << '\n';
        std::cout << v4[i] << "--" << v3[i] << '\n';
    }
}

