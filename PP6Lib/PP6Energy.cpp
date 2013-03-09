#include <iostream>
#include <cmath>
#include "PP6Energy.hpp"
#include "PP6Math.hpp"

int PP6Energy() {
  // Read in number of 4-Vectors to generate
  //
  int numberOfVectors(0);
  std::cout << "Enter number of vectors to generate: ";
  numberOfVectors = getNumber();
  if ((numberOfVectors > 0) && (numberOfVectors < 1001))
  {
    // Create arrays and variables
    double *E = new double[numberOfVectors];
    double *px = new double[numberOfVectors];
    double *py = new double[numberOfVectors];
    double *pz = new double[numberOfVectors];
    int *indices = new int[numberOfVectors];
    double m(0);
    double pMag(0), totalpx(0), totalpy(0), totalpz(0);
    double Emean(0), Estddev(0);

    // Loop to fill arrays
    for(int i(0); i < numberOfVectors; ++i)
    {
      // Index for use in sorting later
      indices[i] = i;
      px[i] = 100.0 * getRandom();
      py[i] = 100.0 * getRandom();
      pz[i] = 100.0 * getRandom();
      m = 100.0 * getRandom();

      // Momentum magnitude and energy
      length3(px[i], py[i], py[i], pMag);
      E[i] = sqrt(m * m + pMag);
    }

    // Compute and display total three momentum
    if (sumVectors(px, py, pz, numberOfVectors,
                   totalpx, totalpy, totalpz))
    {
      std::cerr << "[error]: Failed to calculate total 3-momentum" << std::endl;
      // Tidy up arrays
      delete [] E;
      delete [] px;
      delete [] py;
      delete [] pz;
      delete [] indices;
      return 1;
    }

    if (length3(totalpx, totalpy, totalpz, pMag))
    {
      std::cerr << "[error]: Failed to calculate 3-momentum magnitude" << std::endl;
      // Tidy up arrays
      delete [] E;
      delete [] px;
      delete [] py;
      delete [] pz;
      delete [] indices;
      return 1;
    }

    std::cout << "[Total 3-Momentum] : P(" << totalpx << ", " << totalpy << ", " << totalpz << "), " << "|P| = " << pMag << std::endl;

    // Calculate average energy and standard deviation
    if (getMeanAndStdDev(E, numberOfVectors, Emean, Estddev))
    {
      std::cerr << "[error]: Failed to calculate energy statistics" << std::endl;
      // Tidy up arrays
      delete [] E;
      delete [] px;
      delete [] py;
      delete [] pz;
      delete [] indices;
      return 1;
    }

    std::cout << "[Mean Energy] : E = "
        << Emean
        << " +/- "
        << Estddev
        << std::endl;

    // Sort and find highest energy
    if (associative_sort(E, indices, numberOfVectors))
    {
      std::cerr << "[error]: Failed to sort energy array" << std::endl;
      // Tidy up arrays
      delete [] E;
      delete [] px;
      delete [] py;
      delete [] pz;
      delete [] indices;
      return 1;
    }

    std::cout << "[Maximum Energy] : E = "
        << E[indices[0]]
        << ", found at index "
        << indices[0]
        << " of "
        << numberOfVectors
        << std::endl;

    // Tidy up arrays
    delete [] E;
    delete [] px;
    delete [] py;
    delete [] pz;
    delete [] indices;
  }
  else {
    std::cerr << "[error]: Number must be between 1 and 1000" << std::endl;
    return 1;
  }

  return 0;
}

