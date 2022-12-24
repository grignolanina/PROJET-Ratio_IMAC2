#include <random>

#include <iomanip>
#include <numeric>
#include <cmath>
#include "Ratio.hpp"
#include "include/expLn.hpp"

TEST (RatioArithmetic, expKnowedRatio) {
	Ratio<int> r1(M_PI,1);
    
	Ratio<int> result;
    result = r1.exp();

	ASSERT_EQ(result.getNum(),-1);
	ASSERT_EQ(result.getDenom(),1);
}

TEST (RatioArithmetic, expRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run <100; run++){
        int a = gen();
        int b = gen();

        Ratio<int> r1(a,b);
        Ratio<int> result;
        result = r1.exp();
    

	    ASSERT_EQ(result.getNum(), Ratio(std::exp((float)a/b)).getNum());
	    ASSERT_EQ(result.getDenom(), Ratio(std::exp((float)a/b)).getDenom());
    }
}

TEST (RatioArithmetic, LogOfExpRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run <100; run++){
        int a = gen();
        int b = gen();

        Ratio<int> r1(a,b);
        Ratio<int> result;
        result = std::log(r1.exp())
    

	    ASSERT_EQ(result.getNum(), a);
	    ASSERT_EQ(result.getDenom(), b);
    }
}

TEST (RatioArithmetic, logKnowedRatio) {
	Ratio<int> r1(1,1);
    
	Ratio<int> result;
    result = r1.log();

	ASSERT_EQ(result.getNum(),0);
	ASSERT_EQ(result.getDenom(),1);
}

TEST (RatioArithmetic, logRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run <100; run++){
        int a = gen();
        int b = gen();

        Ratio<int> r1(a,b);
        Ratio<int> result;
        result = r1.log();
    

	    ASSERT_EQ(result.getNum(), Ratio(std::log((float)a/b)).getNum());
	    ASSERT_EQ(result.getDenom(), Ratio(std::log((float)a/b)).getDenom());
    }
}

TEST (RatioArithmetic, ExpOfLogRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run <100; run++){
        int a = gen();
        int b = gen();

        Ratio<int> r1(a,b);
        Ratio<int> result;
        result = std::exp(r1.log())
    

	    ASSERT_EQ(result.getNum(), a);
	    ASSERT_EQ(result.getDenom(), b);
    }
}