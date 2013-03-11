#ifndef PP6CALCULATOR_FOURVECTOR_HPP
#define PP6CALCULATOR_FOURVECTOR_HPP

#include <iosfwd>
#include "ThreeVector.hpp"

class FourVector {
	public:

		FourVector() {t=0;x=0;y=0;z=0;}

		FourVector(const FourVector& other) 
			: t(other.getT()), x(other.getX()), y(other.getY()), z(other.getZ()), s(other.interval())
			{ }

		FourVector(const double t_, const double x_, const double y_, const double z_)
			: t(t_), x(x_), y(y_), z(z_)
			{ compute_interval(); }

		FourVector& operator=(const FourVector& other); 
		
		FourVector& operator+=(const FourVector& rhs); 
		FourVector& operator-=(const FourVector& rhs);

		friend std::istream& operator>>(std::istream& in, FourVector& vec);

		double interval() const { return s; } 

		int boost(const double v); 
	
		double getT() const { return t; }
		const ThreeVector& getThreeVector() const { return x; }
		double getX() const { return x.getX(); }
		double getY() const { return x.getY(); }
		double getZ() const { return x.getZ(); }

		void setT(double t_);
		void setThreeVector(const ThreeVector& x_);
		void setX(const double x_);
		void setY(const double y_);
		void setZ(const double z_);
	private:
		static const double c;

		double t;
		ThreeVector x;
		double s; 

		void compute_interval();
};

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
FourVector operator*(const FourVector& lhs, const double rhs);
FourVector operator*(const double lhs, const FourVector& rhs);
FourVector operator/(const FourVector& lhs, const double rhs);

std::ostream& operator<<(std::ostream& out, const FourVector& vec);

double contraction(const FourVector& lhs, const FourVector& rhs);

#endif // PP6CALCULATOR_FOURVECTOR_HPP
