#include <iostream>
#include <cmath>
#include "FileReader/FileReader.hpp"
#include <string>
#include <vector>


int main() {
  std::string pdgFile;

  // Obtain filename from user
  std::cout << "Enter filename to analyse: ";
  std::cin >> pdgFile;

  std::vector<std::string> particleName;
  std::vector<int> pdgCode;
  std::vector<double> mass;
  std::vector<int> charge;
    
  // - Read in data
  FileReader pdgReader(pdgFile);
 
  while (pdgReader.nextLine()) {

    particleName.push_back(pdgReader.getField<std::string>(1));
    if (pdgReader.inputFailed()) {
      std::cerr << "[error] Field 1 of "
                << pdgFile
                << " is not a string"
                << std::endl;
      break;
    }
   
    pdgCode.push_back(pdgReader.getField<int>(2));
    if (pdgReader.inputFailed()) {
      std::cerr << "[error] Field 2 of "
                << pdgFile
                << " is not a int"
                << std::endl;
      break;
    }

    charge.push_back(pdgReader.getField<int>(3));
    if (pdgReader.inputFailed()) {
      std::cerr << "[error] Field 3 of "
                << pdgFile
                << " is not a int"
                << std::endl;
      break;
    }

    mass.push_back(pdgReader.getField<double>(4));
    if (pdgReader.inputFailed()) {
      std::cerr << "[error] Field 4 of "
                << pdgFile
                << " is not a double"
                << std::endl;
      break;
    }

    size_t num = particleName.size();

    for (size_t i = 0; i < num; ++i) {
      std::cout << particleName[i] << "\t" << pdgCode[i] << "\t" << charge[i] << "\t" << mass[i] << std::endl;
    }  
  }
 
}




