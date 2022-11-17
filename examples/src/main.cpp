#include <iostream>

#include "Ratio.hpp"


int main() {

    // appel de ploup
    //ploup();

    Ratio r1(1,2);
    std::cout << r1.num()<<std::endl;
    std::cout << r1.denom()<<std::endl;

    Ratio r2(3,4);

    Ratio r3 = r1 + r2;

    std::cout << "r1 + r2 :" << std::endl << "num : " << r3.num() << std::endl << "denum : " << r3.denom() << std::endl;
    
    // std::cout << r1.m_denom << std::endl;

    
    return 0;
}
