#pragma once
#include <numeric>
#include <string>
#include <iostream>
#include <cmath>

#include "RatioException.hpp"

//pas faire
//static const unsigned int NB_ITER = 5;
//dans l'idée ça pour PI mais en dehors de la classe

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html accueil.jpg
/// \tableofcontents
/// \section instroduction_sec Ratio projet
/// This is a student project realised at the French engineering school IMAC, for the third semester for object programming and computer science mathematics courses.This work focused on the representation of floating point numbers in the form of rationals. You will therefore find there a research work on rational numbers, the mathematical rules that apply to them and a library allowing their manipulation.
/// \section dependencies_sec Dependencies
/// \subsection is CMake (at least version  3.13)
/// \li - Linux : sudo apt install cmake
///\li - Mac : brew install cmake
///\li - Windows : https://cmake.org/install
/// \subsection Doxygen
///\li - Linux : sudo apt install doxygen
///\li - Mac : brew install doxygen
///\li - Windows : https://www.doxygen.nl/manual/install.html
/// \subsection Google Test
///\li - Linux : sudo apt-get install libgtest-dev
///\li - Mac : 
/// \n       cd /tmp
/// \n       git clone https://github.com/google/googletest.git
/// \n       cd googletest
/// \n       mkdir build && cd build
/// \n       cmake ..
/// \n       make && sudo make install
/// \li - Windows : ?
/// \section usage_sec Usage
/// \li Please use the CMake in the IDE : VSCode
/// \li Before starting the project make sure you have the following extensions :
/// \li • C/C++ (microsoft)
/// \li • C/C++ extension pack (microsoft)
/// \li • C/C++ Themes (microsoft)
/// \li • Clang-Format (xaver)
/// \li • CMake (twxs)
/// \section author_sec Authors
/// \li GRIGNOLA Nina
/// \li GOBE Pauline


namespace ratio {

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
		Ratio(float x):Ratio(ConvertFloatRatio(x,7)){
		// 	if(! std::is_floating_point<T>::value){
		// 	if(std::is_integral<T>::value){
		// 		Ratio(x,1);
		// 	}
		// 	else{
		// 		A REVOIR !!!!
		// 		throw RatioException("ConvertFloatRatio(x, nb_iter) : " + std::to_string(x), 1, ErrorType::fatal);
		// 	}	
		// }
		};


		/// \brief copy-constructor
		/// \param r : the source ratio to be copied
		// Ratio(const Ratio & r)=default;
		Ratio(const Ratio & r):m_num(r.m_num), m_denom(r.m_denom){};


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
		Ratio operator+(const Ratio &r) const;

		/// \brief add a value to *this
		/// \param value : value to add to the calling ratio
		/// \return the sum of the current ratio and the value
		Ratio operator+(const int &value) const;

		/// \brief substract a ratio to *this
		/// \param r : ratio to substract to the calling ratio
		/// \return the substract of the current ratio and the argument ratio
		Ratio operator-(const Ratio &r) const;

		/// \brief substract a value to *this
		/// \param value : value to substract to the calling ratio
		/// \return the substract of the current ratio and the value
		Ratio operator-(const int &value) const;

		/// \brief unary minus
		/// \return the minus of the calling ratio
		Ratio operator-() const;

		/// \brief multiply a ratio to *this
		/// \param r : ratio to multiplicate to the calling ratio
		/// \return the multiplication ratio
		Ratio operator*(const Ratio &r) const;

		// /// \brief multiply a ratio with a constant value
		// /// \param value : multiplicate factor
		// /// \return the multiplication ratio
		// Ratio operator*(const int &value);

		/// \brief multiply a ratio with a constant value
		/// \param value : multiplicate factor, must be a int, float or double
		/// \return the multiplication ratio
		template<typename U>
		Ratio operator*(const U &value) const; 

		/// \brief multiply a constant value with a ratio
		/// \param value : multiplicate factor
		/// \return the multiplication ratio
		template<typename U>
		friend Ratio operator*(const U &value, const Ratio &r); 

		/// \brief divide a ratio to *this
		/// \param r : ratio to divide to the calling ratio
		/// \return the divided ratio
		Ratio operator/(const Ratio &r) const;

		/// \brief divide a ratio with a constant value
		/// \param value : deviding factor
		/// \return the divided ratio
		template<typename U>
		Ratio operator/(const U &value) const;

		/// \brief divide a ratio with a constant value
		/// \param value : float deviding factor
		/// \return the divided ratio
		Ratio operator/(const  float &value) const;

		/*****************************************************************
		COMPARE OPERATORS
		******************************************************************/
		/// \brief compare the equality of a ratio with *this
		/// \param r : ratio to compare to the calling ratio
		/// \return the boolean result of the comparation
		bool operator==(const Ratio &r) const;

		/// \brief compare the non-equality of a ratio with *this
		/// \param r : ratio to compare to the calling ratio
		/// \return the boolean result of the comparation
		bool operator!=(const Ratio &r) const;

		/// \brief test if *this is strictly higher than an other ratio
		/// \param r : ratio to compare to the calling ratio
		/// \return the boolean result of the comparation
		bool operator>(const Ratio &r) const;

		/// \brief test if *this is higher(or equal) than an other ratio
		/// \param r : ratio to compare to the calling ratio
		/// \return the boolean result of the comparation
		bool operator>=(const Ratio &r) const;

		/// \brief test if *this is strictly lower than an other ratio
		/// \param r : ratio to compare to the calling ratio
		/// \return the boolean result of the comparation
		bool operator<(const Ratio &r) const;

		/// \brief test if *this is lower (or equal) than an other ratio
		/// \param r : ratio to compare to the calling ratio
		/// \return the boolean result of the comparation
		bool operator<=(const Ratio &r) const;


		/*****************************************************************
		ARITHMETICS OTHERS OPERATORS
		******************************************************************/
		/// \brief inverse the calling ratio
		/// \return the inverse ratio
		Ratio inverse() const;

		/// \brief fonction which gives the absoluture quotient of a ratio
		/// \return the absolute value of the ratio
		Ratio abs() const;

		/// \brief fonction which gives the square root of a ratio by square rooting a and b separately
		/// \return the square root value of the ratio
		double sqrt() const;

		/// \brief fonction which gives the square root of a ratio by taking a/b in the square root
		/// \return the square root value of the ratio
		double sqrt2() const;

		/// \brief fonction which gives the cosinus of a ratio
		/// \return the value of the cosinus of the ratio
		double cosinus() const;

		/// \brief fonction which gives an approciamtion of the cosinus of a ratio
		/// \return the value of the approximated cosinus of the ratio
		double cosinus2() const;

		/// \brief fonction which gives the sinus of a ratio
		/// \return the value of the sinus of the ratio
		double sinus() const;

		/// \brief fonction which gives the tangent of a ratio
		/// \return the value of the tangent of the ratio
		double tan() const;

		/// \brief fonction which gives a ratio powered by an int number
		/// \param k : power of the ratio
		/// \return the ratio powered by k
		Ratio pow1(int k) const;

		/// \brief fonction which gives a ratio powered by an int number
		/// \param k : power of the ratio
		/// \return the ratio powered by k
		Ratio pow2(int k) const;

		/// \brief fonction which gives the integer part of a ratio
		/// \return the value of the interger part of the ratio
		Ratio intPart() const;

		///\brief fonction which gives the value of the exponential of the rational called
		/// \return the value of the exponentiel of the ratio
		Ratio exp() const;

		///\brief fonction which gives the value of the exponential of the rational called
		/// \return the value of the exponentiel of the ratio
		Ratio expLib() const;

		///\brief fonction which gives the value of the logarithm of the rational called
		/// \return the value of the logarithm of the ratio
		Ratio log() const;


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
		static Ratio ConvertFloatRatio( const float &x,  const int &nb_iter);


		/// \brief fonction which gives the irreductible quotient of a ratio
		/// \return irreductible ratio
		Ratio irreductible();


		/// \brief convert this calling ratio in a float
		/// \param x
		float ConvertRatioToFloat() const;

		/*****************************************************************
		STATIC VARIABLE
		******************************************************************/
		// /// \brief fonction which multiply by infinte the calling ratio
		// /// \return ratio 1/0
		// constexpr static Ratio multiplyInfinite()noexcept{return Ratio(1/0);};

		// /// \brief fonction which multiply by the zero the calling ratio
		// /// \return ratio 0/1
		// constexpr static Ratio multiplyZero()noexcept{return Ratio(0/1);};

		// /// \brief fonction which givr the pi ratio
		// /// \return ratio M_Pi/1
		// constexpr static Ratio pi()noexcept{return Ratio(M_PI/1);};


		/*****************************************************************
		STATIC VARIABLE
		******************************************************************/
		/// \brief give the ratio zero
		inline constexpr static Ratio<T> zero(){return Ratio<T>(0,1);}


		/// \brief give the ratio infinte
		inline constexpr static Ratio<T> infinite(){
			Ratio<T> r;
			r.m_num = 1 ;
			r.m_denom = 0;			
			return r;
		}

		/// \brief give the ratio pi
		inline constexpr static Ratio<T> pi(){return Ratio<T>(355,113);}

	};



	/*****************************************************************
	ARITHMETICS CLASSICS OPERATORS
	******************************************************************/
	template<typename T>
	Ratio<T> Ratio<T>::operator+(const Ratio &r)const{
		return (Ratio((this->m_num * r.m_denom + this->m_denom * r.m_num),( this->m_denom*r.m_denom))).irreductible();
	}

	template<typename T>
	Ratio<T> Ratio<T>::operator+(const int &value) const{
		return ((*this) + Ratio(value,1)).irreductible();
	}

	template<typename T>
	Ratio<T> Ratio<T>::operator-() const{
		return Ratio(((-1) * this->m_num),(this->m_denom)).irreductible();
	}

	template<typename T>
	Ratio<T> Ratio<T>::operator-(const Ratio &r) const{
		return (Ratio(((this->m_num*r.m_denom) - (this->m_denom*r.m_num)),(this->m_denom*r.m_denom))).irreductible();
	}

	template<typename T>
	Ratio<T> Ratio<T>::operator-(const int &value) const{;
		return (Ratio((*this) - Ratio(value,1))).irreductible();
	}

	template<typename T>
	Ratio<T> Ratio<T>::operator*(const Ratio &r) const{
		return (Ratio((this->m_num*r.m_num),(this->m_denom*r.m_denom))).irreductible();
	}

	// template<typename T>
	// Ratio<T> Ratio<T>::operator*(const int &value){
	// 		std::cout << std::is_integral<T>::value << std::endl; 
			
	// 			return Ratio((this->m_num*value),(this->m_denom)).irreductible();
	// }

	template<typename T>
	template<typename U>
	Ratio<T> Ratio<T>::operator*(const U &value) const{
		return ((*this)*Ratio(value)).irreductible();
	}

	// template<typename T>
	// Ratio<T> operator*(const float &value, const Ratio<T> &r) const{
	// 	return Ratio((r.getNum()*value),(r.getDenom()));
	// }

	template<typename T>
	Ratio<T> Ratio<T>::operator/(const Ratio &r) const{
		return Ratio((this->m_num*r.m_denom),(this->m_denom*r.m_num)).irreductible();
	}

	template<typename T>
	template<typename U>
	Ratio<T> Ratio<T>::operator/(const U &value) const{
		return Ratio((*this)/Ratio(value)).irreductible();
	}

	// template<typename T>
	// Ratio<T> Ratio<T>::operator/(const float &value) const{
	// 	float temporary = this->ConvertRatioToFloat()/value;
	// 	return Ratio(temporary).irreductible();	
	// }

	/*****************************************************************
	COMPARE OPERATORS
	******************************************************************/
	template<typename T>
	bool Ratio<T>::operator==(const Ratio &r) const{
		if(this->m_num == r.m_num && this->m_denom == r.m_denom){
			return true;
		}
		return false;
	}

	template<typename T>
	bool Ratio<T>::operator!=(const Ratio &r) const{
		if(this->m_num != r.m_num || this->m_denom != r.m_denom){
			return true;
		}
		return false;
	}

	template<typename T>
	bool Ratio<T>::operator>(const Ratio &r) const{
		if( (*this-r).m_num > 0){
			return true;
		}
		return false;
	}


	template<typename T>
	bool Ratio<T>::operator>=(const Ratio &r) const{
		if( (*this-r).m_num >= 0){
			return true;
		}
		return false;
	}

	template<typename T>
	bool Ratio<T>::operator<(const Ratio &r) const{
		if( ((*this)-r).m_num < 0){
			return true;
		}
		return false;
	}

	template<typename T>
	bool Ratio<T>::operator<=(const Ratio &r) const{
		if( ((*this)-r).m_num <= 0){
			return true;
		}
		return false;
	}


	/*****************************************************************
	ARITHMETICS OTHERS OPERATORS
	******************************************************************/
	template<typename T>
	Ratio<T> Ratio<T>::inverse() const{
		if(this->m_num < 0){
			return (Ratio(-(this->m_denom),-(this->m_num))).irreductible();
		}
		else{
			return (Ratio((this->m_denom),(this->m_num))).irreductible();
		}
		
	}

	template<typename T>
	Ratio<T> Ratio<T>::abs() const{  
		if((*this)<0){
			return -(*this);
		}else{
			return (*this);
		}
	}

	template<typename T>
	double Ratio<T>::sqrt() const{  
		if((*this)<0){
			throw RatioException("Square root of negative is not allowed", 2, ErrorType::fatal);
		}
		return std::sqrt(m_num)/std::sqrt(m_denom);
	}

	template<typename T>
	double Ratio<T>::sqrt2() const{ 
		if((*this)<0){
			throw RatioException("Square root of negative is not allowed", 3, ErrorType::fatal);
		} 
		return std::sqrt((double)m_num/m_denom);
	}

	template<typename T>
	double Ratio<T>::cosinus() const{  
		return std::cos((double)m_num/m_denom);
	}

	template<typename T>
	double Ratio<T>::cosinus2() const{  
		return std::cos(m_num)/std::cos(m_denom);
	}

	template<typename T>
	double Ratio<T>::sinus() const{  
		return std::sin((double)m_num/m_denom);
	}

	template<typename T>
	double Ratio<T>::tan() const{  
		return this->sinus()/this->cosinus();
	}

	template<typename T>
	Ratio<T> Ratio<T>::pow1(int k) const{  
		return (k > 0)? (*this) * pow1(k-1) : 1;
	}

	template<typename T>
	Ratio<T> Ratio<T>::pow2(int k) const{  
		return std::pow(m_num,k)/std::pow(m_denom,k);
	}

	template<typename T>
	Ratio<T> Ratio<T>::intPart() const{ 

		return Ratio((int)(m_num/m_denom), 1);
	}

	int fact(int n){
		return (n==0) ? 1 : n*fact(n-1);
	}

	template<typename T>
	Ratio<T> Ratio<T>::exp() const{
		return pow(std::exp(m_num), pow(m_denom, -1));
	}

	template<typename T>
	Ratio<T> Ratio<T>::expLib() const{
		return Ratio(std::exp((float)m_num/m_denom));
	}

	template<typename T>
	Ratio<T> Ratio<T>::log() const{
		return std::log(m_num)-std::log(m_denom);
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
	Ratio<T> Ratio<T>::ConvertFloatRatio(const float &x, const int &nb_iter){
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
	float Ratio<T>::ConvertRatioToFloat() const{
		return this->m_num/(float)this->m_denom;
	}






}
