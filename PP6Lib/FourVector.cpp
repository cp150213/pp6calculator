#include <cmath>
#include <iostream>
#include "FourVector.hpp"
#include "ThreeVector.hpp"


const double FourVector::c(1);

FourVector::FourVector()
	: t(0.0), x(), s(0.0)
{
}

FourVector::FourVector(const FourVector& other)
	: t(other.getT()), x(other.getThreeVector()), s(other.interval())
{
}

FourVector::FourVector(const double t_, const ThreeVector& x_)
	: t(t_), x(x_)
{
	compute_interval();
}

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

FourVector& FourVector::operator*=(const double rhs)
{
	t *= rhs;
	x *= rhs;
	compute_interval();
	return *this;
}

FourVector& FourVector::operator/=(const double rhs)
{
	t /= rhs;
	x /= rhs;
	compute_interval();
	return *this;
}

void FourVector::compute_interval() 
{
	//interval s squared = (ct)^2 - (x^2 + y^2 + z^2)
	s = c*c*t*t - x.length() * x.length();
}

int FourVector::boost(const double v)
{

	if ( v >= c ) 
	{
		return -1; 
	}

	double gamma = 1.0 / sqrt(1.0 - (v * v)/(c*c));
	double t_ = gamma * (t - ((v * v)/(c*c))*x.getZ());
	double z_ = gamma * (x.getZ() - ((v * v)/(c*c))*t);

	t = t_;
	x.setZ(z_);

	return 0; 
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

FourVector operator*(const FourVector& lhs, const double rhs)
{
	FourVector temp(lhs);
	temp *= rhs;
	return temp;
}

FourVector operator*(const double lhs, const FourVector& rhs)
{
	FourVector temp(rhs);
	temp *= lhs;
	return temp;
}

FourVector operator/(const FourVector& lhs, const double rhs)
{
	FourVector temp(lhs);
	temp /= rhs;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const FourVector& vec)
{
	out << "[" << vec.getT() << ", " << vec.getThreeVector() << "]";
	return out;
}

std::istream& operator>>(std::istream& in, FourVector& vec)
{
	in >> vec.t >> vec.x;
	return in;
}

double contraction(const FourVector& lhs, const FourVector& rhs)
{
	return lhs.getT() * rhs.getT() - lhs.getThreeVector().length() * rhs.getThreeVector().length();
}
