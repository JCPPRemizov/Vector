#include <iostream>
#include <vector>
#include "VectorClass.h"

int main() {
    VectorClass<std::string> a;
    VectorClass<std::string> b;

    a.pushBack("efef");
    a.pushBack("hui");

    a.insert(1, "govno");


    std::cout << a << std::endl;
    return 0;
}
