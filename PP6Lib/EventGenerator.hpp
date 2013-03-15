#ifndef EVENTGENERATOR_HH
#define EVENTGENERATOR_HH

#include <iostream>
#include "Particle.hpp"
#include <vector>

class EventGenerator {
public:
  virtual ~EventGenerator(){}
  virtual std::vector<Particle> generate(const double mother_beta) const = 0;
};

#endif //EVENTGENERATOR_HH
