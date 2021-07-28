#include<iostream>


int main() {
    int A[5];
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    int B[5] = {2, 4, 6, 8, 10};
    int C[] = {2, 4, 6, 8, 10};

    std::cout<<sizeof(A)<<std::endl;
    std::cout<<A[1]<<std::endl;
    printf("%d\n", A[2]);


    for (int x:C) {
        std::cout<<x<<std::endl;
    }

    return 0;
}

