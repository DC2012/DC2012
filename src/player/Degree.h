/*-----------------------------------------------------------------------------
--	CLASS NAME:
--					Degree
--	CONSTRUCTOR:
--					Degree(double degree = 0)
--	DESTROCTOR:
--					Default
--	DATA MEMBERS:
--					private:
--						double degree_
--	FUNCTIONS:
--					public:
--						void rotate(double degree)
--						void setDegree(double degree)
--						double getDegree() const
--
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
		explicit Degree(double degree = 0);
		
/*-----------------------------------------------------------------------------
--	FUNCTION:
--				rotate
--	DATE:
--				March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--				Roger Fan
--	PROGRAMMER:
--				Roger Fan
--	INTERFACE:
--				void rotate(double degree)
--	RETURNS:
--				void
--	NOTES:
--				Call this function to "rotate" the degree_ variable.
--				Positive value will increase the degree_, negative otherwise.
--				This function will keep degree_ variable within the range of
--				0 to 360 (inclusive).
-----------------------------------------------------------------------------*/
		void rotate(double degree);
		
/*-----------------------------------------------------------------------------
--	FUNCTION:
--				setDegree
--	DATE:
--				March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--				Roger Fan
--	PROGRAMMER:
--				Roger Fan
--	INTERFACE:
--				void setDegree(double degree)
--	RETURNS:
--				void
--	NOTES:
--				This function sets the value for degree_ variable and calls
--				rotate(0) to make sure the value of degree_ is within valie
--				range.
-----------------------------------------------------------------------------*/
		void setDegree(double degree);
		
/*-----------------------------------------------------------------------------
--	FUNCTION:
--				getDegree
--	DATE:
--				March 9, 2012
--	REVISIONS:
--
--	DESIGNER:
--				Roger Fan
--	PROGRAMMER:
--				Roger Fan
--	INTERFACE:
--				double getDegree() const
--	RETURNS:
--				Returns degree_ variable.
--	NOTES:
-----------------------------------------------------------------------------*/
		double getDegree() const;
};

#endif
