#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>


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

double CalculateMean(double *arr, int size)
{
	double sum = 0;
	for(int i = 0; i < size-1; i++)
		sum += arr[i];
	return (sum / size);
}

double CalculateVariance(double *arr, int size)
{
	double mean = CalculateMean(arr, size);

	double temp = 0;
	for(int i = 0; i < size-1; i++)
	{
		temp += (arr[i] - mean) * (arr[i] - mean) ;
	}
	return temp / size;
}

double GetStandardDeviation(double *arr, int size)
{
	return sqrt(CalculateVariance(arr, size));
}

double randEnergy(double *arr, int size, double& Emean, double& Estdev)
{
	
	for(int i=0; i<size-1; i++)
	{
		double px = rand()%100;
		double py = rand()%100;
		double pz = rand()%100;
		double m = rand()%100;
		double momentum;
		if (length3(px, py, pz, momentum))
		{
			return 1;
		}

		arr[i] = sqrt(momentum*momentum + m*m);
	}

	Emean = CalculateMean(arr, size);
	Estdev = GetStandardDeviation(arr,size);
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

//----------------------------------------------------------------------
// Main program
//
int main()
{
  // Declare the variables
	double resultCode(0), answerHolder(0), answerHolder2(0);
	char op('\0');
	double a(0), b(0), c(0), t(0);
	char day(0);

	std::cout << "This program can perform a number of operations on user specified numbers. The available operations are: " << std::endl;
	std::cout << "Day 1: " << std::endl;
	std::cout << "+ : Addition" << "\t" << "- : Subtraction" << std::endl;
	std::cout << "/ : Division" << "\t" << "* : Multiplication" << std::endl;
	std::cout << "x : Find the x intercept of a straight line of form y = mx + c" << std::endl;
	std::cout << "q : Find the roots of a quadratic equation" << std::endl;
	std::cout << "l : Find the length of a vector" << std::endl;
	std::cout << "m : Find the invariant mass of two particles" << std::endl;
	std::cout << "Day 2: " << std::endl;
	std::cout << "s : Swap two numbers" << std::endl;
	std::cout << "b : Perform a bubble sort on an array of 5 numbers" << std::endl;
	std::cout << "E : Generate random energies and 3 momenta and get the mean energy and its standard deviation" << std::endl;

	while (true)
	{
      // Ask the user what they want to do
		std::cout << "Please enter the number for the days operations that you would like to perform? " << std::endl;
		std::cout << "1) Day 1" << std::endl;
std::cout << "2) Day 2" << std::endl;
std::cout << "Or type Q to quit" << std::endl;
std::cin >> day;

if(!std::cin)
{
	std::cerr << "[error] Error in input" << std::endl;

	  // clear the buffer
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	continue;
}

if (day == 'Q') break;
else if (day=='1')
{
	std::cout << "Enter the operation you would like to perform (+, -, *, /, x, q, l, m), or type Q to quit:" << std::endl;

	std::cin >> op;

	  // check for bad input
	if(!std::cin)
	{
		std::cerr << "[error] Error in input" << std::endl;

	      // clear the buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue;
	}

	  // Handle menu operation
	if (op == 'Q')
	{
		continue;
	}
	else if((op == '+') || (op == '-') || (op == '*') || (op == '/'))
	{
	      // Arithmetic operations, so ask for two numbers from the user
		std::cout << "Enter the first number: ";
		a = getNumber();
		std::cout << "Enter the second number: ";
		b = getNumber();

	      // calculate the result
		if (op == '+')
		{
			resultCode = add(a, b, answerHolder);
		}
		else if (op == '-')
		{
			resultCode = subtract(a, b, answerHolder);
		}
		else if (op == '*')
		{
			resultCode = multiply(a, b, answerHolder);
		}
		else if (op == '/')
		{
			resultCode = divide(a, b, answerHolder);
		}

	}
	else if (op == 'x')
	{
	      // Ask for two numbers from the user
		std::cout << "Enter the gradient: ";
		a = getNumber();
		std::cout << "Enter the y intercept: ";
		b = getNumber();
		resultCode = intercept(a, b, answerHolder);
	}
	else if (op == 'q')
	{
	      // Solve ax^2 + bx + c = 0
	      // Ask user for quadratic coefficients
		std::cout << "Enter the coefficient of the squared term: ";
		a = getNumber();
		std::cout << "Enter the coefficient of the linear term: ";
		b = getNumber();
		std::cout << "Enter the value of the constant: ";
		c = getNumber();

		resultCode = quadratic(a, b, c, answerHolder, answerHolder2);
	}
	else if (op == 'l')
	{
		std::cout << "This program can find the length of a 3 or a 4 vector, enter the size of vector you would like the length of: " << std::endl;
		int v;
		v = getNumber();
		if (v==3){
		// Calculate sqrt(x^2+y^2+z^2)

		// Ask user for vector components
			std::cout << "Enter the x-component: ";
			a = getNumber();
			std::cout << "Enter the y-component: ";
			b = getNumber();
			std::cout << "Enter the z-component: ";
			c = getNumber();

			resultCode = length3(a, b, c, answerHolder);
		}


		else if (v == 4)
		{
		  // Calculate sqrt(t^2 - (x^2+y^2+z^2))


		  // Ask user for vector components
			std::cout << "Enter the x-component: ";
			a = getNumber();
			std::cout << "Enter the y-component: ";
			b = getNumber();
			std::cout << "Enter the z-component: ";
			c = getNumber();
			std::cout << "Enter the t-component: ";
			t = getNumber();

			resultCode = length4(t, a, b, c, answerHolder);
		}
		else std::cout << "I said a 3 or a 4 vector, what do you think you're doing?" << std::endl;
	}

	else if (op == 'm')
	{
		double E1(0), px1(0), py1(0), pz1(0), E2(0), px2(0), py2(0), pz2(0);

	      // Ask for eight numbers from the user
		std::cout << "Enter the px value for the first particle: ";
		px1 = getNumber();
		std::cout << "Enter the py value for the first particle: ";
		py1 = getNumber();
		std::cout << "Enter the pz value for the first particle: ";
		pz1 = getNumber();
		std::cout << "Enter the E value for the first particle: ";
		E1 = getNumber();

		std::cout << "Enter the px value for the second particle: ";
		px2 = getNumber();
		std::cout << "Enter the py value for the second particle: ";
		py2 = getNumber();
		std::cout << "Enter the pz value for the second particle: ";
		pz2 = getNumber();
		std::cout << "Enter the E value for the second particle: ";
		E2 = getNumber();

		resultCode = inv_mass(E1, px1, py1, pz1,
			E1, px1, py1, pz1,
			answerHolder);
	}

	else
	{
		std::cerr << "[error] Operation '" << op << "' not valid" << std::endl;
		continue;
	}
	if (resultCode)
	{
		std::cerr << "[error] Operation '" << op << "' returned a non-zero code '" << resultCode << "'. Please check parameters." << std::endl;
		continue;
	}

	  // if all is well, print the result(s)
	if (op == 'q')
	{
		std::cout << "[result]: first root: " << answerHolder << std::endl;
		std::cout << "[result]: second root: " << answerHolder2 << std::endl;
		continue;
	}
	else
	{
		std::cout << "[result]: " << answerHolder << std::endl;
		continue;
	}
}


else if (day=='2')
{
	std::cout << "Enter the operation you would like to perform (s, b, E), or type Q to quit:" << std::endl;

	std::cin >> op;

      // check for bad input
	if(!std::cin)
	{
		std::cerr << "[error] Error in input" << std::endl;

	  // clear the buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		continue;
	}

      // Handle menu operation
	if (op == 'Q')
	{
		continue;
	}

	else if (op == 's')
	{
		std::cout << "Enter the first number: ";
		a = getNumber();
		std::cout << "Enter the second number: ";
		b = getNumber();
		swap(a, b);
		std::cout << "Swapping " << a << " and " << b << " gives you: " << std::endl;
		std::cout << a << " and " << b << std::endl;
		continue;
	}

	else if (op == 'b')
	{
		int arraySize(0);
		std::cout << "Enter the size of the array: ";
		arraySize = getNumber();
		if ((arraySize > 0) && (arraySize < 11))
		{
			double *currentArray = new double[arraySize];
			for (int i = 0; i < arraySize; ++i)
			{
				std::cout << "Enter the value of element " << i << ": ";
				currentArray[i] = getNumber();
			}

			std::cout << "Array before sorting: " << std::endl;
			printArray(currentArray, arraySize);

			bubble(currentArray, arraySize);

			std::cout << "Array after sorting: " << std::endl;
			printArray(currentArray, arraySize);

			delete [] currentArray;
			continue;
		}
		else {
			std::cerr << "[error]: Array size must be between 1 and 10" << std::endl;
		}
	}

	else if (op == 'E')
	{
		int arraySize(0);
		std::cout << "Enter the number of random energies wanted: ";
		arraySize = getNumber();
		if (arraySize > 0)
		{
			double *EArray = new double[arraySize];
			resultCode = randEnergy(EArray, arraySize, answerHolder, answerHolder2);
			std::cout << "Mean Energy: " << answerHolder << std::endl;
			std::cout << "Standard deviation: " << answerHolder2 << std::endl;
			continue;
		}
		else {
			std::cerr << "[error]: Array size must be greater than 0" << std::endl;
		}
	}

	else
	{
		std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
		continue;
	}

      // Handle any errors
	if (resultCode)
	{
		std::cerr << "[error] Operation '" << op << "' returned a non-zero code '" << resultCode << "'. Please check parameters." << std::endl;
		continue;
	}
}

else
{
	std::cerr << "[error] Day '" << day << "' not valid" << std::endl;
	continue;
}


std::cout << "Thank you for using pp6calculator!" << std::endl;
return 0;
}
}

