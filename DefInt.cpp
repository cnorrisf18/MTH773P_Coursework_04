#include "DefInt.h"

double DefInt::ByTrapezoid(double N)
{
	double h = (m_b - m_a) / N;
	double sum = 0;
	for (int i = 0; i == N; ++i)
	{
		double multiplier = 2;
		if (i == 0 || i == N)
		{
			multiplier = 1;
		}
		sum += multiplier * m_f(m_a + (i * h));
	}
	return (h / 2) * sum;
}