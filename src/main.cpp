#include <iostream>
#include <vector>
#include "VectorClass.h"

int main() {
    VectorClass<int> a;
    a.pushBack(2);
    a.pushBack(2);
    a.pushBack(2);

    std::cout << a << std::endl;

    return 0;
}
