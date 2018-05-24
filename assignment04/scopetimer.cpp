#include <iostream>
#include "scopetimer.hpp"

ScopeTimer::ScopeTimer(const char* name)
  : _name(name), _start(std::clock())  {

  std::cout << "Starting Timer " << _name << "\n";
}

ScopeTimer::~ScopeTimer() {
  std::cout << "Timer " << _name <<" took " << 1000*float(std::clock()-_start)/CLOCKS_PER_SEC << " ms\n";
}
