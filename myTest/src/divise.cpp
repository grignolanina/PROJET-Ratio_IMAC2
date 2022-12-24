#include <random>

#include <iomanip>
#include <numeric>
#include "Ratio.hpp"
#include "include/divise.hpp"

TEST (RatioArithmetic, diviseKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	Ratio<int> r1(a,b);
	Ratio<int> r2(c,d);
	Ratio<int> result;
	result = r1/r2;

	ASSERT_EQ(result.getNum(), 8);
	ASSERT_EQ(result.getDenom(), 9);
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

		Ratio<int> r1(a,b);
		Ratio<int> r2(c,d);
		Ratio<int> result;
		result = r1/r2;

		ASSERT_EQ(result.getNum(), (a*d)/std::gcd((a*d), (b*c)));
		ASSERT_EQ(result.getDenom(), (b*c)/std::gcd((a*d), (b*c)));
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

		Ratio<int> r1(a,b);
		Ratio<int> r2(c,d);
		Ratio<int> resultDivise;
		resultDivise = r1/r2;
		Ratio<int> resultMultipleInverse;
		resultMultipleInverse = r1 * r2.inverse();
	

		ASSERT_EQ(resultDivise.getNum(), resultMultipleInverse.getNum());
		ASSERT_EQ(resultDivise.getDenom(), resultMultipleInverse.getDenom());
	}
}

