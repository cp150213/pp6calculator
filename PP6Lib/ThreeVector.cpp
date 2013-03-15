#include <cmath>
#include <iostream>
#include "ThreeVector.hpp"

const double ThreeVector::Pi = 3.14159265;

ThreeVector::ThreeVector()
	: x(0.0), y(0.0), z(0.0)
{
	compute_length();
}

ThreeVector::ThreeVector(const ThreeVector& other)
	: x(other.getX()), y(other.getY()), z(other.getZ())
{
	compute_length();
}

ThreeVector::ThreeVector(const double x_, const double y_, const double z_)
	: x(x_), y(y_), z(z_)
{
	compute_length();
}

ThreeVector& ThreeVector::operator=(const ThreeVector& other)
{
	if ( this != &other ) 
	{
		x = other.getX();
		y = other.getY();
		z = other.getZ();
		compute_length();
	}
	return *this;
}

ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs)
{
	x += rhs.getX();
	y += rhs.getY();
	z += rhs.getZ();
	compute_length();
	return *this;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs)
{
	x -= rhs.getX();
	y -= rhs.getY();
	z -= rhs.getZ();
	compute_length();
	return *this;
}

ThreeVector& ThreeVector::operator*=(const double rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	compute_length();
	return *this;
}

ThreeVector& ThreeVector::operator/=(const double rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	compute_length();
	return *this;
}

void ThreeVector::setX(const double x_)
{
	x = x_;
	compute_length();
}

void ThreeVector::setY(const double y_)
{
	y = y_;
	compute_length();
}

void ThreeVector::setZ(const double z_)
{
	z = z_;
	compute_length();
}

double ThreeVector::getTheta() const
{
	double perp = sqrt(x*x + y*y);
	return ( x == 0.0 && y == 0.0 && z == 0.0 ) ? 0.0 : arctan(perp, z);
}

double ThreeVector::getPhi() const
{
	return (x == 0.0 && y == 0.0 && z == 0.0 ) ? 0.0 : arctan(y, x);
}

double arctan(double y, double x)
{
	if ( x != 0 ) return atan2(y, x);
	if ( y == 0 ) return 0;
	if ( y > 0 ) return ThreeVector::Pi / 2.0;
	else return -ThreeVector::Pi / 2.0;
}

void ThreeVector::setR(const double r)
{
	double theta = getTheta();
	double phi = getPhi();
	x = r * sin(theta) * sin(phi);
	y = r * sin(theta) * cos(phi);
	z = r * cos(theta);
	compute_length();
}

void ThreeVector::setTheta(const double theta)
{
	double phi = getPhi();
	x = len * sin(theta) * cos(phi);
	y = len * sin(theta) * sin(phi);
	z = len * cos(theta);
	compute_length();
}

void ThreeVector::setPhi(const double phi)
{
	double perp = sqrt(x*x + y*y);
	x = perp * cos(phi);
	y = perp * sin(phi);
	// z unchanged
	compute_length();
}

void ThreeVector::rotateX(const double angle)
{
  const double oldy = y_;
  const double oldz = z_;
  y_ = cos(angle)*oldy - sin(angle)*oldz;
  z_ = sin(angle)*oldy + cos(angle)*oldz;
}

void ThreeVector::rotateY(const double angle)
{
  const double oldx = x_;
  const double oldz = z_;
  z_ = cos(angle)*oldz - sin(angle)*oldx;
  x_ = sin(angle)*oldz + cos(angle)*oldx;
}

void ThreeVector::rotateZ(const double angle)
{
  const double oldx = x_;
  const double oldy = y_;
  x_ = cos(angle)*oldx - sin(angle)*oldy;
  y_ = sin(angle)*oldx + cos(angle)*oldy;
}

void ThreeVector::compute_length()
{
	len = sqrt(x*x + y*y + z*z);
}

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp += rhs;
	return temp;
}

ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp -= rhs;
	return temp;
}

ThreeVector operator*(const ThreeVector& lhs, const double rhs)
{
	ThreeVector temp(lhs);
	temp *= rhs;
	return temp;
}

ThreeVector operator*(const double lhs, const ThreeVector& rhs)
{
	ThreeVector temp(rhs);
	temp *= lhs;
	return temp;
}

ThreeVector operator/(const ThreeVector& lhs, const double rhs)
{
	ThreeVector temp(lhs);
	temp /= rhs;
	return temp;
}

ThreeVector operator-(const ThreeVector& vec)
{
	return ThreeVector(-vec.getX(), -vec.getY(), -vec.getZ());
}

std::istream& operator>>(std::istream& in, ThreeVector& vec)
{
	in >> vec.x >> vec.y >> vec.z;
	vec.compute_length();
	return in;
}

std::ostream& operator<<(std::ostream& out, const ThreeVector& vec)
{
	out << "(" << vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << ")";
	return out;
}

double scalarProduct(const ThreeVector& a, const ThreeVector& b)
{
	return a.getX() * b.getX() + a.getY() * b.getY()  + a.getZ() * b.getZ();
}

