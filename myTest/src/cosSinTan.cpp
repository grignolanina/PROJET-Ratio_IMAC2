#include <random>

#include <iomanip>
#include <numeric>
#include <cmath>
#include "Ratio.hpp"
#include "include/cosSinTan.hpp"

TEST (RatioArithmetic, cosKnowedRatio) {
	Ratio<int> r1(M_PI,3);
	Ratio<int> result;
    result = r1.cos();

	ASSERT_EQ(result.getNum(),1);
	ASSERT_EQ(result.getDenom(),2);
}

TEST (RatioArithmetic, cosRandomRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int b = gen();

	Ratio<int> r1(a,b);
	Ratio<int> result;
	result = r1.cos();
    theory = Ratio(std::cos((float)a/b));
    


	ASSERT_EQ(result.getNum(),theory.getNum());
	ASSERT_EQ(result.getDenom(), theory.getDenom());
}

TEST (RatioArithmetic, sinKnowedRatio) {
	Ratio<int> r1(M_PI,6);
	Ratio<int> result;
    result = r1.sin();

	ASSERT_EQ(result.getNum(),1);
	ASSERT_EQ(result.getDenom(),2);
}

TEST (RatioArithmetic, sinRandomRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int b = gen();

	Ratio<int> r1(a,b);
	Ratio<int> result;
	result = r1.sin();
    theory = Ratio(std::sin((float)a/b));
    


	ASSERT_EQ(result.getNum(),theory.getNum());
	ASSERT_EQ(result.getDenom(), theory.getDenom());
}

TEST (RatioArithmetic, tanKnowedRatio) {
	Ratio<int> r1(M_PI,4);
	Ratio<int> result;
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

	int a = gen();
	int b = gen();

	Ratio<int> r1(a,b);
	Ratio<int> result;
	result = r1.tan();
    theory = Ratio(std::tan((float)a/b));
    


	ASSERT_EQ(result.getNum(),theory.getNum());
	ASSERT_EQ(result.getDenom(), theory.getDenom());
}