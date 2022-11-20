#include <iostream>

#include "Ratio.hpp"


int main() {

    Ratio r1(1,2);
    Ratio r2(3,4);
    Ratio result;
    result=r1-r2;
    std::cout << "- :" << std::endl;
    std::cout <<"getNum : " << result.getNum() << std::endl;
    std::cout << "getDenom : "<< result.getDenom() << std::endl;
    // appel de ploup
    //ploup();

    Ratio r3(1,2);
    std::cout << r3.getNum()<<std::endl;
    std::cout << r3.getDenom()<<std::endl;

    result=r1*r2;
    std::cout << "* :" << std::endl;
    std::cout <<"getNum : " << result.getNum() << std::endl;
    std::cout << "getDenom : "<< result.getDenom() << std::endl;
    Ratio r4(3,4);

    Ratio r5 = r3 + r4;

    std::cout << "r1 + r2 :" << std::endl << "getNum : " << r5.getNum() << std::endl << "denum : " << r5.getDenom() << std::endl;
    
    Ratio r6 = -r3;
    // std::cout << r1.m_denom << std::endl;
    std::cout << " - r1 : " << std::endl << "getNum : " << r6.getNum() << std:: endl << "denum : " << r6.getDenom() << std::endl; 

    result=r2*2;
    std::cout << "*2 :" << std::endl;
    std::cout <<"getNum : " << result.getNum() << std::endl;
    std::cout << "getDenom : "<< result.getDenom() << std::endl;

    r1.setNum()=4;
    std::cout << "mon getNum"<< r1.getNum() << std::endl;
    
    return 0;
}
