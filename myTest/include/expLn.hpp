#pragma once

#include <random>

#include <iomanip>
#include <numeric>
#include <cmath>
#include <math.h>
#include "Ratio.hpp"

TEST (RatioArithmetic, expKnowedRatio) {
	ratio::Ratio<int> r1= ratio::Ratio<int>::zero();
    
	ratio::Ratio<int> result;
    result = r1.exp();

	float expected = 1.0;
	float epsilon = 0.000001; // notre marge d'erreur

	float absolute = std::abs(result.ConvertRatioToFloat()-expected);
	
	ASSERT_LT(absolute, epsilon);
}

TEST (RatioArithmetic, expRandomRatio) {
	const size_t maxSize = 30;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run <50; run++){
        int a = gen();
        int b = gen();

        ratio::Ratio<int> r1(a,b);
        ratio::Ratio<int> result;
        result = r1.exp();
		

		float expected =std::exp((float)a/b);
		float epsilon = 0.001;; // notre marge d'erreur
	    float absolute = std::abs(result.ConvertRatioToFloat() - expected);
		
		ASSERT_LT(absolute, epsilon);
    }
}


TEST (RatioArithmetic, logKnowedRatio) {
	ratio::Ratio<int> r1(1,1);
    
	ratio::Ratio<int> result;
    result = r1.log();

	float expected = 0.0;
	float epsilon = 0.000001; // notre marge d'erreur
	float absolute = std::abs(result.ConvertRatioToFloat()-expected);
	
	ASSERT_LT(absolute, epsilon);
}

TEST (RatioArithmetic, logRandomRatio) {
	const size_t maxSize = 100;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(1,maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run <100; run++){
        int a = gen();
        int b = gen();

        ratio::Ratio<int> r1(a,b);
        ratio::Ratio<int> result;
        result = r1.log();

		float expected = std::log((float)a/b);
		float absolute = std::abs(expected - result.ConvertRatioToFloat());

		ASSERT_LT(absolute, 0.01);

    }
}

