#include <iostream>
#include <climits>
#include <cmath>

double add(double a, double b)
{
  return a+b;
}

double subtract( double a, double b)
{
  return a-b;
}

double divide( double a, double b)
{
  return a/b;
}

double multiply( double a, double b)
{
  return a*b;
}

double xintercept(double a, double b)
{
  return (0-b)/a;
}

double determ(double a, double b, double c)
{
  return (b*b - 4*a*c);
}

double vlength3(double a, double b, double c)
{
  return sqrt(a*a + b*b + c*c);
}

double vlength4(double t, double a, double b, double c)
{
  return (t*t - (a*a + b*b +c*c));
}

double mass(double a, double b)
{
  return sqrt(a*a - b*b);
}

void print(double a)
{
  std::cout << "Result: " << a << std::endl;
}

int main()
{
  double a;
  double b;
  double c;
  double d;
  double e;
  double t;
  double f;
  char op;

  std::cout << "This program can perform a number of operations on user specified numbers. The available operations are: " << std::endl;
  std::cout << "+ : Addition" << "\t" << "- : Subtraction" << std::endl;
  std::cout << "/ : Division" << "\t" << "* : Multiplication" << std::endl;
  std::cout << "x : Find the x intercept of a straight line of form y = mx + c" << std::endl;
  std::cout << "q : Find the roots of a quadratic equation" << std::endl;
  std::cout << "l : Find the length of a vector" << std::endl;
  std::cout << "m : Find the invariant mass of two particles" << std::endl;
 

  while(true){
    //Ask user to select operation
    std::cout << "Enter the operation you would like to perform (+, -, *, /, x, q, l, m), or type Q to quit:" << std::endl;
   
    std::cin >> op;

    // check for bad input
    if(!std::cin)
      {
	std::cerr << "Error in user input" << std::endl;
    
	// clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	continue;
      }
    // exit the program
    if (op == 'Q')
      {
	break;
      }
    // Finding the x intercept
    if(op == 'x')
      {
	std::cout << "Please enter the coefficient of x:" << std::endl;
	std::cin >> a;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }

	std::cout << "Please enter the value of any constant:" << std::endl;
	std::cin >> b;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }
	// check to make sure we don't end up dividing by 0
	if (a == 0)
	  {
	    std::cerr << "Line must have a non-zero gradient" << std::endl;
	    continue;
	  }
	else
	  {
	    c = xintercept(a, b);
	    print(c);
	    continue;
	  }
      }

    // Finding the roots of a quadratic
    if(op == 'q')
      {
	std::cout << "Please enter the coefficient of x^2:" << std::endl;
	std::cin >> a;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }


	std::cout << "Please enter the coefficient of x:" << std::endl;
	std::cin >> b;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }

	std::cout << "Please enter the value of any constant:" << std::endl;
	std::cin >> c;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }
    // check to make sure we don't divide by zero
	if (a == 0)
	  {
	    std::cerr << "For this to be a quadratic, you actually need an x^2 to appear, shall we try this again?" << std::endl;
	    continue;
	  }
	else
	  {
	  	// for real roots of x
	    if (determ(a,b,c)>0){
	      d = (-b + sqrt(determ(a,b,c)))/(4*a*c);
	      e = (-b - sqrt(determ(a,b,c)))/(4*a*c);
	      std::cout << "The roots of the equation are " << d << " and " << e << std::endl;
	      continue;
	    }
        // for when x has complex roots
	    else if (determ(a,b,c)<0){
	      d = sqrt(fabs(determ(a,b,c)));
	      e = sqrt(fabs(determ(a,b,c)));
	      f = 4*a*c;
	      std::cout << "The roots of the equation are (" << -b << "+" << d << "i" << ")/" << f << " and (" << -b << "-" << e << "i" << ")/" << f << std::endl;
	      continue;

	    }
	  }
      
      }

    // calculate the length of vectors
    if(op == 'l')
      {
      	// determine whether calculating length of 3 or 4 vectors
	std::cout << "This program can find the length of a 3 or a 4 vector, enter the size of vector you would like the length of: " << std::endl;
	int v;
	std::cin >> v;
	//check for error in input
	if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      } 
	      // for 3 vectors
	if (v == 3)
	  {
	    std::cout << "Enter the value of the first component of the vector: " << std::endl;
	    std::cin >> a;
	    if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      } 
	    std::cout << "Enter the value of the second component of the vector: " << std::endl;
	    std::cin >> b; 
	    if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      }
	    std::cout << "Enter the value of the third component of the vector: " << std::endl;
	    std::cin >> c; 
	    if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      }
	    d = vlength3(a, b, c);
	    std::cout << "The length of the vector (" << a << "," << b << "," << c << ") is " << d << std::endl;
	    continue;
	  }
	  // for 4 vectors
	else if (v == 4)
	  {
	    std::cout << "Enter the value of the first component of the vector: " << std::endl;
	    std::cin >> t;
	    if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      }
	    std::cout << "Enter the value of the second component of the vector: " << std::endl;
	    std::cin >> a; 
	    if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      }
	    std::cout << "Enter the value of the third component of the vector: " << std::endl;
	    std::cin >> b; 
	    if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      }
	    std::cout << "Enter the value of the fourth component of the vector: " << std::endl;
	    std::cin >> c; 
	    if(!std::cin)
	      {
		std::cerr << "Error in user input" << std::endl;
    
		// clear the buffer
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	      }
	    d = vlength4(t, a, b, c);
	    std::cout << "The length squared of the vector (" << t << "," << a << "," << b << "," << c << ") is " << d << std::endl;
	    continue;
	  }
	  // for the case where the user inputs invalid vector size
	else 
	  {
	    std::cout << "Did I not just say your options were 3 or 4? Feel free to try again, if you must." << std::endl;
	    continue;
	  }
      }

    // calculating the invariant masses of two particles
    if (op == 'm')
      {
	std::cout << "Enter the energy of the first particle (in MeV): " << std::endl;
	std::cin >> a;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }
	std::cout << "Enter the absolute value of the momentum of the first particle (in MeV): " << std::endl;
	std::cin >> b;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }
	std::cout << "Enter the energy of the second particle (in MeV): " << std::endl;
	std::cin >> d;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }
	std::cout << "Enter the absolute value of the momentum of the second particle (in MeV): " << std::endl;
	std::cin >> e;
	// check for bad input
	if(!std::cin)
	  {
	    std::cerr << "Error in user input" << std::endl;
    
	    // clear the buffer
	    std::cin.clear();
	    std::cin.ignore(INT_MAX, '\n');
	    continue;
	  }
	// make sure non-negative energies and |momenta| are used
	if (a < 0 || b < 0 || d < 0 || e < 0)
	  {
	    std::cout << "Energies and momenta must have positive values" << std::endl;
	    continue;
	  }
	// check that momentum is not greater than energy
	if (b > a)
	  {
	    std::cout << "Particle 1: Particle energy must be greater than or equal to its momentum" << std::endl;
	    continue;
	  }
	else 
	  {
	    c = mass(a,b);
	    std::cout << "The invariant mass of the first particle is " << c << " MeV" << std::endl;
	  }
	// check that momentum is not greater than energy
	if (e > d)
	  {
	    std::cout << "Particle 2: Particle energy must be greater than or equal to its momentum" << std::endl;
	    continue;
	  }
	else 
	  {
	    f = mass(d,e);
	    std::cout << "The invariant mass of the second particle is " << f << " MeV" << std::endl;
	    continue;
	  }

      }


    // standard operations
    std::cout << "Please enter the first number:" << std::endl;
    std::cin >> a;
    // check for bad input
    if(!std::cin)
      {
	std::cerr << "Error in user input" << std::endl;
    
	// clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	continue;
      }

    std::cout << "Please enter the second number:" << std::endl;
    std::cin >> b;
    // check for bad input
    if(!std::cin)
      {
	std::cerr << "Error in user input" << std::endl;
    
	// clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	continue;
      }

    // addition
    else if(op=='+'){
      c = add(a,b);
      print(c);
    }

    // subtraction
    else if(op=='-'){
      c = subtract(a,b);
      print(c);
    }

    // division
    else if(op=='/'){
      // make sure not dividing by 0
      if (b == 0)
	{
	  std::cerr << "You're trying to divide by zero? Why? Why would you do that? No good can come of this." << std::endl;
	  continue;
	}
      else
	{
	  c = divide(a, b);
	  print(c);
	}
    }

    // multiplication
    else if(op=='*'){
      c = multiply(a,b);
      print(c);
    }

    // error message for invalid operations
    else
      {
	std::cerr << "'" << op << "' is not a valid operation." << std::endl;
	continue;
      }
  }
 
  return 0;
}
