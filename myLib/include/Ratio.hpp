#pragma once
#include <numeric>
#include <iostream>
#include <stdexcept>


/// \class Ratio
/// \brief class defining a rational for linear algebra operations
template<typename T>
class Ratio {

	public:
	// Ratio(int num = 0, int denom = 1);
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

		// if(denom==0){
		// 	throw std::invalid_argument("division by 0");
		// }
	};

	/// \brief parameters constructor with a given float number
	/// \param x : the float which will be convert in a ratio
	Ratio(float x):Ratio(ConvertFloatRatio(x,5)){};


	/// \brief copy-constructor
	/// \param r : the source ratio to be copied
	// Ratio(const Ratio & r)=default;
	Ratio(const Ratio & r):m_num(r.m_num), m_denom(r.m_denom){};


	//rajouter constructeur
	//long int en int


	/// \brief destructor
	~Ratio() = default;

	
	private:
	T m_num;
	//mettre en unsigned
	T m_denom;

	public:
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

	/// \brief divide a ratio to *this
	/// \param r : ratio to divide to the calling ratio
	/// \return the divided ratio
	Ratio operator/(const Ratio &r);

	/// \brief divide a ratio with a constant value
	/// \param value : deviding factor
	/// \return the divided ratio
	Ratio operator/(const int &value);

	/// \brief inverse the calling ratio
	/// \return the inverse ratio
	Ratio inverse();

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

	/// \brief display the ratio calling properly in the terminal
	/// \return ratio
	void display()const;


	/// \brief fonction which gives the irreductible quotient of a ratio
	/// \return irreductible ratio
	Ratio irreductible();


	static Ratio ConvertFloatRatio(float x, int nb_iter);


	
};
 
/// \brief convert a float in a ratio
/// \param x : float we want to convert
///\param nb_iter : number of iterations we want to do to find the ratio
/// \return the sum of the current ratio and the argument ratio
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

// template<typename T>
// Ratio<T>::Ratio(): m_num(0), m_denom(1){
// }

// template<typename T>
// Ratio<T>::Ratio(T num, T denom): m_num(num), m_denom(denom){
// 		// if(denom==0){
// 		// 	throw std::invalid_argument("division by 0");
// 		// }
// }

// template<typename T>
// Ratio<T>::Ratio(float x) : m_num(ConvertFloatRatio(x,5).m_num), m_denom(ConvertFloatRatio(x,5).m_denom){
	
// }

// template<typename T>
// Ratio<T>::Ratio(const Ratio & r): m_num(r.m_num), m_denom(r.m_denom){
// }

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
Ratio<T> Ratio<T>::operator/(const Ratio &r){
	return Ratio((this->m_num*r.m_denom),(this->m_denom*r.m_num)).irreductible();
}

template<typename T>
Ratio<T> Ratio<T>::operator/(const int &value){
	return Ratio((this->m_num),(this->m_denom*value)).irreductible();
}

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
void Ratio<T>::display()const{
	std::cout << this->m_num << "/" << this->m_denom << std::endl;
}

template<typename T>
Ratio<T> Ratio<T>::irreductible(){    
    int pgcd = std::gcd(this->m_num, this->m_denom);
    this->m_num = this->m_num/std::abs(pgcd);
    this->m_denom = this->m_denom/std::abs(pgcd);
	return(*this);
}

//pour denom positif 
// template<typename T>
// Ratio<T> Ratio<T>::sign(){
// 	if(this->getDenom<0){
// 		this->setNum()= -this->getNum();
// 		this->setDenom()= -this->getDenom();
// 	}
// 	return(*this);
// }

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

// il faut décider de l'affichage qu'on veut au final !
template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio<T>& r){

	stream << r.getNum();
	stream << "/"	;
	stream << r.getDenom();
	stream << "\n";

	return stream;
}