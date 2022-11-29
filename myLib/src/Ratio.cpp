#include "Ratio.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stdexcept>



// template<typename T>
// Ratio<T>::Ratio(): m_num(0), m_denom(1){
// }

// template<typename T>
// Ratio<T>::Ratio(T num, T denom): m_num(num), m_denom(denom){
// 		// if(denom==0){
// 		// 	throw std::invalid_argument("division by 0");
// 		// }
// }

// // template<typename T>
// // Ratio<T>::Ratio(float x) : m_num(ConvertFloatRatio(x,5).m_num), m_denom(ConvertFloatRatio(x,5).m_denom){
	
// // }

// template<typename T>
// Ratio<T>::Ratio(const Ratio & r): m_num(r.m_num), m_denom(r.m_denom){
// }

// template<typename T>
// int& Ratio<T>::setNum(){
// 	return m_num;
// }

// template<typename T>
// unsigned int& Ratio<T>::setDenom(){
// 	return m_denom;
// }

// template<typename T>
// const int& Ratio<T>::getNum() const{
// 	return m_num;
// }

// template<typename T>
// const unsigned int& Ratio<T>::getDenom() const{
// 	return m_denom;
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator-(const Ratio &r){
// 	return (Ratio(((this->m_num*r.m_denom) - (this->m_denom*r.m_num)),(this->m_denom*r.m_denom))).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator-(const int &value){;
//     return (Ratio((*this) - Ratio(value,1))).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator*(const Ratio &r){
// 	return (Ratio((this->m_num*r.m_num),(this->m_denom*r.m_denom))).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator*(const int &value){
// 	return Ratio((this->m_num*value),(this->m_denom)).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator/(const Ratio &r){
// 	return Ratio((this->m_num*r.m_denom),(this->m_denom*r.m_num)).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator/(const int &value){
// 	return Ratio((this->m_num),(this->m_denom*value)).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::inverse(){
// 	if(this->m_num < 0){
// 		return Ratio(-(this->m_denom),-(this->m_num)).irreductible();
// 	}
// 	else{
// 		return Ratio((this->m_denom),(this->m_num)).irreductible();
// 	}
	
// }


// template<typename T>
// Ratio<T> Ratio<T>::operator+(const Ratio &r){
//     return Ratio((this->m_num * r.m_denom + this->m_denom * r.m_num),( this->m_denom*r.m_denom)).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator+(const int &value){
//     return ((*this) + Ratio(value,1)).irreductible();
// }

// template<typename T>
// Ratio<T> Ratio<T>::operator-(){
//     return Ratio(((-1) * this->m_num),(this->m_denom)).irreductible();
// }

// template<typename T>
// void Ratio<T>::display()const{
// 	std::cout << this->m_num << "/" << this->m_denom << std::endl;
// }

// template<typename T>
// Ratio<T> Ratio<T>::irreductible(){    
//     int pgcd = std::gcd(this->m_num, this->m_denom);
//     this->m_num = this->m_num/std::abs(pgcd);
//     this->m_denom = this->m_denom/std::abs(pgcd);
// 	return(*this);
// }

// template<typename T>
// bool Ratio<T>::operator==(const Ratio &r){
// 	if(this->m_num == r.m_num && this->m_denom == r.m_denom){
// 		return true;
// 	}

// 	return false;

// }

// template<typename T>
// bool Ratio<T>::operator!=(const Ratio &r){
// 	if(this->m_num != r.m_num || this->m_denom != r.m_denom){
// 		return true;
// 	}
// 	return false;
// }

// template<typename T>
// bool Ratio<T>::operator>(const Ratio &r){
// 	if( (*this-r).m_num > 0){
// 		return true;
// 	}
// 	return false;
// }

// template<typename T>
// bool Ratio<T>::operator>=(const Ratio &r){
// 	if( (*this-r).m_num >= 0){
// 		return true;
// 	}
// 	return false;
// }

// template<typename T>
// bool Ratio<T>::operator<(const Ratio &r){
// 	if( ((*this)-r).m_num < 0){
// 		return true;
// 	}
// 	return false;
// }

// template<typename T>
// bool Ratio<T>::operator<=(const Ratio &r){
// 	if( ((*this)-r).m_num <= 0){
// 		return true;
// 	}
// 	return false;
// }