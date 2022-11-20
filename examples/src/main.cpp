#include <iostream>

#include "Ratio.hpp"


int main() {
    /*
    *
    * OPERATORS CLASSIC TESTS
    * 
    */

    Ratio r1(1,2);
    Ratio r2(3,4);
    int value = 3;
    std::cout << "Ratio 1 (r1) : " ;
    r1.display();
    std::cout << "Ratio 2 (r2) : " ;
    r2.display();
    std::cout << "Value (value) : " << value << std::endl << std::endl;

    std::cout << "Addition (r1 + r2): ";
    (r1+r2).display();

    std::cout << "Addition (r1 + value): ";
    (r1+value).display();

    std::cout << "Subtraction (r1 - r2): ";
    (r1-r2).display();

    std::cout << "Subtraction (r1 - value): ";
    (r1-value).display();

    std::cout << "Multiplication (r1 * r2): ";
    (r1*r2).display();

    std::cout << "Multiplication (r1 * value): ";
    (r1*value).display();

    std::cout << "Division (r1 / r2): " ;
    (r1/r2).display();

    std::cout << "Division (r1 / value): " ;
    (r1/value).display();

    std::cout << "Inverse de r2: ";
    (r2.inverse()).display();
    
    return 0;
}
