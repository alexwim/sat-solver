#ifndef CNF_H
#define CNF_H

#include <vector>

#include "defs.h"

class CNF {
public:
	CNF(): nvars(0) { }

	void conjoin(CLAUSE);
	void setNbVars(int);

	int nbClauses();
	int nbVars();

	CLAUSE operator[](int);

private:
	std::vector<CLAUSE> clauses;
	int nvars;
};

#endif
