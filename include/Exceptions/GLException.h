#ifndef GL_EXCEPTION
#define GL_EXCEPTION

#include <iostream>
#include <exception>
#include <string>

class GLException : public std::exception {
 protected:
  std::string message;
 public:
  explicit GLException(const std::string &s) : message(s) {};
  virtual std::string GetMessage() const{
	return message;
  }
};

/*std::ostream &operator<<(std::ostream &os, const GLException &e)
{
  return os << e.GetMessage();
}*/

#endif

