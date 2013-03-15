#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "FileReader.hpp"
#include "PP6MenuDay4.hpp"
#include "PP6Math.hpp"
#include "PP6ParticleInfo.hpp"
#include "PP6Day4Muon.hpp"


int pdgRead() {
	std::string pdgFile;
	std::cout << "Enter filename to analyse: ";
	pdgFile = getString();

	FileReader pdgReader(pdgFile);

	if (!pdgReader.isValid()) {
		std::cerr << "[error] "
		<< pdgFile
		<< " is not a valid file"
		<< std::endl;
		return 1;
	} 
	else 
	{
		std::vector<std::string> particleName;
		std::vector<int> pdgCode;
		std::vector<double> mass;
		std::vector<int> charge;

      // Read and display data
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

	// present results
	// Iterators
			std::vector<std::string>::iterator nameIter(particleName.begin());
			std::vector<std::string>::iterator stopCond(particleName.end());

			std::vector<int>::iterator pdgIter = pdgCode.begin();
			std::vector<int>::iterator chargeIter = charge.begin();
			std::vector<double>::iterator massIter = mass.begin();

			for ( ; nameIter != stopCond; ++nameIter,
				++pdgIter, ++chargeIter, ++massIter) {
				std::cout << *nameIter << " "
			<< *pdgIter << " "
			<< *chargeIter << " "
			<< *massIter
			<< std::endl;
		}
	}

	return 0;
}
}

int pp6Particleinfo() {
	std::string pdgFile;
	std::cout << "Enter path to .dbt file for initializing ParticleInfo: ";
	pdgFile = getString();

	const ParticleInfo& pdgReader = ParticleInfo::Instance(pdgFile);

    // Check it has entries
	std::cout << "Checking ParticleInfo contains entries... ";
	if (!pdgReader.size()) {
		std::cout << "fail" << std::endl;
		return 1;
	} 
	else {
		std::cout << "ok" << std::endl;
	}

    // It must contain mu+ and mu-
	std::cout << "Checking ParticleInfo returns correct mu- PDG code... ";
	if (pdgReader.getPDGCode("mu-") != 13) {
		std::cout << "fail" << std::endl;
		return 1;
	} 
	else {
		std::cout << "ok" << std::endl;
	}

	std::cout << "Checking ParticleInfo returns correct mu+ PDG code... ";
	if (pdgReader.getPDGCode("mu+") != -13) {
		std::cout << "fail" << std::endl;
		return 1;
	} 
	else {
		std::cout << "ok" << std::endl;
	}

    // Check that mu+ and mu- entries return +ve masses
	std::cout << "Checking ParticleInfo returns +ve mass for mu-... ";
	if (pdgReader.getMassMeV(13) <= 0.0) {
		std::cout << "fail" << std::endl;
		return 1;
	} 
	else {
		std::cout << "ok" << std::endl;
	}

	std::cout << "Checking ParticleInfo returns +ve mass for mu+... ";
	if (pdgReader.getMassMeV(-13) <= 0.0) {
		std::cout << "fail" << std::endl;
		return 1;
	} 
	else {
		std::cout << "ok" << std::endl;
	}

	return 0;
}


int myrandom() {
	return rand()%100;
}

int pp6day4ex5() {

	std::vector<int> v(10);
	generate(v.begin(), v.end(), myrandom);
	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, "\n"));
	std::cout << "The smallest element is " << *std::min_element(v.begin(),v.end()) << '\n';
	std::cout << "The largest element is "  << *std::max_element(v.begin(),v.end()) << '\n';
	sort(v.begin(), v.end());
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));

	return 0;
}

void pp6MenuDay4() {

	double resultCode(0);
	char op('\0');

	while (true)
	{

		std::cout << "Enter the operation you would like to perform:" << std::endl;
		std::cout << "1) Read in the pdg database file and display data to terminal" << std::endl;
std::cout << "2) Instantiate a ParticleInfo instance and test it" << std::endl;
std::cout << "3) Sort an array" << std::endl;
std::cout << "4) Analyse muons from file, day 4 style" << std::endl;
std::cout << "Or type Q to quit" << std::endl;
std::cout << ">> ";

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
	resultCode = pdgRead();
}
else if (op == '2')
{
	resultCode = pp6Particleinfo();
}
else if (op == '3')
{
	resultCode = pp6day4ex5();
}
else if (op == '4')
{
	resultCode = pp6Day4Muon();
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
