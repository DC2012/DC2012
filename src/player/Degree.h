/*-----------------------------------------------------------------------------
--	CLASS NAME:
--					Degree
--	CONSTRUCTOR:
--					explicit Degree(int degree = 0)
--	DESTROCTOR:
--					Default
--	FUNCTIONS:
--					public:
--						void rotate(int degree)
--						void setDegree(int degree)
--						int getDegree()
--
--					private:
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
-----------------------------------------------------------------------------*/
#ifndef DEGREE_H_
#define DEGREE_H_

class Degree
{
	private:
		double degree_;
	public:
/*-----------------------------------------------------------------------------
--	FUNCTION:
--
--	DATE:
--
--	REVISIONS:
--
--	DESIGNER:
--
--	PROGRAMMER:
--
--	INTERFACE:
--
--	RETURNS:
--
--	NOTES:
-----------------------------------------------------------------------------*/
		explicit Degree(double degree = 0);
		void rotate(double degree);
		void setDegree(double degree);
		double getDegree()const;
};

#endif
