#pragma once

/// \class Ratio
/// \brief class defining a rational for linear algebra operations
class Ratio {

	public:
	// Ratio(int num = 0, int denom = 1);
	/// \brief constructor from a num and a denom and default constructor
	/// \param num denom : the num of the ratio (optional)
	/// \param denom denom : the denum of the ratio (optional)
	Ratio();


	/// \brief constructor from a num and a denom and default constructor
	/// \param num denom : the num of the ratio
	/// \param denom denom : the denum of the ratio
	Ratio(int num, unsigned int denom);

	/// \brief parameters constructor with a given float number
	/// \param x : the float which will be convert in a ratio
	Ratio(float x);


	/// \brief copy-constructor
	/// \param r : the source ratio to be copied
	Ratio(const Ratio & r);


	/// \brief destructor
	~Ratio() = default;

	
	private:
	int m_num;
	unsigned int m_denom;

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
	const unsigned int& getDenom()const;

	/// \brief display the ratio calling properly in the terminal
	/// \return ratio
	void display()const;


	/// \brief fonction which gives the irreductible quotient of a ratio
	/// \return irreductible ratio
	void irreductible();

	
};
 
/// \brief convert a float in a ratio
/// \param x : float we want to convert
///\param nb_iter : number of iterations we want to do to find the ratio
/// \return the sum of the current ratio and the argument ratio
Ratio ConvertFloatRatio(float x, int nb_iter);