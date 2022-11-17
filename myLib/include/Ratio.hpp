#pragma once

/// \class Ratio
/// \brief class defining a rational for linear algebra operations
class Ratio {
	public:
	//constructeur
	Ratio(int num, int denom);
	int m_num;
	int m_denom;

	//Ratio &operateur= (const Ratio &r);
	Ratio operator+(const Ratio &r);
	Ratio operator-(const Ratio &r);
	Ratio operator-();
	Ratio operator*(const Ratio &r);
	Ratio operator*(const int &value);


	private:
	//denom et num
	// int m_num;
	// int m_denom;


};