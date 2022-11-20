#include "Ratio.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

// Ratio convert_float_to_ratio(float x, int nb_iter){
//     Ratio r(0,0);
//     if( x == 0 || nb_iter == 0){
//         r.m_num(0);
//         r.m_denom(1);
//         return r;
//     }

//     else if( x<1 ){

//         return 1/convert_float_to_ratio((1/x), nb_iter);
//     }

//     else if( x>1 ){
//         Ratio q((int) x, 1);
//         return q + convert_float_to_ratio(x - (int)x, nb_iter-1);
        
        
//     }
// }



Ratio::Ratio(): m_num(0), m_denom(1){
}

Ratio::Ratio(int num, unsigned int denom): m_num(num), m_denom(denom){
		//add exception
}

Ratio::Ratio(const Ratio & r): m_num(r.m_num), m_denom(r.m_denom){
}

int& Ratio::setNum(){
	return m_num;
}

unsigned int& Ratio::setDenom(){
	return m_denom;
}

const int& Ratio::getNum() const{
	return m_num;
}

const unsigned int& Ratio::getDenom() const{
	return m_denom;
}

Ratio Ratio::operator-(const Ratio &r){
	Ratio result = Ratio();
	result.m_num = (this->m_num*r.m_denom) - (this->m_denom*r.m_num);
	result.m_denom=this->m_denom*r.m_denom;
	result.irreductible();
	return result;
}

Ratio Ratio::operator-(const int &value){
	Ratio convert = Ratio(value,1); 
    return (*this - convert);
}

Ratio Ratio::operator*(const Ratio &r){
	Ratio result = Ratio();
	result.m_num = this->m_num*r.m_num;
	result.m_denom=this->m_denom*r.m_denom;
	return result;
}

Ratio Ratio::operator*(const int &value){
	Ratio result = Ratio();
	result.m_num = this->m_num*value;
	result.m_denom = this->m_denom;

	return result;
}

Ratio Ratio::operator/(const Ratio &r){
	Ratio result = Ratio();
	result.m_num = this->m_num*r.m_denom;
	result.m_denom = this->m_denom*r.m_num;
	result.irreductible();
	return result;
}

Ratio Ratio::operator/(const int &value){
	Ratio result = Ratio();
	result.m_num = this->m_num;
	result.m_denom=this->m_denom*value;
	result.irreductible();
	return result;
}

Ratio Ratio::inverse(){
	Ratio result = Ratio();
	result.m_num= this->m_denom;
	result.m_denom = this->m_num;
	result.irreductible();
	return result;
}



Ratio Ratio::operator+(const Ratio &r){
    Ratio result = Ratio(); 
    result.m_num = this->m_num * r.m_denom + this->m_denom * r.m_num;
    result.m_denom = this->m_denom*r.m_denom;
    result.irreductible();

    return result;
}

Ratio Ratio::operator+(const int &value){
	Ratio convert = Ratio(value,1); 
    return (*this + convert);
}

Ratio Ratio::operator-(){
    Ratio result;
    result.m_num = (-1) * this->m_num;
    result.m_denom = this->m_denom;
    result.irreductible();
    return result;
}

void Ratio::display()const{
	std::cout << this->m_num << "/" << this->m_denom << std::endl;
}


void Ratio::irreductible(){    
    int pgcd = std::gcd(this->m_num, this->m_denom);
    this->m_num = this->m_num/std::abs(pgcd);
    this->m_denom = this->m_denom/std::abs(pgcd);
}