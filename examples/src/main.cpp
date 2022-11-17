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

    result=r1*r2;
    std::cout << "* :" << std::endl;
    std::cout <<"getNum : " << result.getNum() << std::endl;
    std::cout << "getDenom : "<< result.getDenom() << std::endl;

    result=r2*2;
    std::cout << "*2 :" << std::endl;
    std::cout <<"getNum : " << result.getNum() << std::endl;
    std::cout << "getDenom : "<< result.getDenom() << std::endl;

    r1.setNum()=4;
    std::cout << "mon getNum"<< r1.getNum() << std::endl;
    
    return 0;
}
