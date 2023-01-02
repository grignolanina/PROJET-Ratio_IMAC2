#pragma once

#include <random>

#include <iomanip>
#include <numeric>
#include "Ratio.hpp"

TEST (RatioArithmetic, minusEqualKnowedRatio) {
	ratio::Ratio<int> r1(1,2);
	ratio::Ratio<int> r2(3,4);
	ratio::Ratio<int> result;
	result = r1-=r2;


	ASSERT_EQ(result.getNum(),-1);
	ASSERT_EQ(result.getDenom(),4);
}

TEST (RatioArithmetic, minusEqualRandomRatio) {
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
		result = r1-=r2;

		ASSERT_EQ(std::abs(result.getNum()), std::abs((a*d-b*c)/std::gcd((a*d-b*c), (b*d))));
		ASSERT_EQ(std::abs(result.getDenom()), std::abs((b*d)/std::gcd((a*d-b*c), (b*d))));
	}
}

TEST (RatioArithmetic, minusEqualRandomRatioConvert) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		float a = gen();
		float b = gen();

		ratio::Ratio<int> r1(a);
		ratio::Ratio<int> r2(b);


		ratio::Ratio<int> result;
		result = r1-=r2;

		ratio::Ratio<int> r3(a-b);

		float epsilon = 0.001; // notre marge d'erreur

		float absolute = std::abs((result.ConvertRatioToFloat() - r3.ConvertRatioToFloat()));
		
		ASSERT_LT(absolute, epsilon);
	}

}