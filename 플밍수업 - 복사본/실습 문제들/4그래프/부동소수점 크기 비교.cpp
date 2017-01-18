#include <float.h>

bool isEq(double a, double b)
{
	return (fabs(a - b) < (DBL_EPSILON * fabs(a + b)));
}