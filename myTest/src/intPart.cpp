#include <random>

#include <iomanip>
#include <numeric>
#include <cmath>
#include "Ratio.hpp"
#include "include/cosSinTan.hpp"

TEST (RatioArithmetic, intPartKnowedRatio) {
	Ratio<int> r1(5,2);
	Ratio<int> result;
    result = r1.intPart();

	ASSERT_EQ(result.getNum(),2);
	ASSERT_EQ(result.getDenom(),1);
}

TEST (RatioArithmetic, intPartRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int b = gen();

	Ratio<int> r1(a,b);
	Ratio<int> result;
	result = r1.intPart();

	ASSERT_EQ(result.getNum(), (int)a/b);
	ASSERT_EQ(result.getDenom(), 1);
}