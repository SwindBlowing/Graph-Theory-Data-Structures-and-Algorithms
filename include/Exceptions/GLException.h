#ifndef GL_EXCEPTION
#define GL_EXCEPTION

#include <iostream>
#include <exception>
#include <string>

class GLException : public std::exception {
 protected:
  std::string message;
 public:
  explicit GLException(const std::string &s);
  virtual std::string GetMessage() const;
};

ostream &operator<<(ostream &os, const GLException &e);

#endif

