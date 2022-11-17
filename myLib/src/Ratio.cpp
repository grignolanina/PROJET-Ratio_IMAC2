#include "Ratio.hpp"
#include <vector>

Ratio::Ratio(int num, int denom): m_num(num), m_denom(denom){}

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


