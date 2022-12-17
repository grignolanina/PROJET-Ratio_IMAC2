#pragma once
#include <numeric>
#include <string>
#include <iostream>
#include <cmath>

#include "RatioException.hpp"

//pas faire
//static const unsigned int NB_ITER = 5;
//dans l'idée ça pour PI mais en dehors de la classe

/// \class Ratio
/// \brief class defining a rational for linear algebra operations
template<typename T>
class Ratio {

	public:

	/*****************************************************************
	CONSTRUCTORS
	******************************************************************/
	/// \brief default constructor
	/// \param num denom : the num of the ratio (optional)
	/// \param denom denom : the denum of the ratio (optional)
	Ratio(): m_num(0), m_denom(1){};


	/// \brief constructor from a num and a denom
	/// \param num denom : the num of the ratio
	/// \param denom denom : the denum of the ratio
	Ratio(T num, T denom): m_num(num), m_denom(denom){
		if(this->m_denom <0){
			this->m_num= -this->m_num;
			this->m_denom = -this->m_denom;
		}
		this->irreductible();
		if(denom==0){
			throw RatioException("Ratio() constructor with denom equal : " + std::to_string(this->m_denom), 1, ErrorType::fatal);
		}
	};

	/// \brief parameters constructor with a given float number
	/// \param x : the float which will be convert in a ratio
	Ratio(float x):Ratio(ConvertFloatRatio(x,7)){};


	/// \brief copy-constructor
	/// \param r : the source ratio to be copied
	// Ratio(const Ratio & r)=default;
	Ratio(const Ratio & r):m_num(r.m_num), m_denom(r.m_denom){};


	//rajouter constructeur
	//long int en int


	/*****************************************************************
	DESTRUCTOR
	******************************************************************/
	/// \brief destructor
	~Ratio() = default;


	private:

	/*****************************************************************
	VARIABLES
	******************************************************************/
	T m_num;
	//mettre en unsigned
	T m_denom;


	public:

	/*****************************************************************
	GETTER & SETTER
	******************************************************************/
	/// \brief fonction to set to the numerator of a vector
	/// \return ratio.num() 
	int& setNum();

	/// \brief fonction to set to the denominator of a vector
	/// \return ratio.denom() 
	unsigned int& setDenom();

	/// \brief fonction to access to the numerator of a vector
	/// \return ratio.num() 
	const int& getNum()const;

	/// \brief fonction to access to the denominator of a vector
	/// \return ratio.denom() 
	const int& getDenom()const;


	/*****************************************************************
	ARITHMETICS CLASSICS OPERATORS
	******************************************************************/
	//Ratio &operateur= (const Ratio &r);

	/// \brief add a ratio to *this
	/// \param r : ratio to add to the calling ratio
	/// \return the sum of the current ratio and the argument ratio
	Ratio operator+(const Ratio &r);

	/// \brief add a value to *this
	/// \param value : value to add to the calling ratio
	/// \return the sum of the current ratio and the value
	Ratio operator+(const int &value);

	/// \brief substract a ratio to *this
	/// \param r : ratio to substract to the calling ratio
	/// \return the substract of the current ratio and the argument ratio
	Ratio operator-(const Ratio &r);

	/// \brief substract a value to *this
	/// \param value : value to substract to the calling ratio
	/// \return the substract of the current ratio and the value
	Ratio operator-(const int &value);

	/// \brief unary minus
	/// \return the minus of the calling ratio
	Ratio operator-();

	/// \brief multiply a ratio to *this
	/// \param r : ratio to multiplicate to the calling ratio
	/// \return the multiplication ratio
	Ratio operator*(const Ratio &r);

	/// \brief multiply a ratio with a constant value
	/// \param value : multiplicate factor
	/// \return the multiplication ratio
	Ratio operator*(const int &value);

	/// \brief multiply a ratio with a constant value
	/// \param value : multiplicate factor
	/// \return the multiplication ratio
	Ratio operator*(const float &value); //surement faire Ratio operator*(const T &value) au final

	/// \brief divide a ratio to *this
	/// \param r : ratio to divide to the calling ratio
	/// \return the divided ratio
	Ratio operator/(const Ratio &r);

	/// \brief divide a ratio with a constant value
	/// \param value : deviding factor
	/// \return the divided ratio
	Ratio operator/(const int &value);


	/*****************************************************************
	COMPARE OPERATORS
	******************************************************************/
	/// \brief compare the equality of a ratio with *this
	/// \param r : ratio to compare to the calling ratio
	/// \return the boolean result of the comparation
	bool operator==(const Ratio &r);

	/// \brief compare the non-equality of a ratio with *this
	/// \param r : ratio to compare to the calling ratio
	/// \return the boolean result of the comparation
	bool operator!=(const Ratio &r);

	/// \brief test if *this is strictly higher than an other ratio
	/// \param r : ratio to compare to the calling ratio
	/// \return the boolean result of the comparation
	bool operator>(const Ratio &r);

	/// \brief test if *this is higher(or equal) than an other ratio
	/// \param r : ratio to compare to the calling ratio
	/// \return the boolean result of the comparation
	bool operator>=(const Ratio &r);

	/// \brief test if *this is strictly lower than an other ratio
	/// \param r : ratio to compare to the calling ratio
	/// \return the boolean result of the comparation
	bool operator<(const Ratio &r);

	/// \brief test if *this is lower (or equal) than an other ratio
	/// \param r : ratio to compare to the calling ratio
	/// \return the boolean result of the comparation
	bool operator<=(const Ratio &r);


	/*****************************************************************
	ARITHMETICS OTHERS OPERATORS
	******************************************************************/
	/// \brief inverse the calling ratio
	/// \return the inverse ratio
	Ratio inverse();

	/// \brief fonction which gives the absoluture quotient of a ratio
	/// \return the absolute value of the ratio
	Ratio abs();

	/// \brief fonction which gives the square root of a ratio by square rooting a and b separately
	/// \return the square root value of the ratio
	double sqrt();

	/// \brief fonction which gives the square root of a ratio by taking a/b in the square root
	/// \return the square root value of the ratio
	double sqrt2();

	/// \brief fonction which gives the cosinus of a ratio
	/// \return the value of the cosinus of the ratio
	double cosinus();

	/// \brief fonction which gives an approciamtion of the cosinus of a ratio
	/// \return the value of the approximated cosinus of the ratio
	double cosinus2();

	/// \brief fonction which gives the sinus of a ratio
	/// \return the value of the sinus of the ratio
	double sinus();

	/// \brief fonction which gives the tangent of a ratio
	/// \return the value of the tangent of the ratio
	double tan();

	/// \brief fonction which gives a ratio powered by an int number
	/// \param k : power of the ratio
	/// \return the ratio powered by k
	Ratio pow1(int k);

	/// \brief fonction which gives a ratio powered by an int number
	/// \param k : power of the ratio
	/// \return the ratio powered by k
	Ratio pow2(int k);

	/// \brief fonction which gives the integer part of a ratio
	/// \return the value of the interger part of the ratio
	Ratio intPart();


	/*****************************************************************
	AFFICHAGE
	******************************************************************/
	/// \brief display the ratio calling properly in the terminal
	/// \return ratio
	void display()const;


	/*****************************************************************
	CONVERTION
	******************************************************************/
	/// \brief convert a float in a ratio
	/// \param x : float we want to convert
	///\param nb_iter : number of iterations we want to do to find the ratio
	/// \return the sum of the current ratio and the argument ratio
	static Ratio ConvertFloatRatio(float x, int nb_iter);


	/// \brief fonction which gives the irreductible quotient of a ratio
	/// \return irreductible ratio
	Ratio irreductible();


	/// \brief convert this calling ratio in a float
	/// \param x
	float ConvertRatioToFloat();

	/*****************************************************************
	STATIC VARIABLE
	******************************************************************/
	/// \brief fonction which multiply by infinte the calling ratio
	/// \return ratio 1/0
	constexpr static Ratio multiplyInfinite()noexcept{return Ratio(1,0);};

	/// \brief fonction which multiply by the zero the calling ratio
	/// \return ratio 0/1
	constexpr static Ratio multiplyZero()noexcept{return Ratio(0,1);};

	/// \brief fonction which givr the pi ratio
	/// \return ratio M_Pi/1
	constexpr static Ratio pi()noexcept{return Ratio(322/117);};


	/// \brief fonction which test if a ratio is infinite
	/// \return true of false
	bool isInfinite(){return ((float)m_num/m_denom)>= std::numeric_limits<float>::max() ? true : false;}

};

// 	template<typename T>
// 	inline constexpr static Ratio<T> Pi()=Ratio<T>(22/7)};

// 	template<typename T>
// 	constexpr static Ratio<T> Pi()noexcept{return Ratio<T>(22/7);};


// 	template<typename T>
// 	Ratio<T> zero(1/0);

// 	template<typename T>
// 	Ratio<T> pi(22/7);

// }


/*****************************************************************
ARITHMETICS CLASSICS OPERATORS
******************************************************************/
template<typename T>
Ratio<T> Ratio<T>::operator+(const Ratio &r){
    return (Ratio((this->m_num * r.m_denom + this->m_denom * r.m_num),( this->m_denom*r.m_denom))).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator+(const int &value){
    return ((*this) + Ratio(value,1)).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator-(){
    return Ratio(((-1) * this->m_num),(this->m_denom)).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator-(const Ratio &r){
	return (Ratio(((this->m_num*r.m_denom) - (this->m_denom*r.m_num)),(this->m_denom*r.m_denom))).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator-(const int &value){;
    return (Ratio((*this) - Ratio(value,1))).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator*(const Ratio &r){
	return (Ratio((this->m_num*r.m_num),(this->m_denom*r.m_denom))).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator*(const int &value){
	return Ratio((this->m_num*value),(this->m_denom)).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator*(const float &value){
	float temporary = this->ConvertRatioToFloat()*value;
	return Ratio(temporary).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator/(const Ratio &r){
	return Ratio((this->m_num*r.m_denom),(this->m_denom*r.m_num)).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator/(const int &value){
	return Ratio((this->m_num),(this->m_denom*value)).irreductible();
}

/*****************************************************************
COMPARE OPERATORS
******************************************************************/
template<typename T>
bool Ratio<T>::operator==(const Ratio &r){
	if(this->m_num == r.m_num && this->m_denom == r.m_denom){
		return true;
	}
	return false;
}

template<typename T>
bool Ratio<T>::operator!=(const Ratio &r){
	if(this->m_num != r.m_num || this->m_denom != r.m_denom){
		return true;
	}
	return false;
}

template<typename T>
bool Ratio<T>::operator>(const Ratio &r){
	if( (*this-r).m_num > 0){
		return true;
	}
	return false;
}

template<typename T>
bool Ratio<T>::operator>=(const Ratio &r){
	if( (*this-r).m_num >= 0){
		return true;
	}
	return false;
}

template<typename T>
bool Ratio<T>::operator<(const Ratio &r){
	if( ((*this)-r).m_num < 0){
		return true;
	}
	return false;
}

template<typename T>
bool Ratio<T>::operator<=(const Ratio &r){
	if( ((*this)-r).m_num <= 0){
		return true;
	}
	return false;
}


/*****************************************************************
ARITHMETICS OTHERS OPERATORS
******************************************************************/
template<typename T>
Ratio<T> Ratio<T>::inverse(){
	if(this->m_num < 0){
		return (Ratio(-(this->m_denom),-(this->m_num))).irreductible();
	}
	else{
		return (Ratio((this->m_denom),(this->m_num))).irreductible();
	}
	
}

template<typename T>
Ratio<T> Ratio<T>::abs(){  
	if((*this)<0){
		return -(*this);
	}else{
		return (*this);
	}
}

template<typename T>
double Ratio<T>::sqrt(){  
	return std::sqrt(m_num)/std::sqrt(m_denom);
}

template<typename T>
double Ratio<T>::sqrt2(){  
	return std::sqrt((double)m_num/m_denom);
}

template<typename T>
double Ratio<T>::cosinus(){  
	return std::cos((double)m_num/m_denom);
}

template<typename T>
double Ratio<T>::cosinus2(){  
	return std::cos(m_num)/std::cos(m_denom);
}

template<typename T>
double Ratio<T>::sinus(){  
	return std::sin((double)m_num/m_denom);
}

template<typename T>
double Ratio<T>::tan(){  
	return this->sinus()/this->cosinus();
}

template<typename T>
Ratio<T> Ratio<T>::pow1(int k){  
	return (k > 0)? (*this) * pow1(k-1) : 1;
}

template<typename T>
Ratio<T> Ratio<T>::pow2(int k){  
	return std::pow(m_num,k)/std::pow(m_denom,k);
}

template<typename T>
Ratio<T> Ratio<T>::intPart(){ 

	return Ratio((int)(m_num/m_denom), 1);
}

/*****************************************************************
GETTER & SETTER
******************************************************************/
template<typename T>
int& Ratio<T>::setNum(){
	return m_num;
}

template<typename T>
unsigned int& Ratio<T>::setDenom(){
	return m_denom;
}

template<typename T>
const int& Ratio<T>::getNum() const{
	return m_num;
}

template<typename T>
const int& Ratio<T>::getDenom() const{
	return m_denom;
}






/*****************************************************************
AFFICHAGE
******************************************************************/
template<typename T>
void Ratio<T>::display()const{
	std::cout << this->m_num << "/" << this->m_denom << std::endl;
}

template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio<T>& r){

	stream << r.getNum();
	stream << "/"	;
	stream << r.getDenom();
	stream << "\n";

	return stream;
}

/*****************************************************************
CONVERTION
******************************************************************/
template<typename T>
Ratio<T> Ratio<T>::ConvertFloatRatio(float x, int nb_iter){
    Ratio<T> r; // valeur par défaut est 0/1

	


    if( x == 0 || nb_iter == 0){
        return r; //return 0/1
    }

    else if( std::abs(x)<1 ){
		if(x<0){
			r = ConvertFloatRatio(((-1)/(-x)), nb_iter).inverse();
		}
		else{
			r = ConvertFloatRatio((1/x), nb_iter).inverse();
		}
		return r.irreductible();
    }

    else{
        int q = (int)x;
		Ratio<T> qRatio(q,1);
        r = qRatio + ConvertFloatRatio(x - q, nb_iter-1); 
		return r.irreductible();
    }
}

template<typename T>
Ratio<T> Ratio<T>::irreductible(){    
    int pgcd = std::gcd(this->m_num, this->m_denom);
    this->m_num = this->m_num/std::abs(pgcd);
    this->m_denom = this->m_denom/std::abs(pgcd);
	return(*this);
}

template<typename T>
float Ratio<T>::ConvertRatioToFloat(){
	return this->m_num/(float)this->m_denom;
}


