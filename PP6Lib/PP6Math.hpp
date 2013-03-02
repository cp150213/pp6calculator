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

int bubble(double *arr, int size);

double CalculateMean(double *arr, int size);

double CalculateVariance(double *arr, int size);

double GetStandardDeviation(double *arr, int size);

double randEnergy(double *arr, int size, double& Emean, double& Estdev);

void printArray(double *arr, int size);

double getNumber();

#endif // PP6CALCULATOR_PP6MATH_HH