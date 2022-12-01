#ifndef NEGATIVE_CYCLE_EXCEPTION
#define NEGATIVE_CYCLE_EXCEPTION

#include <iostream>
#include <exception>
#include <string>
#include <Exceptions/GLException.h>

class NegativeCycleException : public GLException {
 protected:
  std::string errorType = "NegativeCycleException";
  std::string errorAlgorithm;
 public:
  NegativeCycleException(const std::string &s) : GLExption(errorType) 
  {
	errorAlgorithm = s;
  };
  std::string GetErrorAlgorithm() const
  {
	return errorAlgorithm;
  }
};

std::ostream &operator<<(std::ostream &os, const NegativeCycleException &e)
{
	return os << e.GetErrorAlgorithm();
}

#endif