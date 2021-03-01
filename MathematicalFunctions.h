#pragma once
#include <string>

class MathematicalFunctions {
public:
	MathematicalFunctions(double stdev, double mean, double strike, std::string call_or_put) { m_stdev = stdev; m_mean = mean; m_strike = strike;  m_call_or_put = call_or_put; }
	double Pricing_Integral(double x);
	double Call_Def_Int();
private:
	double m_stdev;
	double m_mean;
	double m_strike;
	std::string m_call_or_put;
};