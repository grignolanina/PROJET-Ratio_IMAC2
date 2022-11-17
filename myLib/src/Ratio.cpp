#include "Ratio.hpp"
#include <vector>


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
