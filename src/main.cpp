#include <iostream>
#include "VectorClass.h"

int main() {
    VectorClass<int> a;
    a.pushBack(2);
    a.pushBack(3);
    a.pushBack(4);
    a.pushBack(5);
    a.pushBack(5);


    std::cout << a[0] << std::endl;
    return 0;
}
