#include <iostream>
#include <cmath>
#include <PP6Math.hpp>
#include <PP6MenuDay1.hpp>
#include <limits>



void pp6MenuDay1()
{
  // Declare the variables
	double resultCode(0), answerHolder(0), answerHolder2(0);
	char op('\0');
	double a(0), b(0), c(0), t(0);

	while (true)
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
			break;
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
				E2, px2, py2, pz2,
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
}
