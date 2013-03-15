#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include "FileReader.hpp"
#include "PP6MenuDay5.hpp"
#include "PP6Math.hpp"
#include "PP6ParticleInfo.hpp"
#include "Particle.hpp"
#include "TwoBodyGenerator.hpp"

bool initialise_database() {
  static bool dbIsUninitialised(true);
  if (dbIsUninitialised) {
    std::string dbFilename;
    std::cout << "Enter the filename (with it's path) of the .dbt file to initialise ParticleInfo" << std::endl;
    dbFilename = getString();

    const ParticleInfo& dataBase = ParticleInfo::Instance(dbFilename);

    std::cout << "Checking for entries in ParticleInfo";
    if (!dataBase.size()) {
      std::cout << "Oh nooooooooooooo, it failed." << std::endl;
      return false;
    }
    else {
      std::cout << "huzzah!" << std::endl;
      dbIsUninitialised = false;
    }
  }

  return !dbIsUninitialised;
}

int twoBodyGenerator() {
  if (!initialise_database()) return 1;

  TwoBodyGenerator generator("B0", "K+", "pi-");
  int dMinusPDG = ParticleInfo::Instance().getPDGCode("B0");
  double expectedMass = ParticleInfo::Instance().getMassGeV(dMinusPDG);
  //Loop to generate products with inv masses and print
  for (int i(0); i < 50; ++i) {
    std::cout << "Iteration" << i << std::endl;
    std::vector<Particle> decayProducts = generator.generate(0.56);
    double invMass = calculate_invariant_mass(decayProducts);
    std::copy(decayProducts.begin(), decayProducts.end(), std::ostream_iterator<Particle>(std::cout, "\n"));
    std::cout << "Invariant Mass = " << invMass << std::endl;
    std:: cout << "Expected: " << expectedMass << std::endl;
  }
  return 0;
}


void pp6MenuDay5() {

  double resultCode(0);
  char op('\0');

  while (true)
    {

      std::cout << "Enter the operation you would like to perform:" << std::endl;
      std::cout << "1) Something day 5-ish" << std::endl;
      std::cout << "Or type Q to quit" << std::endl;

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
	  resultCode = twoBodyGenerator();
	}

      else
	{
	  std::cerr << "[error] Operation '" << op << "' not recognised."
		    << std::endl;
	  continue;
	}

      // Handle any errors
      if (resultCode)
	{
	  std::cerr << "[error] Operation '" << op
		    << "' returned a non-zero code '" << resultCode
		    << "'. Please check parameters."
		    << std::endl;
	  resultCode = 0;
	  continue;
	}
    }
}
