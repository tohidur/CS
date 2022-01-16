#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class Vec : public vector<T> {
public:
    using vector<T>::vector;  // using the constructor of the vector under
                              // the name Vec

    T& operator[](int i)  // range check
        { return vector<T>::at(i); }

    const T& operator[](int i) const  // range check const objects
    { return vector<T>::at(i); }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4};
    Vec<double> doubles = {0.1, 1.2, 2.3};

    try {
        cout << numbers.at(1) << '\n';
        cout << doubles.at(12) << '\n';
    }
    catch(out_of_range) {
       cout << "range error\n";
    }
    catch(...) {
        cerr<<"unknown exception thrown\n";
    }
}
