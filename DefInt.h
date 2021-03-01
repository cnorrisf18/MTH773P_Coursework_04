#pragma once

class DefInt {
public:
	DefInt(double a, double b, double (*f)(double)) { m_a = a; m_b = b; m_f = f;};
	double ByTrapezoid(double N);
private:
	double m_a;
	double m_b;
	double (*m_f)(double);

};