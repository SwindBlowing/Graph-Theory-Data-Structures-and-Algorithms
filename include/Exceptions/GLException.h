#ifndef GL_EXCEPTION
#define GL_EXCEPTION

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class GLException : public std::exception {
 protected:
  std::string message;
 public:
  explicit GLException(const std::string &s) : message(s) {};
  virtual std::string GetMessage() const{
	return message;
  }
};

ostream &operator<<(ostream &os, const GLException &e)
{
  return os << e.GetMessage();
}

#endif

