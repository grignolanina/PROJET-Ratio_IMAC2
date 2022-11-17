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

	//Ratio &operateur= (const Ratio &r);
	Ratio operator+(const Ratio &r);
	Ratio operator-(const Ratio &r);
	Ratio operator-();
	Ratio operator*(const Ratio &r);
	Ratio operator*(const int &value);

	public:
	/// \brief fonction to access to the numerator of a vector
	/// \return ratio.num() 
	int& num();

	/// \brief fonction to access to the denominator of a vector
	/// \return ratio.denom() 
	public:
	int& denom();

	
};