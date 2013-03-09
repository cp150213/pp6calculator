#include <cmath>
#include <iostream>
#include "FourVector.hpp"


const double FourVector::c(2.998E8);

FourVector& FourVector::operator=(const FourVector& other)
{
	if ( this != &other ) 
	{
		t = other.getT();
		x = other.getX();
		y = other.getY();
		z = other.getZ();
		s = other.interval();
	}
	return *this;
}

std::istream& operator>>(std::istream& in, FourVector& vec) 
{
	double x(0.0), y(0.0), z(0.0), t(0.0);
	in >> t >> x >> y >> z;
	vec.setT(t);
	vec.setX(x);
	vec.setY(y);
	vec.setZ(z);
	return in;
}

std::ostream& operator<<(std::ostream& out, const FourVector& vec)
{
	out << "(" << vec.getT() << ", " << vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << ")";
	return out;
}

FourVector& FourVector::operator+=(const FourVector& rhs)
{
	t += rhs.getT();
	x += rhs.getX();
	y += rhs.getY();
	z += rhs.getZ();
		compute_interval();
	return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs)
{
	t -= rhs.getT();
	x -= rhs.getX();
	y -= rhs.getY();
	z -= rhs.getZ();
		compute_interval();
	return *this;
}

FourVector operator+(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp += rhs;
	return temp;
}

FourVector operator-(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp -= rhs;
	return temp;
}

void FourVector::compute_interval() 
{
	//interval s squared = (ct)^2 - (x^2 + y^2 + z^2)
	s = c*c*t*t - (x*x + y*y + z*z);
}

int FourVector::boost(const double v)
{

	if ( v >= c ) 
	{
		return 1; 
	}

	double gamma = 1.0 / sqrt(1.0 - (v * v)/(c*c));
	double t_ = gamma * (t - ((v * v)/(c*c))*z);
	double z_ = gamma * (z - ((v * v)/(c*c))*t);

	t = t_;
	z = z_;

	return 0; 
}
