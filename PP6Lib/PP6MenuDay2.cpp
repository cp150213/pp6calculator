#include <iostream>
#include <cmath>
#include <PP6Math.hpp>
#include <PP6MenuDay2.hpp>
#include <limits>
#include "PP6Energy.hpp"
#include "PP6Muon.hpp"


void pp6MenuDay2()
{
  // Declare the variables
	double resultCode(0);
	char op('\0');
	double a(0), b(0);

	while (true)
	{
		{
			std::cout << "Enter the operation you would like to perform:" << std::endl;
			std::cout << "1) : Swap two numbers" << std::endl;
	std::cout << "2) : Perform a bubble sort on an array of 5 numbers" << std::endl;
	std::cout << "3) : Generate random energies and 3 momenta and get the mean energy and its standard deviation" << std::endl;
	std::cout << "4) : Analyse muons from file" << std::endl;
	std::cout << "Or type Q to quit." << std::endl;

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

			else if (op == '1')
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

			else if (op == '2')
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

	  //Produce a (user defined) number of random energies and 3 momenta and calculate mean energy and its standard deviation
			else if (op == '3')
			{
				resultCode = PP6Energy();
				continue;
			}
			else if (op == '4')
			{
				resultCode = PP6Muon();
				continue;
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


	}
}