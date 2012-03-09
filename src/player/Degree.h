/*----------------------------------------------------------------------
--	SORCE FILE:
--
--	CLASS NAME:
--
--	CONSTRUCTOR:
--
--	DESTROCTOR:
--
--	FUNCTIONS:
--
--	DATE:
--
--	REVISIONS:
--
--	DESIGNERS:
--
--	PROGRAMMER:
--
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
