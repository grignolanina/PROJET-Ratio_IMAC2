#include <random>

#include <iomanip>
#include <numeric>
#include "Ratio.hpp"
#include "include/multiply.hpp"


TEST (RatioArithmetic, multipleKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	Ratio<int> r1(a,b);
	Ratio<int> r2(c,d);
	Ratio<int> result;
	result = r1*r2;

	ASSERT_EQ(result.getNum(), 1);
	ASSERT_EQ(result.getDenom(), 2);
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

		Ratio<int> r1(a,b);
		Ratio<int> r2(c,d);
		Ratio<int> result;
		result = r1*r2;


		ASSERT_EQ(result.getNum(), (a*c)/std::gcd((a*c), (b*d)));
		ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*c), (b*d)));
	}
}

TEST (RatioArithmetic, multipleByInverseRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int num = gen();
		int denom = gen();
		Ratio<int> r1(num,denom);
		Ratio<int> inverser1;
		inverser1=r1.inverse();

		ASSERT_EQ(inverser1.getNum(), r1.getDenom());
		ASSERT_EQ(inverser1.getDenom(), r1.getNum());
	}
}

TEST (RatioArithmetic, multiplyByInverseEqualToOne){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int b = gen();

		Ratio<int> r1(a,b);
		Ratio<int> resultMultipleInverse;
		resultMultipleInverse = r1 * r1.inverse();

		ASSERT_EQ(resultMultipleInverse.getNum(), 1);
		ASSERT_EQ(resultMultipleInverse.getDenom(), 1);
	}
}
