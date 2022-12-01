#ifndef NEGATIVE_CYCLE_EXCEPTION
#define NEGATIVE_CYCLE_EXCEPTION

#include <string>
#include <Exceptions/GLException.h>

class NegativeCycleException : public GLException {
 private:
  std::string errorType = "NegativeCycleException";
 public:
  NegativeCycleException(const std::string &s) : GLExption(s) {};
};

#endif