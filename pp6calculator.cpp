#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include "PP6MenuDay1.hpp"
#include "PP6MenuDay2.hpp"
#include "PP6MenuDay3.hpp"
#include "PP6MenuDay4.hpp"

int main()
{
  // Declare the variables
	char day(0);

	/*std::cout << "This program can perform a number of operations on user specified numbers. The available operations are: " << std::endl;
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
	std::cout << "M : Analyse muons from file" << std::endl;
	std::cout << "Day 3: " << std::endl;
	std::cout << "B : Boost a 4 vector along the z axis" << std::endl;*/

	while (true)
	{
      // Ask the user what they want to do
		std::cout << "Please enter the number of the day whose operations you would like to perform? " << std::endl;
		std::cout << "1) Day 1 - Basic operations" << std::endl;
std::cout << "2) Day 2 - Array operations" << std::endl;
std::cout << "3) Day 3 - 4 vector boost" << std::endl;
std::cout << "4) Day 4 - STL operations";
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

if (day == 'Q') {
	break;
	std::cout << "Thank you for using pp6calculator!" << std::endl;
	return 0;
}
else if (day == '1')
{
	pp6MenuDay1();
	continue;
}

else if (day=='2')
{
	pp6MenuDay2();
	continue;
}

else if(day=='3')
{
	pp6MenuDay3();
	continue;
}

else if(day=='4')
{
	pp6MenuDay4();
	continue;
}

else
{
	std::cerr << "[error] Day '" << day << "' not valid" << std::endl;
	continue;
}

}
}

