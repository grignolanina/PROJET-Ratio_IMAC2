// *** This main is used to do mathematical test to see how use some opererators with ratios. 
// All the explainations needed are in the report file of the project *** 

#include <iostream>
#include <cmath>
#include "Ratio.hpp"
#include <iomanip>

int main(){

    // ----- 1. SQUARE ROOT -----

    // We want to know what is better between doing a square root on a ratio or doing
    //it with the numerator and denominator separately 


    //enter values for num and denom
    int num = 1;
    int denom = 4;
    //enter the exact value if knowned
    double exactValue = 0.5;

    //ratio of the previous numbers
    Ratio<int> r1(num,denom);
    Ratio<int> r2(r1);

    //Ratio<int> r3 = r1 * 2 + r2 * 2;
    
    //sqrt of the ratio 
    double racineRatio = r1.sqrt();

    //sqrt of the separte numbers
    //double racineDouble = sqrt(r3.getNum())/sqrt(r3.getDenom());
    double racineDouble = sqrt((double)num/denom);

    std::cout << "sqrt(ratio) : " << std::setprecision(30) << racineRatio << std::endl;
    std::cout << "sqrt(num)/sqrt(denum)  : " << std::setprecision(30) << racineDouble << std::endl;

    std::cout << "Difference between both sqrt : " << std::setprecision(20) << std::abs(racineDouble - racineRatio) << std::endl;
    std::cout << "Difference with exact value (ratio) : " << std::setprecision(20) << std::abs(racineRatio - exactValue) << std::endl;
    std::cout << "Difference with exact value : " << std::setprecision(20) << std::abs(racineDouble- exactValue) << std::endl<<std::endl;

    
    // ----- 2. COSINUS -----

    Ratio<int> piSurTrois = r1.pi()/3;
    double exactValueCos = 0.5;

    double cosRatio = piSurTrois.cosinus();
    double cosRatio2 = piSurTrois.cosinus2();

    std::cout << "cos1(ratio) : " << std::setprecision(20) << cosRatio << std::endl;
    std::cout << "cos2(ratio)  : " << std::setprecision(20) << cosRatio2 << std::endl;

    std::cout << "Difference between both sqrt : " << std::setprecision(20) << std::abs(cosRatio - cosRatio2) << std::endl;
    std::cout << "Difference with exact value : " << std::setprecision(20) << std::abs(cosRatio - exactValueCos) << std::endl<<std::endl;

    // ----- 3. SINUS -----

    Ratio<int> piSurSix = r1.pi()/6;
    double exactValueSin = 0.5;

    double sinRatio = piSurSix.sinus();

    std::cout << "sin (ratio) : " << std::setprecision(20) << sinRatio << std::endl;
    std::cout << "Difference with exact value : " << std::setprecision(20) << std::abs(sinRatio - exactValueSin) << std::endl<<std::endl;

    // ----- 4. POWER -----

    std::cout << "Power1(ratio) : " << r1.pow1(3) <<std::endl;
    Ratio<int> exactValuePow1(1,64);

    std::cout << "Difference with exact value : " << std::setprecision(20) << (r1.pow1(3) - exactValuePow1).abs() << std::endl<<std::endl;

    std::cout << "Power2 (ratio) : " << r1.pow2(3) <<std::endl;
    Ratio<int> exactValuePow2(1,64);

    std::cout << "Difference with exact value : " << std::setprecision(20) << (r1.pow2(3) - exactValuePow2).abs() << std::endl<<std::endl;
    

    return 0; 
}