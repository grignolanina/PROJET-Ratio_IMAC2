#include <random>

#include <gtest/gtest.h>
#include <iomanip>
#include <numeric>


#include "Ratio.hpp"

/*****************************************************************
ARITHMETICS CLASSICS OPERATORS
******************************************************************/

TEST (RatioArithmetic, plusKnowedRatio) {
	Ratio<int> r1(1,2);
	Ratio<int> r2(3,4);
	Ratio<int> result;
	result = r1+r2;


	ASSERT_EQ(result.getNum(),5);
	ASSERT_EQ(result.getDenom(),4);

}

TEST (RatioArithmetic, plusRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int c = gen();
	int b = gen();
	int d = gen();
	Ratio<int> r1(a,b);
	Ratio<int> r2(c,d);
	Ratio<int> result;
	result = r1+r2;

	ASSERT_EQ(result.getNum(), (a*d+b*c)/std::gcd((a*d+b*c), (b*d)));
	ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*d+b*c), (b*d)));
}

TEST (RatioArithmetic, plusRandomRatioConvert) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	float a = gen();
	float b = gen();

	Ratio<int> r1(a);
	Ratio<int> r2(b);


	Ratio<int> result;
	result = r1+r2;

	Ratio<int> r3(a+b);

	float epsilon = 0.0001; // notre marge d'erreur

	float absolute = std::abs((result.ConvertRatioToFloat() - r3.ConvertRatioToFloat()));

	ASSERT_LT(absolute, epsilon);
}