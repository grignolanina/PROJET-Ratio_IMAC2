#include <random>

#include <gtest/gtest.h>
#include <iomanip>


#include "Ratio.hpp"

/*****************************************************************
CONSTRUCTORS
******************************************************************/
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

	int a = gen();
	int b = gen();
	ratio::Ratio<int> r1(a,b);

	ASSERT_EQ(r1.getNum(), a);
	ASSERT_EQ(r1.getDenom(), b);



	// for(int run=0; run <100; run++){
	// 	int a = gen();
	// 	int b = gen();
	// 	ratio::Ratio<int> r1(a,b);

	// 	// ASSERT_EQ(r1.getNum(), a);
	// 	// ASSERT_EQ(r1.getDenom(), b);

	// 	if(b<0){
	// 		ASSERT_EQ(r1.getNum(), -a);
	// 		ASSERT_EQ(r1.getDenom(), -b);
	// 	}else{
	// 		ASSERT_EQ(r1.getNum(), a);
	// 		ASSERT_EQ(r1.getDenom(), b);
	// 	}
		
	// }

	
}


/*****************************************************************
ARITHMETICS CLASSICS OPERATORS
******************************************************************/

TEST (RatioArithmetic, plusKnowedRatio) {
	ratio::Ratio<int> r1(1,2);
	ratio::Ratio<int> r2(3,4);
	ratio::Ratio<int> result;
	result = r1+r2;


	ASSERT_EQ(result.getNum(),5);
	ASSERT_EQ(result.getDenom(),4);

}

TEST (RatioArithmetic, plusRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int c = gen();
	int b = gen();
	int d = gen();
	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1+r2;

	ASSERT_EQ(result.getNum(), (a*d+b*c)/std::gcd((a*d+b*c), (b*d)));
	ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*d+b*c), (b*d)));
}

TEST (RatioArithmetic, plusRandomRatioConvert) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	float a = gen();
	float b = gen();

	ratio::Ratio<int> r1(a);
	ratio::Ratio<int> r2(b);


	ratio::Ratio<int> result;
	result = r1+r2;

	ratio::Ratio<int> r3(a+b);

	float epsilon = 0.0001; // notre marge d'erreur

	float absolute = std::abs((result.ConvertRatioToFloat() - r3.ConvertRatioToFloat()));

	ASSERT_LT(absolute, epsilon);
}

TEST (RatioArithmetic, minusKnowedRatio) {
	ratio::Ratio<int> r1(1,2);
	ratio::Ratio<int> r2(3,4);
	ratio::Ratio<int> result;
	result = r1-r2;


	ASSERT_EQ(result.getNum(),-1);
	ASSERT_EQ(result.getDenom(),4);
}

TEST (RatioArithmetic, minusRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int c = gen();
	int b = gen();
	int d = gen();
	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1-r2;

	ASSERT_EQ(result.getNum(), (a*d-b*c)/std::gcd((a*d-b*c), (b*d)));
	ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*d-b*c), (b*d)));
}

TEST (RatioArithmetic, minusRandomRatioConvert) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	float a = gen();
	float b = gen();

	ratio::Ratio<int> r1(a);
	ratio::Ratio<int> r2(b);


	ratio::Ratio<int> result;
	result = r1-r2;

	ratio::Ratio<int> r3(a-b);

	float epsilon = 0.0001; // notre marge d'erreur

	float absolute = std::abs((result.ConvertRatioToFloat() - r3.ConvertRatioToFloat()));
	
	ASSERT_LT(absolute, epsilon);

}



TEST (RatioArithmetic, multipleKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
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

	int a = gen();
	int c = gen();
	int b = gen();
	int d = gen();

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1*r2;


	ASSERT_EQ(result.getNum(), (a*c)/std::gcd((a*c), (b*d)));
	ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*c), (b*d)));
}

TEST (RatioArithmetic, multipleByInverseRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int num = gen();
	int denom = gen();
	ratio::Ratio<int> r1(num,denom);
	ratio::Ratio<int> inverser1;
	inverser1=r1.inverse();

	ASSERT_EQ(inverser1.getNum(), r1.getDenom());
	ASSERT_EQ(inverser1.getDenom(), r1.getNum());
}

TEST (RatioArithmetic, multiplyByInverseEqualToOne){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int b = gen();

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> resultMultipleInverse;
	resultMultipleInverse = r1 * r1.inverse();

	ASSERT_EQ(resultMultipleInverse.getNum(), 1);
	ASSERT_EQ(resultMultipleInverse.getDenom(), 1);
}

TEST (RatioArithmetic, diviseKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1/r2;

	ASSERT_EQ(result.getNum(), 8);
	ASSERT_EQ(result.getDenom(), 9);
}

TEST (RatioArithmetic, diviseRandomRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int c = gen();
	int b = gen();
	int d = gen();

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> result;
	result = r1/r2;


	ASSERT_EQ(result.getNum(), (a*d)/std::gcd((a*d), (b*c)));
	ASSERT_EQ(result.getDenom(), (b*c)/std::gcd((a*d), (b*c)));
}

TEST (RatioArithmetic, diviseEqualToMultipleInverseRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int a = gen();
	int c = gen();
	int b = gen();
	int d = gen();

	ratio::Ratio<int> r1(a,b);
	ratio::Ratio<int> r2(c,d);
	ratio::Ratio<int> resultDivise;
	resultDivise = r1/r2;
	ratio::Ratio<int> resultMultipleInverse;
	resultMultipleInverse = r1 * r2.inverse();


	ASSERT_EQ(resultDivise.getNum(), resultMultipleInverse.getNum());
	ASSERT_EQ(resultDivise.getDenom(), resultMultipleInverse.getDenom());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
