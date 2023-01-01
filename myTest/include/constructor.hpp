#pragma once

#include <random>

#include <gtest/gtest.h>
#include <iomanip>
#include <numeric>
#include "Ratio.hpp"

TEST (RatioConstructor, defaultConstructor) { 
	ratio::Ratio<int> r1;
	ASSERT_EQ(r1.getNum(), 0);
	ASSERT_EQ(r1.getDenom(), 1);
}

TEST (RatioConstructor, copyConstructor) {
	ratio::Ratio<int> r1;
	ratio::Ratio<int> r2(r1);
	ASSERT_EQ(r1.getNum(), r2.getNum());
	ASSERT_EQ(r1.getDenom(), r2.getDenom());
}


TEST (RatioConstructor, paramConstructor){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	for(int run=0; run <100; run++){
		int a = gen();
		int b = gen();
		ratio::Ratio<int> r1(a,b);

		ASSERT_EQ(std::abs(r1.getNum()), (std::abs((a)/std::gcd(a,b))));
		ASSERT_EQ(r1.getDenom(), (std::abs((b)/std::gcd(a,b))));
	}

	
}