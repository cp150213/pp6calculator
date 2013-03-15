#ifndef PP6CALCULATOR_THREEVECTOR_HPP
#define PP6CALCULATOR_THREEVECTOR_HPP

#include <iosfwd> 

class ThreeVector {
public:
  // Constructors
  ThreeVector();
  ThreeVector(const ThreeVector& other);
  ThreeVector(double x_, double y_, double z_);

  // Copy assignment operator
  ThreeVector& operator=(const ThreeVector& other);

  // Member operators
  ThreeVector& operator+=(const ThreeVector& rhs);
  ThreeVector& operator-=(const ThreeVector& rhs);
  ThreeVector& operator*=(const double rhs);
  ThreeVector& operator/=(const double rhs);
	
  // Friend operators
  friend std::istream& operator>>(std::istream& in, ThreeVector& vec);

  // Accessors / setters
  double getX() const { return x; }
  double getY() const { return y; }
  double getZ() const { return z; }

  void setX(const double x_);
  void setY(const double y_);
  void setZ(const double z_);

  double getR() const { return len; }
  double getTheta() const;
  double getPhi() const;

  void rotateX(const double angle);

  void rotateY(const double angle);

  void rotateZ(const double angle);


  void setR(const double r);
  void setTheta(const double theta);
  void setPhi(const double phi);

  // Member functions
  double length() const { return len; }

  // statics
  static const double Pi;

private:
  // Private member functions
  void compute_length();
		
  // Member variables
  double x;
  double y;
  double z;
  double len;

};

// Free operators
ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator*(const ThreeVector& lhs, const double rhs);
ThreeVector operator*(const double lhs, const ThreeVector& rhs);
ThreeVector operator/(const ThreeVector& lhs, const double rhs);
ThreeVector operator-(const ThreeVector& vec);

// Streaming operators
std::ostream& operator<<(std::ostream& out, const ThreeVector& vec);

// Free functions
double scalarProduct(const ThreeVector& a, const ThreeVector& b);

// arctangent
double arctan(double y, double x);

#endif //PP6CALCULATOR_THREEVECTOR_HPP
