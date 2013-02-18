#include <iostream>
#include <climits>

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

void print(double a)
{
  std::cout << "Result: " << a << std::endl;
}

int main()
{
  double a;
  double b;
  double c;
  int op;
  char answer;

  std::cout << "This program will perform a basic operation on two user specified numbers. The available operations are: " << std::endl;
  std::cout << "1 : Addition" << std::endl;
  std::cout << "2 : Subtraction" << std::endl;
  std::cout << "3 : Division" << std::endl;
  std::cout << "4 : Multiplication" << std::endl;
  while(true){
    
    std::cout << "Enter the number of the operation you would like to perform" << std::endl;
   
    std::cin >> op;
 
    std::cout << "Please enter the first number:" << std::endl;
    std::cin >> a;
    std::cout << "Please enter the second number:" << std::endl;
    std::cin >> b;

    //check for valid user input
    if (!std::cin){
      std::cout << "Error in user input" << std::endl;
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
      continue;
    }

    else if(op==1){
      c = add(a,b);
      print(c);
    }

    else if(op==2){
      c = subtract(a,b);
      print(c);
    }

    else if(op==3){
      c= divide(a,b);
      print(c);
    }

    else if(op==4){
      c = multiply(a,b);
	print(c);
    }

    else {
      std::cout << "You entered an invalid operation, feel free to try again." << std::endl;}

    std::cout << "Would you like to perform another operation (Y/N)?" << std::endl;
    std::cin >> answer;
    if (answer=='N') break;
    else if (answer=='Y') continue;
  }
 
  return 0;
}
