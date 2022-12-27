#include <iostream>

int main(){
	std::cout << "WELCOME IN THE RATIO LIB !" << std::endl << std::endl;
	std::cout << "This lib aim at help on operations on the rationals numbers" << std::endl;
	std::cout << "Thus, you can find here many operators and fonctions to manipulate ratio" << std::endl << std::endl;
	std::cout << "Here is an exhaustive list of operators that you can use :" << std::endl;
	std::cout << "Classic operators :" << std::endl;
	std::cout << "• +" << std::endl;
	std::cout << "• -" << std::endl;
	std::cout << "• *" << std::endl;
	std::cout << "• /" << std::endl;
	std::cout << "• +=" << std::endl;
	std::cout << "• -=" << std::endl;
	std::cout << "• *=" << std::endl;
	std::cout << "• /=" << std::endl << std::endl;

	std::cout << "Comparison operators :" << std::endl;
	std::cout << "• =" << std::endl;
	std::cout << "• ==" << std::endl;
	std::cout << "• <=" << std::endl;
	std::cout << "• >=" << std::endl;
	std::cout << "• <" << std::endl;
	std::cout << "• >" << std::endl;
	std::cout << "• >=" << std::endl << std::endl;

	std::cout << "Others arithmetic operators :" << std::endl;
	std::cout << "• cos" << std::endl;
	std::cout << "• sin" << std::endl;
	std::cout << "• tan" << std::endl;
	std::cout << "• exp" << std::endl;
	std::cout << "• ln" << std::endl;
	std::cout << "• abs" << std::endl;
	std::cout << "• intPart" << std::endl;
	std::cout << "• sqrt" << std::endl;
	std::cout << "• inverse" << std::endl;
	std::cout << "• pow" << std::endl << std::endl;

	std::cout << "You also have access to specific numbers like 0, pi and infinity, with the following respective names:" << std::endl;
	std::cout << "• zero()" << std::endl;
	std::cout << "• pi()"<< std::endl;
	std::cout << "• infinite()" << std::endl << std::endl;

	std::cout << "To construct your personnal ratio, there are the four following constructors :" << std::endl;
	std::cout << "• Ratio() : the default constructor with give 0/1" << std::endl;
	std::cout << "• Ratio(num, denom) : the constructor with the numerator and the denominator"<< std::endl;
	std::cout << "• Ratio(Ratio()) : the constructor by copy"<< std::endl;
	std::cout << "• Ratio(float) : the constructor from a float" << std::endl << std::endl;

	std::cout << "Finally, you can display your ratio with two ways : "<< std::endl; 
	std::cout << "• display() : the method" << std::endl;
	std::cout <<"• << : the classic characters" << std::endl << std::endl;

	std::cout << "And there you go ! you are ready to construct your ratios and do lots of tests on the ratio lib. However, if you want more informations, we invite you to compile HTML utility and open the index.html present in the build/INTERFACE/doc/doc-doxygen/html. It will present you a complete lib create thanks to dowygen !" << std::endl;
	std::cout << "You can also watch the examples.cpp which will show you more about the use of the lib !" << std::endl;
	std::cout << "IT'S YOUR MOVE !" << std::endl;

	return 0;
}