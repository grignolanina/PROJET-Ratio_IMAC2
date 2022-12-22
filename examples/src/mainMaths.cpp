// *** This main is used to do mathematical test to see how use some opererators with ratios. 
// All the explainations needed are in the report file of the project *** 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>

#include "Ratio.hpp"

int main(){

    // build a seed to compare time function
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
    srand(seed);

    //enter values for num and denom (will be use of the different tests)
    int num = 1;
    int denom = 4;

    //creation of the ratios
    ratio::Ratio<int> r1(num,denom);
    ratio::Ratio<int> r2(r1);


    // ----- 1. SQUARE ROOT -----

    // We want to know what is better between doing a square root on a ratio or doing
    //it with the numerator and denominator separately 

    
    //enter the exact result if knowned
    double exactValue = 0.5;
    
    //sqrt(ratio)
    double racineRatio = r1.sqrt();

    //sqrt(num)/sqrt(denum)
    double racineDouble = r1.sqrt2();

    //display of the first result
    std::cout << "sqrt(ratio) : " << std::setprecision(30) << racineRatio << std::endl;

    //calculates the execution time of sqrt1
    auto sqrtStart1 = std::chrono::steady_clock::now();
    r1.sqrt();
    auto sqrtEnd1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = sqrtEnd1-sqrtStart1;
    std::cout << "Time of execution sqrt1 : " << elapsed_seconds1.count() << " s" << std::endl;
    std::cout << "Difference with exact value sqrt(ratio) : " << std::setprecision(20) << std::abs(racineRatio - exactValue) << std::endl<<std::endl;
    
    //display of the second result
    std::cout << "sqrt(num)/sqrt(denum)  : " << std::setprecision(30) << racineDouble << std::endl;

    //calculates the execution time of sqrt1
    auto sqrtStart2 = std::chrono::steady_clock::now();
    r1.sqrt2();
    auto sqrtEnd2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = sqrtEnd2-sqrtStart2;
    std::cout << "temps calcul fonction récursive : " << elapsed_seconds2.count() << " s" << std::endl;
    std::cout << "Difference with exact value sqrt(num)/sqrt(denum) : " << std::setprecision(20) << std::abs(racineDouble- exactValue) << std::endl<<std::endl;

    
    // ----- 2. COSINUS -----
    //test of the implementation and of one bad approximation

    //trigonometric ratio
    ratio::Ratio<int> piSurTrois = r1.pi()/3;

    //exact result if knowned
    double exactValueCos = 0.5;

    //calculates the cosinus
    double cosRatio = piSurTrois.cosinus();
    double cosApprox = piSurTrois.cosinus2();

    std::cout << "cos1(ratio) : " << std::setprecision(20) << cosRatio << std::endl;
    std::cout << "cos2(ratio)  : " << std::setprecision(20) << cosApprox << std::endl;

    std::cout << "Difference between both sqrt : " << std::setprecision(20) << std::abs(cosRatio - cosApprox) << std::endl;
    std::cout << "Difference with exact value : " << std::setprecision(20) << std::abs(cosRatio - exactValueCos) << std::endl<<std::endl;

    // ----- 3. SINUS -----

    //trigonometric ratio
    ratio::Ratio<int> piSurSix = r1.pi()/6;
    double exactValueSin = 0.5;

    //calculates the sinus
    double sinRatio = piSurSix.sinus();

    //display
    std::cout << "sin (ratio) : " << std::setprecision(20) << sinRatio << std::endl;
    std::cout << "Difference with exact value : " << std::setprecision(20) << std::abs(sinRatio - exactValueSin) << std::endl<<std::endl;

    // ------ 3(bis). TEST OF TAGENT -----



    // ----- 4. POWER -----

    //display pow
    std::cout << "Power1(ratio) : " << r1.pow1(15) <<std::endl;
    ratio::Ratio<int> exactValuePow1(1,64);

    //calculates the execution time of pow1
    auto powStart1 = std::chrono::steady_clock::now();
    r1.pow1(15);
    auto powEnd1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = powEnd1-powStart1;
    std::cout << "Execution time pow1 (recursive): " << elapsed_seconds3.count() << " s" << std::endl;
    std::cout << "Difference with exact value : " << std::setprecision(20) << (r1.pow1(3) - exactValuePow1).abs() << std::endl<<std::endl;


    //display pow2
    std::cout << "Power2 (ratio) : " << r1.pow2(15) <<std::endl;
    ratio::Ratio<int> exactValuePow2(1,64);

    //calculates execution time
    auto powStart2 = std::chrono::steady_clock::now();
    r1.pow2(15);
    auto powEnd2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds4 = powEnd2-powStart2;
    std::cout << "Execution time of pow2 (cmath library) : " << elapsed_seconds4.count() << " s" << std::endl;
    std::cout << "Difference with exact value : " << std::setprecision(20) << (r1.pow2(3) - exactValuePow2).abs() << std::endl<<std::endl;


    // ----- 5. EXPONENTIAL ------


    // ----- 6. INTEGER PART ------

    ratio::Ratio<int> r6 = r1 * 25;
    std::cout << "Integer Part of " << r6 << " : " << r6.intPart() << std::endl;


    //test exception negative sqrt
    #if 0
        ratio::Ratio<int> sqrtNeg(-4,7);
        try{
            sqrtNeg.sqrt();
        }catch(const RatioException &e){
            std::cerr << e.what() << std::endl;
        }

        try{
            sqrtNeg.sqrt2();
        }catch(const RatioException &e){
            std::cerr << e.what() << std::endl;
        }
    #endif

    



    

    return 0; 
}