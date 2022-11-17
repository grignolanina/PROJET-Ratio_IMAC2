#include <iostream>

#include "Ratio.hpp"


int main() {

    // appel de ploup
    //ploup();

    Ratio r3(1,2);
    std::cout << r3.num()<<std::endl;
    std::cout << r3.denom()<<std::endl;

    Ratio r4(3,4);

    Ratio r5 = r3 + r4;

    std::cout << "r1 + r2 :" << std::endl << "num : " << r5.num() << std::endl << "denum : " << r5.denom() << std::endl;
    
    Ratio r6 = -r3;
    // std::cout << r1.m_denom << std::endl;
    std::cout << " - r1 : " << std::endl << "num : " << r6.num() << std:: endl << "denum : " << r6.denom() << std::endl; 

    
    return 0;
}
