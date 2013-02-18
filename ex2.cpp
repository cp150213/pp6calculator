#include <iostream>


int main()
{
  int a;
  int b;
  int c;

  std::cout << "Please enter the first number for multiplication:" << std::endl;
  std::cin >> a;
  std::cout << "Please enter the second number for multiplication:" << std::endl;
  std::cin >> b;
  c=a*b;
  std::cout << "The product of " << a << " and " << b << " is " << c << std::endl;

  return 0;
}
