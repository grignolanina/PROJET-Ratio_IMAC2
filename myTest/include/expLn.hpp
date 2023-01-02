#pragma once

#include <random>

#include <iomanip>
#include <numeric>
#include <cmath>
#include <math.h>
#include "Ratio.hpp"

TEST (RatioArithmetic, expKnowedRatio) {
	ratio::Ratio<int> r1= ratio::Ratio<int>::zero();
    
	ratio::Ratio<int> result;
    result = r1.exp();

	float expected = 1.0;
	float epsilon = 0.000001; // notre marge d'erreur

	float absolute = std::abs(result.ConvertRatioToFloat()-expected);
	
	ASSERT_LT(absolute, epsilon);
}

// TEST (RatioArithmetic, expRandomRatio) {
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

//     for(int run=0; run <100; run++){
//         int a = gen();
//         int b = gen();

//         ratio::Ratio<int> r1(a,b);
//         ratio::Ratio<int> result;
//         result = r1.exp();

// 		ratio::Ratio<int> expected(std::exp((float)a/b));
    
// 		float epsilon = 0.001;; // notre marge d'erreur

// 	    float absolute = std::abs((result.ConvertRatioToFloat() - expected.ConvertRatioToFloat()));
		
// 		ASSERT_LT(absolute, epsilon);
//     }
// }

// TEST (RatioArithmetic, LogOfExpRandomRatio) {
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

//     // for(int run=0; run <100; run++){
//         int a = gen();
//         int b = gen();

//         ratio::Ratio<int> r1(a,b);
//         ratio::Ratio<int> result;
//         result = (r1.exp()).log();

// 		float theory = (float)a/b;

		
// 		std::cout << "mon result est " <<  result.ConvertRatioToFloat() << "est mon theory est " << theory << std::endl;

// 		float absolute = std::abs((result.ConvertRatioToFloat() - theory));
// 		float epsilon = 0.0001;; // notre marge d'erreur
// 		ASSERT_LT(absolute, epsilon);
//     // }
// }

TEST (RatioArithmetic, logKnowedRatio) {
	ratio::Ratio<int> r1(1,1);
    
	ratio::Ratio<int> result;
    result = r1.log();

	float expected = 0.0;
	float epsilon = 0.000001; // notre marge d'erreur

	float absolute = std::abs(result.ConvertRatioToFloat()-expected);
	
	ASSERT_LT(absolute, epsilon);
}

// TEST (RatioArithmetic, logRandomRatio) {
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

//     for(int run=0; run <100; run++){
//         int a = gen();
//         int b = gen();

//         ratio::Ratio<int> r1(a,b);
//         ratio::Ratio<int> result;
//         result = r1.log();

// 		ratio::Ratio<int> expected(std::log((float)a/b));
    

// 	    ASSERT_EQ(result.getNum(), expected.getNum());
// 	    ASSERT_EQ(result.getDenom(), expected.getDenom());
//     }
// }

// TEST (RatioArithmetic, ExpOfLogRandomRatio) {
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

//     for(int run=0; run <100; run++){
//         int a = gen();
//         int b = gen();

//         ratio::Ratio<int> r1(a,b);
//         ratio::Ratio<int> result;
//         result = (r1.log()).exp();
    

// 	    ASSERT_EQ(result.getNum(), a);
// 	    ASSERT_EQ(result.getDenom(), b);
//     }
// }