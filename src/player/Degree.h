/*----------------------------------------------------------------------
--	CLASS NAME:
--					Degree
--	CONSTRUCTOR:
--					Degree(int degree)
--	DESTROCTOR:
--					Default
--	FUNCTIONS:
--					void rotate(int degree)
--					void setDegree(int degree)
--					int getDegree()
--	DATE:
--					March 9, 2012
--	REVISIONS:
--					March 14, 2012
--						- switched to using floating-point type, double
--
--	DESIGNER:
--					Roger Fan
--	PROGRAMMER:
--					Roger Fan
--	NOTES:
----------------------------------------------------------------------*/
#ifndef DEGREE_H_
#define DEGREE_H_

class Degree
{
	private:
		double degree_;
	public:
		explicit Degree(double degree);
		void rotate(double degree);
		void setDegree(double degree);
		double getDegree()const;
};

#endif
