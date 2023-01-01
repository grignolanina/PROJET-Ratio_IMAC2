#pragma once

#include <random>

#include <iomanip>
#include <numeric>
#include "Ratio.hpp"


TEST (RatioArithmetic, multipleEqualKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1*=r2;

	ASSERT_EQ(result.getNum(), 1);
	ASSERT_EQ(result.getDenom(), 2);
}

TEST (RatioArithmetic, multipleEqualRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int c = gen();
		int b = gen();
		int d = gen();

		ratio::Ratio<int> r1(a,b);
		ratio::Ratio<int> r2(c,d);
		ratio::Ratio<int> result;
		result = r1*=r2;


		ASSERT_EQ(result.getNum(), (a*c)/std::gcd((a*c), (b*d)));
		ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*c), (b*d)));
	}
}

// TEST (RatioArithmetic, multipleEqualRandomRatioConvert){
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	for(int run=0; run <100; run++){
// 		int a = gen();
// 		int c = gen();
	
// 		ratio::Ratio<int> r1(a);
// 		ratio::Ratio<int> r2(b);
// 		ratio::Ratio<int> result;
// 		result = r1*=r2;

// 		ratio::Ratio<int> r3(a*=b);

// 		float epsilon = 0.001; // notre marge d'erreur

// 		float absolute = std::abs((result.ConvertRatioToFloat() - r3.ConvertRatioToFloat()));

// 		ASSERT_LT(absolute, epsilon);
// 	}
// }
