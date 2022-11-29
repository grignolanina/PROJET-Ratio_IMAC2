#include "Ratio.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

Ratio ConvertFloatRatio(float x, int nb_iter){

    Ratio r; // valeur par défaut est 0/1
    if( x == 0 || nb_iter == 0){
        return r; //return 0/1
    }

    else if( std::abs(x)<1 ){
		if(x<0){
			r = ConvertFloatRatio(((-1)/(-x)), nb_iter).inverse();
			r.irreductible();
		}
		else{
			r = ConvertFloatRatio((1/x), nb_iter).inverse();
			r.irreductible();
		}
		return r;
    }

    else{
        int q = (int)x;
		Ratio qRatio(q,1);
        r = qRatio + ConvertFloatRatio(x - q, nb_iter-1); 
		r.irreductible();
		return r;
    }
}

Ratio::Ratio(): m_num(0), m_denom(1){
}

Ratio::Ratio(int num, unsigned int denom): m_num(num), m_denom(denom){
		//add exception
}

Ratio::Ratio(float x) : m_num(ConvertFloatRatio(x,5).m_num), m_denom(ConvertFloatRatio(x,5).m_denom){
	
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
	Ratio result = (*this) - Ratio(value,1);
	result.irreductible();
    return result;
}

Ratio Ratio::operator*(const Ratio &r){
	Ratio result = Ratio();
	result.m_num = this->m_num*r.m_num;
	result.m_denom=this->m_denom*r.m_denom;
	result.irreductible();
	return result;
}

Ratio Ratio::operator*(const int &value){
	Ratio result = Ratio();
	result.m_num = this->m_num*value;
	result.m_denom = this->m_denom;
	result.irreductible();
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
	if(this->m_num <0){
		result.m_num= -(this->m_denom);
		result.m_denom = -(this->m_num);
	}
	else{
		result.m_num= this->m_denom;
		result.m_denom = this->m_num;
	}
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
	Ratio result = (*this) + Ratio(value,1); 
	result.irreductible();
    return result;
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

bool Ratio::operator==(const Ratio &r){

	// this->irreductible();
	// r.irreductible();

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