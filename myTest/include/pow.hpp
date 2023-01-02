#pragma once

#include <random>

#include <iomanip>
#include <numeric>
#include <cmath>
#include "Ratio.hpp"

//ici on teste que la première fonction car l'autre provient de la STL
TEST (RatioArithmetic, powKnowedRatio) {
	ratio::Ratio<int> r1(1,2);
    int k = 3;
	ratio::Ratio<int> result;
    result = r1.pow1(k);

	ASSERT_EQ(result.getNum(),1);
	ASSERT_EQ(result.getDenom(),8);
}

TEST (RatioArithmetic, powRandomRatio) {
	const size_t maxSize = 100;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformIntDistributionK(1,15);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	std::uniform_real_distribution<double> uniformDistributionValueK(-int(10),10);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
	auto genK = [&uniformDistributionValueK, &generator](){ return uniformDistributionValueK(generator);};

    for(int run=0; run <100; run++){
        int a = gen();
        int b = gen();
        int k = genK();

        ratio::Ratio<int> r1(a,b);
        ratio::Ratio<int> result;
        result = r1.pow1(k);
		std::cout << "result : " << result.ConvertRatioToFloat() << std::endl;

		float expected = std::pow((float)a/b, k);
		std::cout<< "Expected : " << expected  << std::endl;
	
		float absolute = std::abs(result.ConvertRatioToFloat()-expected);

		float epsilon = 0.01;

		ASSERT_LT(absolute, epsilon);

    }
}