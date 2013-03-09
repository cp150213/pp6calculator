#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH


int add(double a, double b, double& result);

int subtract(double a, double b, double& result);

int divide(double a, double b, double& result);

int multiply(double a, double b, double& result);

int intercept(double a, double b, double& result);

int quadratic(double a, double b, double c, double& root1, double& root2);

double length3(double a, double b, double c, double& v3Length);

double length4(double t, double a, double b, double c, double& v4Length);

double inv_mass(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2, double& invariantMass);

int swap(double& a, double& b);

int swap(int& a, int& b);

int bubble(double *arr, int size);

int sumVectors(double *x, double *y, double *z, int size, double &sumX, double &sumY, double &sumZ);

int getMeanAndStdDev(double *x, int size, double& mean, double& stddev);

int associative_sort(double *arr, int *index, int size);

double getRandom();

void printArray(double *arr, int size);

double getNumber();

std::string getString();

#endif // PP6CALCULATOR_PP6MATH_HH