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

// TEST (RatioArithmetic, powRandomRatio) {
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

//     for(int run=0; run <100; run++){
//         int a = gen();
//         int b = gen();
//         int k = gen();

//         ratio::Ratio<int> r1(a,b);
//         ratio::Ratio<int> result;
//         result = r1.pow1(k);
    

// 	    ASSERT_EQ(result.getNum(), std::pow(a,k)/std::gcd(std::pow(a,k), std::pow(b,k)));
// 	    ASSERT_EQ(result.getDenom(), std::pow(b,k)/std::gcd(std::pow(a,k), std::pow(b,k)));
//     }
// }