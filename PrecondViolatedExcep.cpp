#include "PrecondViolatedExcep.h"

// Constructor
PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message):
	logic_error("Precondition Violated Exception: " + message) { }