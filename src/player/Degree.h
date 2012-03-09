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
		int degree_;
	public:
		explicit Degree(int degree);
		void rotate(int degree);
		void setDegree(int degree);
		int getDegree();
};

#endif
