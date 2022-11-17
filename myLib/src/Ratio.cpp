#include "Ratio.hpp"

Ratio::Ratio(): m_num(0), m_denom(1){
}

Ratio::Ratio(int num, int denom): m_num(num), m_denom(denom){
}

Ratio::Ratio(const Ratio & r): m_num(r.m_num), m_denom(r.m_denom){
}

int& Ratio::num(){
	return m_num;
}

int& Ratio::denom(){
	return m_denom;
}