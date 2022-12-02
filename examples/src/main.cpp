#include <iostream>

#include "Ratio.hpp"


int main() {
    /*
    *
    * OPERATORS CLASSIC TESTS
    * 
    */

    Ratio<int> r1(1,2);
    Ratio<int> r2(3,4);
    Ratio<int> r3(r1);
    int value = 3;
    float fvalue = 0.78;
    float negfvalue = -2.5;

    std::cout << "Ratio 1 (r1) : " ;
    r1.display();
    std::cout << "Ratio 2 (r2) : " ;
    r2.display();
    std::cout << "Ratio 3 (r3) : " ;
    r3.display();
    std::cout << "Value (value) : " << value << std::endl;
    std::cout << "Float Value (fvalue) : " << fvalue << std::endl;
    std::cout << "Negative Float Value (negfvalue) : " << negfvalue << std::endl << std::endl;

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
    
    std::cout << "Conversion de fvalue en ratio r4 : " ;

    // Ratio r4(fvalue);
    // r4.display();

    // std::cout << "Conversion de negfvalue en ratio r5 : " ;
    // Ratio r5(negfvalue);
    // r5.display();

    std::cout << "Test r1 == r2 : ";
    std::cout << (r1 == r2) <<std::endl;

    std::cout << "Test r1 == r3 : ";
    std::cout << (r1 == r3) <<std::endl;

    std::cout << "Test r1 != r2 : ";
    std::cout << (r1 != r2) <<std::endl;

    std::cout << "Test r1 != r3 : ";
    std::cout << (r1 != r3) <<std::endl;

    std::cout << "Test r1 < r3 : ";
    std::cout << (r1 < r3) << std::endl;

    std::cout << "Test r1 <= r3 : ";
    std::cout << (r1 <= r3) <<std::endl;

    std::cout << "Test r1 > r2 : ";
    std::cout << (r1 > r2) <<std::endl;

    // try {
    //     Ratio r5(3,0);
    // }
    // catch(const std::exception &e){
	//     std::cout << "c'est quoi ?" << e.what() ;
    // }

    std::cout << "Essai d'affichage avec ostream : " <<std::endl;
    std::cout<< r1;
    

    return 0;
}
