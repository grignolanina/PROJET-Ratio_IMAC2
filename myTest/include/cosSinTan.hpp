#pragma once

#include <random>

#include <iomanip>
#include <numeric>
#include <cmath>
#include "Ratio.hpp"

TEST (RatioArithmetic, cosKnowedRatio) {
	ratio::Ratio<int> r1 = ratio::Ratio<int>::pi()/3;
	ratio::Ratio<int> result;
    result = r1.cosinus();

	ASSERT_EQ(result.getNum(),1);
	ASSERT_EQ(result.getDenom(),2);
}

TEST (RatioArithmetic, cosRandomRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int b = gen();

		ratio::Ratio<int> r1(a,b);
		ratio::Ratio<int> result;

		result = r1.cosinus();
		ratio::Ratio<int> theory(std::cos((float)a/b));
	
		ASSERT_EQ(result.getNum(),theory.getNum());
		ASSERT_EQ(result.getDenom(), theory.getDenom());
	}
}

TEST (RatioArithmetic, sinKnowedRatio) {
	ratio::Ratio<int> r1 = ratio::Ratio<int>::pi()/6;
	ratio::Ratio<int> result;
    result = r1.sinus();

	ASSERT_EQ(result.getNum(),1);
	ASSERT_EQ(result.getDenom(),2);
}

TEST (RatioArithmetic, sinRandomRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){

		int a = gen();
		int b = gen();

		ratio::Ratio<int> r1(a,b);
		ratio::Ratio<int> result;
		result = r1.sinus();
		ratio::Ratio<int> theory(std::sin((float)a/b));
	
		ASSERT_EQ(result.getNum(),theory.getNum());
		ASSERT_EQ(result.getDenom(), theory.getDenom());
	}
	
}

TEST (RatioArithmetic, tanKnowedRatio) {
	ratio::Ratio<int> r1 = ratio::Ratio<int>::pi()/4;
	ratio::Ratio<int> result;
    result = r1.tan();

	ASSERT_EQ(result.getNum(), 1);
	ASSERT_EQ(result.getDenom(),1);
}

TEST (RatioArithmetic, tanRandomRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int b = gen();

		ratio::Ratio<int> r1(a,b);
		ratio::Ratio<int> result;
		result = r1.tan();
		ratio::Ratio<int> theory(std::tan((float)a/b));
		


		ASSERT_EQ(result.getNum(),theory.getNum());
		ASSERT_EQ(result.getDenom(), theory.getDenom());
	}
}