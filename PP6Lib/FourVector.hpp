#ifndef PP6CALCULATOR_FOURVECTOR_HPP
#define PP6CALCULATOR_FOURVECTOR_HPP

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

		double interval() const { return s; } 

		int boost(const double v); 
	
		double getT() const { return t; }
		double getX() const { return x; }
		double getY() const { return y; }
		double getZ() const { return z; }

		void setT(const double t_) { t = t_; compute_interval(); }
		void setX(const double x_) { x = x_; compute_interval(); }
		void setY(const double y_) { y = y_; compute_interval(); }
		void setZ(const double z_) { z = z_; compute_interval(); }
	private:
		static const double c;

		double t;
		double x;
		double y;
		double z;
		double s; 

		void compute_interval();
};

std::istream& operator>>(std::istream& in, FourVector& vec); 
std::ostream& operator<<(std::ostream& out, const FourVector& vec); 
FourVector operator+(const FourVector& lhs, const FourVector& rhs); 
FourVector operator-(const FourVector& lhs, const FourVector& rhs); 

#endif // PP6CALCULATOR_FOURVECTOR_HPP
