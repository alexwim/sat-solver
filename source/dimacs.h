#ifndef DIMACS_H
#define DIMACS_H

#include <iostream>

#include "defs.h"

namespace dimacs {
	CNF readCNF(std::istream&);
}

#endif
