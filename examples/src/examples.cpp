#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>


#include "Ratio.hpp"

int main() {
	// build a seed to compare time function
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
    srand(seed);


	std::cout << "Here you will find different examples of uses of the library accompanied by some comments." << std::endl <<std::endl;

	std::cout << "\033[94m \033[4mConstructors :\033[0m" <<std::endl;
	ratio::Ratio<int> defaultConstructor;
	std::cout << "• Default constructors : " << defaultConstructor<< std::endl;
	ratio::Ratio<int> classicConstructor(6,-12);
	std::cout << "• Classic constructors (param : num = 6 et denom = -12) : " << classicConstructor << std::endl;
	std::cout<< "-> The fonction irreductible reduce the ratio at his irreductible form"  << std::endl;
	ratio::Ratio<int> copieConstructor(classicConstructor);
	std::cout << "• Copie constructors (param : classicConstructor) : " << copieConstructor<< std::endl;
	ratio::Ratio<int> floatConstructor(-0.25);
	std::cout << "• Float constructors (param : -0.25) : " << floatConstructor << std::endl<< std::endl;


	/// put if on 1 to activate the exception test 
	#if 0
	std::cout << "\033[94m \033[4mConstructor exceptions :\033[0m put if on 1 to activate the exception test you want" <<std::endl;

		//test with a 0 at the denominator
		#if 0
			std::cout << "• Constructors with denom equal to 0 (param : num = 2 et denom = 0) : " << std::endl<< std::endl;
			ratio::Ratio<int> exceptConstructor(2,0);
			// try {
			//    ratio::Ratio<int> exceptConstructor(2,0);
			// }
			// catch(const RatioException &e){
			//     std::cerr << e.what() << std::endl;
			// }
		#endif

		//test about the type in the constructor with the convertFloatToRatio
		#if 0
			std::cout << "• Constructors with char (param : 'hah') : " << std::endl;
			ratio::Ratio<int> rtest("hah");

			// try {
			//    ratio::Ratio<int> rtest("hah");
			// }
			// catch(const RatioException &e){
			//     std::cerr << e.what() << std::endl;
			// }
		#endif

		//test about the type in the constructor
		#if 0
			char char1 = '1';
			char char2 = '2';
			std::cout << "• Constructors with char (param : char1 ='1' and char2='2') : " << std::endl;
			ratio::Ratio<char> rtest(char1, char2);

			// try {
			//    char char1 = '1';
			// 	char char2 = '2';
			// 	std::cout << "• Constructors with char (param : char1 ='1' and char2='2') : " << std::endl;
			// 	ratio::Ratio<char> rtest(char1, char2);
			// }
			// catch(const RatioException &e){
			//     std::cerr << e.what() << std::endl;
			// }
		#endif

	#endif


	std::cout << "\033[94m \033[4mSpecific ratios :\033[0m" <<std::endl;
	std::cout << "• zero : " << ratio::Ratio<int>::zero() << std::endl;
	std::cout << "• infinity : " << ratio::Ratio<int>::infinite() << std::endl;
	std::cout << "• pi : "<< ratio::Ratio<int>::pi() << std::endl << std::endl;

	
	
	std::cout << "\033[94m \033[4mOperators :\033[0m" <<std::endl;
	ratio::Ratio<int> ratio1(1,4);
	ratio::Ratio<int> ratio2(1,2);
	int ivalue = 3;
	float nfvalue = -0.5;
	std::cout << "Two ratio, an int and a float negative value are create for the following test : " << std::endl;
	std::cout << "• ratio1 : " << ratio1 << std::endl;
	std::cout << "• ratio2 : " << ratio2 << std::endl;
	std::cout << "• int value : "<< ivalue << std::endl;
	std::cout << "• negative float value : "<< nfvalue << std::endl << std::endl;


	std::cout << "\033[36mPlus : \033[0m" << std::endl;
	std::cout << "• ratio1 + ratio2 = " << ratio1 << " + "<< ratio2<< std::endl;
	std::cout << "    Expected : 3/4"  << std::endl;
	std::cout << "    Current : "<< ratio1+ratio2 << std::endl;

	std::cout << "• ratio1 + ivalue = " << ratio1 << " + "<< ivalue<< std::endl;
	std::cout << "    Expected : 13/4"  << std::endl;
	std::cout << "    Current : "<< ratio1+ivalue << std::endl;

	std::cout << "• ratio1 + nfvalue = " << ratio1 << " + ("<< nfvalue<< ")"<<std::endl;
	std::cout << "    Expected : 1/2"  << std::endl;
	std::cout << "    Current : "<< ratio1+nfvalue << std::endl<<std::endl;



	std::cout << "\033[36mMinus : \033[0m" << std::endl;
	std::cout << "• ratio1 - ratio2 = " << ratio1 << " - "<< ratio2<< std::endl;
	std::cout << "   Expected : -1/4"  << std::endl;
	std::cout << "   Current : "<< ratio1-ratio2 << std::endl;

	std::cout << "• ratio1 - ivalue = " << ratio1 << " - "<< ivalue<< std::endl;
	std::cout << "    Expected : -11/4"  << std::endl;
	std::cout << "    Current : "<< ratio1-ivalue << std::endl;

	std::cout << "• ratio1 - nfvalue = " << ratio1 << " - ("<< nfvalue<< ")"<<std::endl;
	std::cout << "    Expected : 3/4"  << std::endl;
	std::cout << "    Current : "<< ratio1-nfvalue<< std::endl<<std::endl;



	std::cout << "\033[36mMultiplication : \033[0m" << std::endl;
	std::cout << "• ratio1 * ratio2 = " << ratio1 << " * "<< ratio2<< std::endl;
	std::cout << "    Expected : 1/8"  << std::endl;
	std::cout << "    Current : "<< ratio1*ratio2 << std::endl;

	std::cout << "• ratio1 * ivalue = " << ratio1 << " * "<< ivalue<< std::endl;
	std::cout << "    Expected : 3/4"  << std::endl;
	std::cout << "    Current : "<< ratio1*ivalue << std::endl;

	std::cout << "• ratio1 * nfvalue = " << ratio1 << " * ("<< nfvalue<< ")"<<std::endl;
	std::cout << "    Expected : -1/8"  << std::endl;
	std::cout << "    Current : "<< ratio1*nfvalue << std::endl;

	std::cout << "• ratio1 * 0 = " << ratio1 << " * 0"<<std::endl;
	std::cout << "    Expected : 0/1"  << std::endl;
	std::cout << "    Current : "<< ratio1*0 << std::endl <<std::endl;


	std::cout << "\033[36mDivision : \033[0m" << std::endl;
	std::cout << "• ratio1 / ratio2 = " << ratio1 << " / "<< ratio2<< std::endl;
	std::cout << "   Expected : 1/2"  << std::endl;
	std::cout << "   Current : "<< ratio1/ratio2 << std::endl;

	std::cout << "• ratio1 / ivalue = " << ratio1 << " / "<< ivalue<< std::endl;
	std::cout << "    Expected : 1/12"  << std::endl;
	std::cout << "    Current : "<< ratio1/ivalue << std::endl;

	std::cout << "• ratio1 / nfvalue = " << ratio1 << " / ("<< nfvalue<< ")"<<std::endl;
	std::cout << "    Expected : -3/1"  << std::endl;
	std::cout << "    Current : "<< ratio1/nfvalue<< std::endl;

	std::cout << "• ratio1 / 0 = " << ratio1 << " / 0"<<std::endl;
	std::cout << "    Expected : 1/0 (infinity)"  << std::endl;
	std::cout << "    Current : "<< ratio1/0<< std::endl << std::endl;

	std::cout << "\033[36mAffectation after operations : \033[0m" << std::endl;
	std::cout << "• ratio2 += ratio1  = " << ratio2 << " += "<< ratio1<<std::endl;
	std::cout << "    Expected : 3/4"  << std::endl;
	std::cout << "    Current : "<< (ratio2 += ratio1) << std::endl;

	std::cout << "• ratio2 -= 2 = " << ratio2 << " -= 2"<<std::endl;
	std::cout << "    Expected : -5/4"  << std::endl;
	std::cout << "    Current : "<< (ratio2 -= 2) << std::endl;

	std::cout << "• ratio2 *= 2  = " << ratio2 << " *= 2" <<std::endl;
	std::cout << "    Expected : -5/2"  << std::endl;
	std::cout << "    Current : "<< (ratio2 *= 2) << std::endl;

	std::cout << "• ratio2 /= ratio2 = " << ratio2 << " /= " << ratio1<<std::endl;
	std::cout << "    Expected : -10/1"  << std::endl;
	std::cout << "    Current : "<< (ratio2/=ratio1) << std::endl<<std::endl;






	std::cout << "\033[94m \033[4mCompare operators :\033[0m" << std::endl;
	std::cout << "We will use the same variables as for the other part" << std::endl << std::endl;
	
	std::cout << "\033[36mOperator == : \033[0m" << std::endl;
	std::cout << "• (ratio1==ratio2) : (" << ratio1 << " == "<< ratio2 << ")"<< std::endl;
	std::cout << "   Expected : 0"  << std::endl;
	std::cout << "   Current : "<< (ratio1==ratio2) << std::endl;

	std::cout << "• (ratio1==ratio1) : (" << ratio1 << " == "<< ratio1 << ")"<< std::endl;
	std::cout << "   Expected : 1"  << std::endl;
	std::cout << "   Current : "<< (ratio1==ratio1) << std::endl;

	std::cout << "• (ratio1==ivalue) : (" << ratio1 << " == "<< ivalue<< ")"<< std::endl;
	std::cout << "   Expected : 0"  << std::endl;
	std::cout << "   Current : "<< (ratio1==ivalue) << std::endl;

	std::cout << "• (ratio1==nfvalue) : (" << ratio1 << " == "<< nfvalue<< ")"<< std::endl;
	std::cout << "   Expected : 0"  << std::endl;
	std::cout << "   Current : "<< (ratio1==nfvalue) << std::endl<< std::endl;



	std::cout << "\033[36mOperator != : \033[0m" << std::endl;
	std::cout << "• (ratio1!=ratio2) : (" << ratio1 << " != "<< ratio2 << ")"<< std::endl;
	std::cout << "   Expected : 1"  << std::endl;
	std::cout << "   Current : "<< (ratio1!=ratio2) << std::endl;

	std::cout << "• (ratio1!=ratio1) : (" << ratio1 << " != "<< ratio1<< ")"<< std::endl;
	std::cout << "   Expected : 0"  << std::endl;
	std::cout << "   Current : "<< (ratio1!=ratio1) << std::endl;

	std::cout << "• (ratio1!=ivalue) : (" << ratio1 << " != "<< ivalue<< ")"<< std::endl;
	std::cout << "   Expected : 1"  << std::endl;
	std::cout << "   Current : "<< (ratio1!=ivalue) << std::endl;

	std::cout << "• (ratio1!=nfvalue) : (" << ratio1 << " != "<< nfvalue<< ")"<< std::endl;
	std::cout << "   Expected : 1"  << std::endl;
	std::cout << "   Current : "<< (ratio1!=nfvalue) << std::endl<< std::endl;


	std::cout << "\033[36mOperator > : \033[0m" << std::endl;
	std::cout << "• (ratio1>ratio2) : (" << ratio1 << " > "<< ratio2<< ")"<< std::endl;
	std::cout << "   Expected : 1"  << std::endl;
	std::cout << "   Current : "<< (ratio1>ratio2) << std::endl;

	std::cout << "• (ratio1>ivalue) : (" << ratio1 << " > "<< ivalue<< ")"<< std::endl;
	std::cout << "   Expected : 0"  << std::endl;
	std::cout << "   Current : "<< (ratio1>ivalue) << std::endl;

	std::cout << "• (ratio1>nfvalue) : (" << ratio1 << " > "<< nfvalue<< ")"<< std::endl;
	std::cout << "   Expected : 1"  << std::endl;
	std::cout << "   Current : "<< (ratio1>nfvalue) << std::endl<< std::endl;

	

	std::cout << "\033[36mOperator < : \033[0m" << std::endl;
	std::cout << "• (ratio1<ratio2) : (" << ratio1 << " < "<< ratio2<< ")"<< std::endl;
	std::cout << "   Expected : 0"  << std::endl;
	std::cout << "   Current : "<< (ratio1<ratio2) << std::endl;

	std::cout << "• (ratio1<ivalue) : (" << ratio1 << " < "<< ivalue<< ")"<< std::endl;
	std::cout << "   Expected : 1"  << std::endl;
	std::cout << "   Current : "<< (ratio1<ivalue) << std::endl;

	std::cout << "• (ratio1<nfvalue) : (" << ratio1 << " < "<< nfvalue<< ")"<< std::endl;
	std::cout << "   Expected : 0"  << std::endl;
	std::cout << "   Current : "<< (ratio1<nfvalue) << std::endl<< std::endl;


	std::cout << "\033[94m \033[4mOthers arithmetic operators :\033[0m" <<std::endl;
	std::cout << "We will use the ratio1 from the other part on the following test and news ratio3, PI/3 and PI/6 : " << std::endl;
	ratio::Ratio<int> piSurTrois = ratio::Ratio<int>::pi()/3;
	ratio::Ratio<int> piSurSix = ratio::Ratio<int>::pi()/6;
	ratio::Ratio<int> piSurQuatre = ratio::Ratio<int>::pi()/4;
	ratio::Ratio<int> ratio3(-25,4);
	std::cout << "• ratio1 : " << ratio1 << std::endl;
	std::cout << "• ratio3 : " << ratio3 << std::endl;
	std::cout << "• PI/3 : "<< piSurTrois << std::endl;
	std::cout << "• PI/6 : "<< piSurSix << std::endl;
	std::cout << "• PI/4 : "<< piSurQuatre << std::endl << std::endl;
	


	std::cout << "\033[36mSquare root : \033[0m" << std::endl;
	std::cout << "We want to know what is better between doing a square root on the numerator and the denominator separately ( sqrt() )or doing it the ratio ( sqrt2() )" << std::endl;

    double exactValueSqrt = 0.5;

    double racineRatio = ratio1.sqrt();
    auto sqrtStart1 = std::chrono::steady_clock::now();
    ratio1.sqrt();
    auto sqrtEnd1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = sqrtEnd1-sqrtStart1;    
	std::cout << "• ratio1.sqrt() "<< std::endl;
	std::cout << "    Expected : " << exactValueSqrt  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << racineRatio << std::endl;
	std::cout << "    Time to calculate : "<< elapsed_seconds1.count() << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(racineRatio - exactValueSqrt)  << std::endl << std::endl;

    double racineDouble = ratio1.sqrt2();
    auto sqrtStart2 = std::chrono::steady_clock::now();
    ratio1.sqrt2();
    auto sqrtEnd2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = sqrtEnd2-sqrtStart2;
	std::cout << "• ratio1.sqrt2() "<<std::endl;
	std::cout << "    Expected : " << exactValueSqrt  << std::endl;
	std::cout << "    Current : "<<std::setprecision(30) <<  racineDouble << std::endl;
	std::cout << "    Time to calculate : "<< elapsed_seconds2.count() << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(racineDouble- exactValueSqrt)  << std::endl<< std::endl;

	#if 0
		std::cout << "• ratio3.sqrt() : sqrt on ratio3 (negative ratio) "<<std::endl;
		ratio3.sqrt();
		// try {
		// 	ratio3.sqrt();
		// }catch(const RatioException &e){
		// 	std::cerr << e.what() << std::endl;
		// }
	#endif

	std::cout << "• ratio1.sqrt2() "<<std::endl;
	std::cout << "    Expected : " << exactValueSqrt  << std::endl;
	std::cout << "    Current : "<<std::setprecision(30) <<  racineDouble << std::endl;
	std::cout << "    Time to calculate : "<< elapsed_seconds2.count() << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(racineDouble- exactValueSqrt)  << std::endl<< std::endl;
	
	#if 0
		std::cout << "• ratio3.sqrt2() : sqrt2 on ratio3 (negative ratio) "<<std::endl;
		ratio3.sqrt2();
		// try{
		// 	ratio3.sqrt2();
		// }catch(const RatioException &e){
		// 	std::cerr << e.what() << std::endl;
		// }
	#endif
	
    
	std::cout << "\033[36mCosinus : \033[0m" << std::endl;
	std::cout << "We want to test of the implementation ( cosinus() ) and of one bad approximation ( cosinus2() )" << std::endl;

    double exactValueCos = 0.5;

    double cosRatio = piSurTrois.cosinus();
	std::cout << "• piSurTrois.cosinus() "<< std::endl;
	std::cout << "    Expected : " << exactValueCos  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << cosRatio << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(cosRatio - exactValueCos)  << std::endl << std::endl;

	double cosApprox = std::cos(piSurTrois.getNum())/std::cos(piSurTrois.getDenom());
	std::cout << "• piSurTrois.cosinus2() "<< std::endl;
	std::cout << "    Expected : " << exactValueCos  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << cosApprox << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(cosApprox - exactValueCos)  << std::endl;
	std::cout << "\033[32m> Difference beetween both cos  :"<< std::setprecision(20) << std::abs(cosApprox - cosRatio)<< "\033[0m"  << std::endl << std::endl;



    std::cout << "\033[36mSinus : \033[0m" << std::endl;
	std::cout << "We want to test of the implementation ( sinus() ) and of one bad approximation ( sinus2() )" << std::endl;

    double exactValueSin = 0.5;

    double sinRatio = piSurSix.sinus();
	std::cout << "• piSurSix.sinus() "<< std::endl;
	std::cout << "    Expected : " << exactValueSin  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << sinRatio << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(sinRatio - exactValueSin)  << std::endl << std::endl;

	double sinApprox = std::sin(piSurSix.getNum())/std::sin(piSurSix.getDenom());
	std::cout << "• piSurTrois.sinus2() "<< std::endl;
	std::cout << "    Expected : " << exactValueSin  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << sinApprox << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(sinApprox - exactValueSin)  << std::endl;
	std::cout << "\033[32m=> Difference beetween both sin  :"<< std::setprecision(20) << std::abs(sinApprox - sinRatio)<< "\033[0m"  << std::endl << std::endl;


    std::cout << "\033[36mTangent : \033[0m" << std::endl;
	std::cout << "We want to test of the implementation ( tan() ) and of one bad approximation ( tan2() )" << std::endl;

    double exactValueTan = 1.0;

    double tanRatio = piSurQuatre.tan();
	std::cout << "• piSurQautre.tan() "<< std::endl;
	std::cout << "    Expected : " << exactValueTan  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << tanRatio << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(tanRatio - exactValueTan)  << std::endl << std::endl;

	double tanApprox = std::tan(piSurQuatre.getNum())/std::tan(piSurQuatre.getDenom());
	std::cout << "• piSurQautre.tan2() "<< std::endl;
	std::cout << "    Expected : " << exactValueTan  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << tanApprox << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(tanApprox - exactValueTan)  << std::endl;
	std::cout << "\033[32m=> Difference beetween both sin  :"<< std::setprecision(20) << std::abs(tanApprox - tanRatio)<< "\033[0m"  << std::endl << std::endl;



	std::cout << "\033[36mPower : \033[0m" << std::endl;
	std::cout << "We try to calculate the power with two method : one which is recursive ( pow1()) and the other who apply the pow on an the num and the denom separately with the cmath library ( pow2() )"<< std::endl;

    ratio::Ratio<int> exactValuePow(1,64);

    ratio::Ratio<int> powRecursive = ratio1.pow1(3);
	auto powStart1 = std::chrono::steady_clock::now();
    ratio1.pow1(15);
    auto powEnd1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = powEnd1-powStart1;  
	std::cout << "• ratio1.pow1() "<< std::endl;
	std::cout << "    Expected : " << exactValuePow  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << powRecursive<< std::endl;
	std::cout << "    Time to calculate : "<< elapsed_seconds3.count() << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << (powRecursive - exactValuePow).abs()  << std::endl << std::endl;

    ratio::Ratio<int> powCMath = ratio1.pow2(3);
    auto powStart2 = std::chrono::steady_clock::now();
    ratio1.pow2(15);
    auto powEnd2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds4 = powEnd2-powStart2;
	std::cout << "• ratio1.pow2() "<< std::endl;
	std::cout << "    Expected : " << exactValuePow  << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << powCMath<< std::endl;
	std::cout << "    Time to calculate : "<< elapsed_seconds4.count() << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << (powCMath - exactValuePow).abs()  << std::endl << std::endl; 


   
	std::cout << "\033[36mExponentiel : \033[0m" << std::endl;
	std::cout << "We want to test the implementation of the exponantiel in two ways, one with mathematic rules ( exp()) and one the convertFloatToRatio constructor in our lib and cmath lib ( expLib() )" << std::endl;

    float exactValueExp = 1.28402541669;

    float expRatio = (ratio1.exp()).ConvertRatioToFloat();
	std::cout << "• ratio1.exp() "<< std::endl;
	std::cout << "    Expected : " << exactValueExp << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << expRatio << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(expRatio - exactValueExp)  << std::endl << std::endl;

    float expLibRatio = (ratio1.expLib()).ConvertRatioToFloat();
	std::cout << "• ratio1.expLib() "<< std::endl;
	std::cout << "    Expected : " << exactValueExp << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << expLibRatio << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(expLibRatio - exactValueExp)  << std::endl << std::endl;



	std::cout << "\033[36mLogarithm : \033[0m" << std::endl;
	std::cout << "We want to test the implementation of the logarithm in two ways, one with mathematic rules ( log()) and one the convertFloatToRatio constructor in our lib and cmath lib ( logLib() )" << std::endl;

    float exactValueLog = -1.38629436112;

    float logRatio = (ratio1.log()).ConvertRatioToFloat();
	std::cout << "• ratio1.log() "<< std::endl;
	std::cout << "    Expected : " << exactValueLog << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << logRatio << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(logRatio - exactValueLog)  << std::endl << std::endl;

    float logLibRatio = (ratio1.logLib()).ConvertRatioToFloat();
	std::cout << "• ratio1.logLib() "<< std::endl;
	std::cout << "    Expected : " << exactValueLog << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << logLibRatio << std::endl;
	std::cout << "    Difference with exact value  : "<< std::setprecision(20) << std::abs(logLibRatio - exactValueLog)  << std::endl << std::endl;



	std::cout << "\033[36mInteger part : \033[0m" << std::endl;
	std::cout << "We want the integer part of the ratio" << std::endl;
	
	std::cout << "• ratio3.intPart() : integer part of "<< ratio3.ConvertRatioToFloat()<< std::endl;
	std::cout << "    Expected : " << "-6/1" << std::endl;
	std::cout << "    Current : "<< std::setprecision(30) << ratio3.intPart() << std::endl<<std::endl;


	std::cout << "WITH ALL THESES TESTS YOU ARE READY TO MANIPULATE EASILY THE LIB !  " << std::endl;

	return 0;
}