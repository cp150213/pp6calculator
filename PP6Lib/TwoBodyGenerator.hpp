#ifndef TWOBODYGENERATOR_HH
#define TWOBODYGENERATOR_HH

#include <iostream>
#include "Particle.hpp"
#include <vector>
#include "EventGenerator.hpp"
#include <string>

class TwoBodyGenerator : public EventGenerator{
public:
  TwoBodyGenerator(const std::string& mother, const std::string& daughter1, const std::string& daughter2);
  TwoBodyGenerator(const int mother_code, const int daughter1_code, const int daughter2_code);
  virtual ~TwoBodyGenerator(){}
  virtual std::vector<Particle> generate(const double mother_beta) const;

private:
  void checkValid();
  void calculateQ();
  
  Particle mother_;
  Particle daughter1_;
  Particle daughter2_;

  double qvalue_;

  bool valid_;
  
};

#endif //TWOBODYGENERATOR_HH
