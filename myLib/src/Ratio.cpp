#include "Ratio.hpp"
#include <algorithm>


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

Ratio Ratio::operator+(const Ratio &r){
    Ratio result = Ratio(); 
    result.m_num = this->m_num * r.m_denom + this->m_denom * r.m_num;
    result.m_denom = this->m_denom*r.m_denom;
    result.pgcd();

    return result;
}

void Ratio::pgcd(){
    
    int pgcd = std::__gcd(this->m_num, this->m_denom);
    this->m_num = this->m_num/pgcd;
    this->m_denom = this->m_denom/pgcd;
}