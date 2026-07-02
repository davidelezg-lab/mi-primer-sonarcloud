#include <iostream>
#include "suma.h"

int main() {

    if (suma(10, 20) == 30) {

        std::cout << "TEST OK" << std::endl;

        return 0;
    }

    std::cout << "TEST ERROR" << std::endl;

    return 1;
}