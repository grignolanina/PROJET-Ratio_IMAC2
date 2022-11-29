#include "Ratio.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stdexcept>

Ratio convert_float_to_ratio(float x, int nb_iter){

    Ratio r; // valeur par défaut est 0/1
    if( x == 0 || nb_iter == 0){
        return r; //return 0/1
    }

    else if( x<1 ){

        r = convert_float_to_ratio((1/x), nb_iter).inverse();
		r.irreductible();
		return r;
    }

    else{
        int q = (int)x;
		Ratio qRatio(q,1);
        r = qRatio + convert_float_to_ratio(x - q, nb_iter-1); 
		r.irreductible();
		return r;
    }
}

Ratio::Ratio(): m_num(0), m_denom(1){
}

Ratio::Ratio(int num, unsigned int denom): m_num(num), m_denom(denom){
		// if(denom==0){
		// 	throw std::invalid_argument("division by 0");
		// }
}

Ratio::Ratio(float x) : m_num(convert_float_to_ratio(x,5).m_num), m_denom(convert_float_to_ratio(x,5).m_denom){
	
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
	return (Ratio(((this->m_num*r.m_denom) - (this->m_denom*r.m_num)),(this->m_denom*r.m_denom))).irreductible();
}

Ratio Ratio::operator-(const int &value){;
    return (Ratio((*this) - Ratio(value,1))).irreductible();
}

Ratio Ratio::operator*(const Ratio &r){
	return (Ratio((this->m_num*r.m_num),(this->m_denom*r.m_denom))).irreductible();
}

Ratio Ratio::operator*(const int &value){
	return Ratio((this->m_num*value),(this->m_denom)).irreductible();
}

Ratio Ratio::operator/(const Ratio &r){
	return Ratio((this->m_num*r.m_denom),(this->m_denom*r.m_num)).irreductible();
}

Ratio Ratio::operator/(const int &value){
	return Ratio((this->m_num),(this->m_denom*value)).irreductible();
}

Ratio Ratio::inverse(){
	return Ratio((this->m_denom),(this->m_num)).irreductible();
}



Ratio Ratio::operator+(const Ratio &r){
    return Ratio((this->m_num * r.m_denom + this->m_denom * r.m_num),( this->m_denom*r.m_denom)).irreductible();
}

Ratio Ratio::operator+(const int &value){
    return ((*this) + Ratio(value,1)).irreductible();
}

Ratio Ratio::operator-(){
    return Ratio(((-1) * this->m_num),(this->m_denom)).irreductible();
}

void Ratio::display()const{
	std::cout << this->m_num << "/" << this->m_denom << std::endl;
}


Ratio Ratio::irreductible(){    
    int pgcd = std::gcd(this->m_num, this->m_denom);
    this->m_num = this->m_num/std::abs(pgcd);
    this->m_denom = this->m_denom/std::abs(pgcd);
	return(*this);
}

bool Ratio::operator==(const Ratio &r){
	if(this->m_num == r.m_num && this->m_denom == r.m_denom){
		return true;
	}

	return false;

}

bool Ratio::operator!=(const Ratio &r){

	if(this->m_num != r.m_num || this->m_denom != r.m_denom){
		return true;
	}

	return false;
}

bool Ratio::operator>(const Ratio &r){
	if( (*this-r).m_num > 0){
		return true;
	}
	return false;
}

bool Ratio::operator>=(const Ratio &r){
	if( (*this-r).m_num >= 0){
		return true;
	}
	return false;
}

bool Ratio::operator<(const Ratio &r){
	
	
	if( ((*this)-r).m_num < 0){
	
		return true;
	}
	return false;
}

bool Ratio::operator<=(const Ratio &r){
	
	if( ((*this)-r).m_num <= 0){
		return true;
	}
	return false;
}