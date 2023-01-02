#pragma once

#include <random>

#include <iomanip>
#include <numeric>
#include "Ratio.hpp"


TEST (RatioArithmetic, multipleKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1*r2;

	ASSERT_EQ(result.getNum(), 1);
	ASSERT_EQ(result.getDenom(), 2);
}

TEST (RatioArithmetic, multipleByZero) {
	ratio::Ratio<int> r1(1,2);
	ratio::Ratio<int> result;
	result = r1*ratio::Ratio<int>::zero();

	ASSERT_EQ(result.getNum(), 0);
	ASSERT_EQ(result.getDenom(), 1);
}

TEST (RatioArithmetic, multiplePluralKnowedRatio) {
	ratio::Ratio<int> r1(1,2);
	ratio::Ratio<int> r2(3,4);
	ratio::Ratio<int> r3(1,5);
	ratio::Ratio<int> result;
	result = r1*r2*r3;


	ASSERT_EQ(result.getNum(),3);
	ASSERT_EQ(result.getDenom(),40);
} 

TEST (RatioArithmetic, multipleRandomRatio) {
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
		result = r1*r2;


		ASSERT_EQ(std::abs(result.getNum()), std::abs((a*c)/std::gcd((a*c), (b*d))));
		ASSERT_EQ(std::abs(result.getDenom()), std::abs((b*d)/std::gcd((a*c), (b*d))));
	}
}

TEST (RatioArithmetic, multipleRandomRatioConvert){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int b = gen();
	
		ratio::Ratio<int> r1(a);
		ratio::Ratio<int> r2(b);
		ratio::Ratio<int> result;
		result = r1*r2;

		ratio::Ratio<int> r3(a*b);

		float epsilon = 0.001; // notre marge d'erreur

		float absolute = std::abs((result.ConvertRatioToFloat() - r3.ConvertRatioToFloat()));

		ASSERT_LT(absolute, epsilon);
	}
}

TEST (RatioArithmetic, multipleByInverseRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(1);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int num = gen();
		int denom = gen();
		ratio::Ratio<int> r1(num,denom);
		ratio::Ratio<int> inverser1;
		inverser1=r1.inverse();

		ASSERT_EQ(std::abs(inverser1.getNum()), std::abs(r1.getDenom()));
		ASSERT_EQ(std::abs(inverser1.getDenom()), std::abs(r1.getNum()));
	}
}

TEST (RatioArithmetic, multiplyByInverseEqualToOne){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(1);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int b = gen();

		ratio::Ratio<int> r1(a,b);
		ratio::Ratio<int> resultMultipleInverse;
		resultMultipleInverse = r1 * r1.inverse();

		ASSERT_EQ(resultMultipleInverse.getNum(), 1);
		ASSERT_EQ(resultMultipleInverse.getDenom(), 1);
	}
}

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


		ASSERT_EQ(std::abs(result.getNum()), std::abs((a*c)/std::gcd((a*c), (b*d))));
		ASSERT_EQ(std::abs(result.getDenom()), std::abs((b*d)/std::gcd((a*c), (b*d))));
	}
}

TEST (RatioArithmetic, multipleEqualRandomRatioConvert){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int b = gen();
	
		ratio::Ratio<int> r1(a);
		ratio::Ratio<int> r2(b);
		ratio::Ratio<int> result;
		result = r1*=r2;

		ratio::Ratio<int> r3(a*=b);

		float epsilon = 0.001; // notre marge d'erreur

		float absolute = std::abs((result.ConvertRatioToFloat() - r3.ConvertRatioToFloat()));

		ASSERT_LT(absolute, epsilon);
	}
}