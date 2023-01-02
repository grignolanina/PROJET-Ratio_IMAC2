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

	float expected = 0.5;

	float epsilon = 0.00001; // notre marge d'erreur

	float absolute = std::abs(result.ConvertRatioToFloat()-expected);
	
	ASSERT_LT(absolute, epsilon);
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

		float epsilon = 0.000001;; // notre marge d'erreur

		float absolute = std::abs((result.ConvertRatioToFloat() - theory.ConvertRatioToFloat()));
		
		ASSERT_LT(absolute, epsilon);
	}
}

TEST (RatioArithmetic, sinKnowedRatio) {
	ratio::Ratio<int> r1 = ratio::Ratio<int>::pi()/6;
	ratio::Ratio<int> result;
    result = r1.sinus();

	float expected = 0.5;

	float epsilon = 0.00001; // notre marge d'erreur

	float absolute = std::abs(result.ConvertRatioToFloat()-expected);
	
	ASSERT_LT(absolute, epsilon);
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

		float epsilon = 0.000001; // notre marge d'erreur

		float absolute = std::abs((result.ConvertRatioToFloat() - theory.ConvertRatioToFloat()));
		
		ASSERT_LT(absolute, epsilon);
	}
	
}

TEST (RatioArithmetic, tanKnowedRatio) {
	ratio::Ratio<int> r1 = ratio::Ratio<int>::pi()/4;
	ratio::Ratio<int> result;
    result = r1.tan();

	float expected = 1.0;

	float epsilon = 0.01; // notre marge d'erreur

	float absolute = std::abs(result.ConvertRatioToFloat()-expected);
	
	ASSERT_LT(absolute, epsilon);
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

		float epsilon = 0.001; // notre marge d'erreur

		float absolute = std::abs((result.ConvertRatioToFloat() - theory.ConvertRatioToFloat()));
		
		ASSERT_LT(absolute, epsilon);
	}
}