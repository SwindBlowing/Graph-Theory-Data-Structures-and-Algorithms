#include <string>
using namespace std;

#include <Exceptions/GLException.h>

GLException::GLException(const string &s) : message(s) {}

string GLException::GetMessage() const {
  return message;
}

ostream &operator<<(ostream &os, const GLException &e) {
  return os << e.GetMessage();
}

