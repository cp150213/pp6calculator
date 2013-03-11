#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int myrandom() {
  return rand()%100;
}

int main(){
  std::vector<int> v(10);
  generate(v.begin(), v.end(), myrandom);
  std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, "\n"));
  /* std::vector<int>::const_iterator vmax = max_element(v.begin(), v.end());
  std::cout << "The largest element is " << *vmax << std::endl;
  std::vector<int>::const_iterator vmin = min_element(v.begin(), v.end());
  std::cout << "The smallest element is " << *vmin << std::endl;*/
  std::cout << "The smallest element is " << *std::min_element(v.begin(),v.end()) << '\n';
  std::cout << "The largest element is "  << *std::max_element(v.begin(),v.end()) << '\n';
  sort(v.begin(), v.end());
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
