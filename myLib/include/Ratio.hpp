#pragma once

/// \class Ratio
/// \brief class defining a rational for linear algebra operations
class Ratio {

	public:
	// /// \brief constructor from a num and a denom and default constructor
	// /// \param num denom : the num of the ratio (optional)
	// /// \param denom denom : the denum of the ratio (optional)
	// Ratio(int num = 0, int denom = 1);
	/// \brief constructor from a num and a denom and default constructor
	/// \param num denom : the num of the ratio (optional)
	/// \param denom denom : the denum of the ratio (optional)
	Ratio();


	/// \brief constructor from a num and a denom and default constructor
	/// \param num denom : the num of the ratio
	/// \param denom denom : the denum of the ratio
	Ratio(int num, int denom);


	/// \brief copy-constructor
	/// \param r : the source ratio to be copied
	Ratio(const Ratio & r);


	/// \brief destructor
	~Ratio() = default;

	
	private:
	int m_num;
	int m_denom;

	public:
	//Ratio &operateur= (const Ratio &r);

	/// \brief add a ratio to *this
	/// \param r : ratio to add to the calling ratio
	/// \return the sum of the current ratio and the argument ratio
	Ratio operator+(const Ratio &r);

	/// \brief substract a ratio to *this
	/// \param r : ratio to substract to the calling ratio
	/// \return the substract of the current ratio and the argument ratio
	Ratio operator-(const Ratio &r);

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

	/// \brief fonction to set to the numerator of a vector
	/// \return ratio.num() 
	int& setNum();

	/// \brief fonction to set to the denominator of a vector
	/// \return ratio.denom() 
	int& setDenom();

	/// \brief fonction to access to the numerator of a vector
	/// \return ratio.num() 
	const int& getNum()const;

	/// \brief fonction to access to the denominator of a vector
	/// \return ratio.denom() 
	const int& getDenom()const;

	/// \brief fonction which gives the irreductible quotient of a ratio
	/// \return pgcd()
	void pgcd();

	
};