#include "MathematicalFunctions.h"
#include <cmath>
#include "DefInt.h"

double MathematicalFunctions::Pricing_Integral(double x)
{
	//pdf of the function
	double pi = 4.0 * atan(1.0);
	double first_part = 1 / (x * m_stdev * sqrt(2 * pi));
	double second_part = exp(-pow(log(x) - m_mean, 2) / (2 * pow(m_stdev, 2)));
	double pdf = first_part * second_part;
	//payoff of the function
	double payoff = 0;
	if (m_call_or_put == "CALL")
	{
		if (x - m_strike > 0)
		{
			payoff = x - m_strike;
		}
	}
	else if (m_call_or_put == "PUT")
	{
		if (m_strike - x > 0)
		{
			payoff = m_strike - x;
		}
	}
	else
	{
		return 0;
	}
	return payoff * pdf;
}
/*
double MathematicalFunctions::Call_Def_Int()
{
	double *fptr = Pricing_Integral;
	DefInt di1(0.0, 1000000.0, Pricing_Integral);
	return di1.ByTrapezoid(400);
}
*/