#include <iostream>
#include <cmath>
#include <PP6Math.hpp>
#include <PP6MenuDay3.hpp>
#include <limits>
#include "FourVector.hpp"


void pp6MenuDay3()
{
  // Declare the variables
	char op('\0');
	
	while (true)
	{
		std::cout << "Enter the operation you would like to perform (B), or type Q to quit:" << std::endl;

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

		else if (op == 'B')
		{
			double v(0.0);
			double x(0.0), y(0.0), z(0.0), t(0.0);

			std::cout << "Boosting a 4 vector\n";
			std::cout << "Enter the time coordinate: " << std::endl;
			std::cin >> t;
			std::cout << "Enter the x coordinate: " << std::endl;
			std::cin >> x;
			std::cout << "Enter the y coordinate: " << std::endl;
			std::cin >> y;
			std::cout << "Enter the z coordinate: " << std::endl;
			std::cin >> z;
			std::cout << "Enter a velocity (as a fraction of the speed of light, c) to boost along z-axis: " << std::endl;
			std::cin >> v;

			FourVector vec(t, x, y, z);

			std::cout << "The space-time interval is " << vec.interval() << std::endl;


			int status = vec.boost(v);
			if ( status != 0 )
			{
				std::cerr << "Velocity cannot be greater than the speed of light!\n";
			}
			else
			{
				std::cout << "Boosted vector: " << vec << std::endl;
			}


			continue;
		}
	}
}

