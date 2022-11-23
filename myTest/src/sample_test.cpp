#include <random>

#include <gtest/gtest.h>

#include "Ratio.hpp"

/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) { 
	Ratio r1;
	ASSERT_EQ(r1.getNum(), 0);
	ASSERT_EQ(r1.getDenom(), 1);
}

TEST (RatioConstructor, copyConstructor) {
	Ratio r1;
	Ratio r2(r1);
	ASSERT_EQ(r1.getNum(), r2.getNum());
	ASSERT_EQ(r1.getDenom(), r2.getDenom());
}


// //faire l'exception avant de l'activer
// TEST (RatioConstructor, paramConstructor){
// 	Ratio r1(2,0);
// 	ASSERT_NE(r1.getDenom(), 0);

// 	//valeur aleatoire bug
// 	// const size_t maxSize = 1000;  // max size of the tested vectors
// 	// std::mt19937 generator(0);
// 	// std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	// std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	// auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// int val = (int)gen();


// }


/////////////////////////////////////////////////////
// arithmetic

TEST (ArithmeticRatio, plusKnowedRatio) {
	Ratio r1(1,2);
	Ratio r2(3,4);
	Ratio result;
	result = r1+r2;


	ASSERT_EQ(result.getNum(),5);
	ASSERT_EQ(result.getDenom(),4);

}

TEST (ArithmeticRatio, plusRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int num1 = gen();
	int num2 = gen();
	int denom1 = gen();
	int denom2 = gen();
	Ratio r1(num1,denom1);
	Ratio r2(num2,denom2);
	Ratio result;
	result = r1+r2;

	ASSERT_EQ(result.getNum(), (num1*denom2+denom1*num2)/std::gcd((num1*denom2+denom1*num2), (denom1*denom2)));
	ASSERT_EQ(result.getDenom(), (denom1*denom2)/std::gcd((num1*denom2+denom1*num2), (denom1*denom2)));
}

TEST (ArithmeticRatio, minusKnowedRatio) {
	Ratio r1(1,2);
	Ratio r2(3,4);
	Ratio result;
	result = r1-r2;


	ASSERT_EQ(result.getNum(),-1);
	ASSERT_EQ(result.getDenom(),4);

}

TEST (ArithmeticRatio, minusRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int num1 = gen();
	int num2 = gen();
	int denom1 = gen();
	int denom2 = gen();
	Ratio r1(num1,denom1);
	Ratio r2(num2,denom2);
	Ratio result;
	result = r1-r2;

	ASSERT_EQ(result.getNum(), (num1*denom2-denom1*num2)/std::gcd((num1*denom2-denom1*num2), (denom1*denom2)));
	ASSERT_EQ(result.getDenom(), (denom1*denom2)/std::gcd((num1*denom2-denom1*num2), (denom1*denom2)));
}



TEST (ArithmeticRatio, multipleKnowedRatio) {
	int num1 = 2;
	int num2 = 3;
	int denom1 = 3;
	int denom2 = 4;

	Ratio r1(num1,denom1);
	Ratio r2(num2,denom2);
	Ratio result;
	result = r1*r2;

	ASSERT_EQ(result.getNum(), 1);
	ASSERT_EQ(result.getDenom(), 2);
}

TEST (ArithmeticRatio, multipleRandomRatio) {
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int num1 = gen();
	int num2 = gen();
	int denom1 = gen();
	int denom2 = gen();

	Ratio r1(num1,denom1);
	Ratio r2(num2,denom2);
	Ratio result;
	result = r1*r2;


	ASSERT_EQ(result.getNum(), (num1*num2)/std::gcd((num1*num2), (denom1*denom2)));
	ASSERT_EQ(result.getDenom(), (denom1*denom2)/std::gcd((num1*num2), (denom1*denom2)));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
