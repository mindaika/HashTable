#ifndef _PRECOND_VIOLATED_EXEP
#define _PRECOND_VIOLATED_EXEP

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error
{
public:
	PrecondViolatedExcep(const std::string& message = "");
};
#endif