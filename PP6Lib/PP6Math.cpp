#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include "PP6Math.hpp"

int add(double a, double b, double& result)
{
	result = a + b;
	return 0;
}

int subtract(double a, double b, double& result)
{
	result = a - b;
	return 0;
}

int divide(double a, double b, double& result)
{
	if (b == 0)
	{
		return 1;
	}

	result = a / b;
	return 0;
}

int multiply(double a, double b, double& result)
{
	result = a * b;
	return 0;
}

int intercept(double a, double b, double& result)
{
	return divide(-b, a, result);
}

int quadratic(double a, double b, double c, double& root1, double& root2)
{

	if (a == 0)
	{
		return 1;
	}

	double discriminant(b*b - 4*a*c);

  // Only allow real roots
	if (discriminant < 0)
	{
		return 2;
	}

	root1 = (-b + sqrt(discriminant)) / (2*a);
	root2 = (-b - sqrt(discriminant)) / (2*a);

	return 0;
}

double length3(double a, double b, double c, double& v3Length)
{
	v3Length = sqrt(a*a + b*b + c*c);
	return 0;
}

double length4(double t, double a, double b, double c, double& v4Length)
{
	double spaceLength(0);
	if (length3(a, b, c, spaceLength))
	{
		return 1;
	}

  // Only time-like vectors allowed
	if ((t*t) < (spaceLength*spaceLength))
	{
		return 2;
	}

	v4Length = sqrt(t*t - spaceLength*spaceLength);
	return 0;
}

double inv_mass(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2, double& invariantMass)
{
	double tot_E(E1 + E2);
	double tot_px(px1 + px2);
	double tot_py(py1 + py2);
	double tot_pz(pz1 + pz2);

	if (length4(tot_E, tot_px, tot_py, tot_pz, invariantMass))
	{
		return 1;
	}
	return 0;
}

int swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
	return 0;
}

int swap(int& a, int& b)
{
  int tmp(a);
  a = b;
  b = tmp;
  return 0;
}

int bubble(double *arr, int size)
{
	bool done(true);

	while (true)
	{
		done = true;

		for (int i = 0; i < size-1; ++i)
		{
			if (arr[i] < arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				done = false;
			}
		}

		if (done)
		{
			break;
		}
	}
	return 0;
}

double getRandom()
{
  return rand() % 100;
}

int getMeanAndStdDev(double *x, int size, double& mean, double& stddev)
{
  // Check for valid pointer
  if (!x) return 1;

  // loop and compute mean
  mean = 0;
  for (int i(0); i < size; ++i)
  {
    mean += x[i];
  }

  mean /= size;

  // now the standard deviation
  stddev = 0;
  for (int i(0); i < size; ++i)
  {
    stddev += (x[i] - mean) * (x[i] - mean);
  }

  stddev /= size;
  stddev = sqrt(stddev);

  return 0;
}


int sumVectors(double *x, double *y, double *z, int size,
               double &sumX, double &sumY, double &sumZ)
{
  // check for valid pointers
  if ((!x) || (!y) || (!z))
  {
    return 1;
  }

  sumX = 0;
  sumY = 0;
  sumZ = 0;

  for (int i(0); i < size; ++i)
  {
    sumX += x[i];
    sumY += y[i];
    sumZ += z[i];
  }

  return 0;
}

int associative_sort(double *arr, int *index, int size)
{
  double *arr_t = new double[size];
  for (int i(0); i < size; i++)
  {
    arr_t[i] = arr[i];
  }

  bool done(true);

  while (true)
  {
    done = true;

    for (int i(0); i < size-1; ++i)
    {
      if (arr_t[i] < arr_t[i+1])
      {
        swap(index[i], index[i+1]);
        swap(arr_t[i], arr_t[i+1]);
        done = false;
      }
    }
    if (done)
    {
      break;
    }
  }

  delete [] arr_t;
  return 0;
}

void printArray(double *arr, int size)
{
	std::cout << "[array:" << arr << "]{";
	for (int i = 0; i < size - 1; ++i)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[size - 1] << "}" << std::endl;
}

double getNumber()
{
	double res(0);

	std::cin >> res;

	while (!std::cin)
	{
		std::cout << "Error in input. Please re-enter >> ";

      // clear the buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      // retry
		std::cin >> res;
	}

	return res;
}

std::string getString()
{
  std::string res;

  std::cin >> res;

  while (!std::cin)
  {
    std::cout << "Error in input. Please re-enter >> ";

    // clear the buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // retry
    std::cin >> res;
  }

  return res;
}
