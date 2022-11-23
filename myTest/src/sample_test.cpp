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
//exception message ?
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



// TEST (RatioConstructor, paramConstructorExceptionMessage) {

// 	const std::string expectedException = "Ratio constructor is impossible with a denominator equal to zero";
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	int num=gen();
// 	int denom=gen();

// 	if(denom!=0)
// 		continue:

// 	try{
// 		Ratio r1(num, denom);
// 	}
// 	catch(const std::exception &e){
// 		ASSERT_TRUE( std::string(e.what()).find(expectedException) == 0);

// 	}
// }




/////////////////////////////////////////////////////
// arithmetic

TEST (RatioArithmetic, plusKnowedRatio) {
	Ratio r1(1,2);
	Ratio r2(3,4);
	Ratio result;
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
	Ratio r1(a,b);
	Ratio r2(c,d);
	Ratio result;
	result = r1+r2;

	ASSERT_EQ(result.getNum(), (a*d+b*c)/std::gcd((a*d+b*c), (b*d)));
	ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*d+b*c), (b*d)));
}

TEST (RatioArithmetic, minusKnowedRatio) {
	Ratio r1(1,2);
	Ratio r2(3,4);
	Ratio result;
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
	Ratio r1(a,b);
	Ratio r2(c,d);
	Ratio result;
	result = r1-r2;

	ASSERT_EQ(result.getNum(), (a*d-b*c)/std::gcd((a*d-b*c), (b*d)));
	ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*d-b*c), (b*d)));
}



TEST (RatioArithmetic, multipleKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	Ratio r1(a,b);
	Ratio r2(c,d);
	Ratio result;
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

	Ratio r1(a,b);
	Ratio r2(c,d);
	Ratio result;
	result = r1*r2;


	ASSERT_EQ(result.getNum(), (a*c)/std::gcd((a*c), (b*d)));
	ASSERT_EQ(result.getDenom(), (b*d)/std::gcd((a*c), (b*d)));
}

TEST (RatioArithmetic, inverseRatio){
	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	int num = gen();
	int denom = gen();
	Ratio r1(num,denom);
	Ratio inverser1;
	inverser1=r1.inverse();

	ASSERT_EQ(inverser1.getNum(), r1.getDenom());
	ASSERT_EQ(inverser1.getDenom(), r1.getNum());
}

TEST (RatioArithmetic, diviseKnowedRatio) {
	int a = 2;
	int c = 3;
	int b = 3;
	int d = 4;

	Ratio r1(a,b);
	Ratio r2(c,d);
	Ratio result;
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

	Ratio r1(a,b);
	Ratio r2(c,d);
	Ratio result;
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

	Ratio r1(a,b);
	Ratio r2(c,d);
	Ratio resultDivise;
	resultDivise = r1/r2;
	Ratio resultMultipleInverse;
	resultMultipleInverse = r1 * r2.inverse();


	ASSERT_EQ(resultDivise.getNum(), resultMultipleInverse.getNum());
	ASSERT_EQ(resultDivise.getDenom(), resultMultipleInverse.getDenom());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
