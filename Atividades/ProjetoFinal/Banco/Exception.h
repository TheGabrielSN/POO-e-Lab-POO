#ifndef EXEPTION_H
#define EXEPTION_H
#include <stdexcept>                                    //Biblioteca para runtime_error
using std::runtime_error;
class ExceptionError : public runtime_error{
public:
    ExceptionError(const char *e) : runtime_error(e) {} 
};

#endif