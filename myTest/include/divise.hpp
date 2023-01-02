#pragma once
#include <random>

#include <iomanip>
#include <numeric>
#include "Ratio.hpp"

TEST (RatioArithmetic, diviseKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1/r2;

	ASSERT_EQ(result.getNum(), 8);
	ASSERT_EQ(result.getDenom(), 9);
}

TEST (RatioArithmetic, diviseByZero) {
	ratio::Ratio<int> r1(1,2);
	ratio::Ratio<int> result;
	result = r1/ratio::Ratio<int>::zero();

	ASSERT_EQ(result.getNum(), 1);
	ASSERT_EQ(result.getDenom(), 0);
}

TEST (RatioArithmetic, divisePluralKnowedRatio) {
	ratio::Ratio<int> r1(1,2);
	ratio::Ratio<int> r2(3,4);
	ratio::Ratio<int> r3(1,5);
	ratio::Ratio<int> result;
	result = r1/r2/r3;


	ASSERT_EQ(result.getNum(),10);
	ASSERT_EQ(result.getDenom(),3);
} 

TEST (RatioArithmetic, diviseRandomRatio){
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
		result = r1/r2;

		ASSERT_EQ(std::abs(result.getNum()), std::abs((a*d)/std::gcd((a*d), (b*c))));
		ASSERT_EQ(std::abs(result.getDenom()), std::abs((b*c)/std::gcd((a*d), (b*c))));
	}
}


TEST (RatioArithmetic, diviseEqualToMultipleInverseRatio){
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
		ratio::Ratio<int> resultDivise;
		resultDivise = r1/r2;
		ratio::Ratio<int> resultMultipleInverse;
		resultMultipleInverse = r1 * r2.inverse();
	

		ASSERT_EQ(resultDivise.getNum(), resultMultipleInverse.getNum());
		ASSERT_EQ(resultDivise.getDenom(), resultMultipleInverse.getDenom());
	}
}


TEST (RatioArithmetic, diviseEqualKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1/=r2;

	ASSERT_EQ(result.getNum(), 8);
	ASSERT_EQ(result.getDenom(), 9);
}

TEST (RatioArithmetic, diviseEqualRandomRatio){
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
		result = r1/=r2;

		ASSERT_EQ(std::abs(result.getNum()), std::abs((a*d)/std::gcd((a*d), (b*c))));
		ASSERT_EQ(std::abs(result.getDenom()), std::abs((b*c)/std::gcd((a*d), (b*c))));
	}
}