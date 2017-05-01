#ifndef CNF_H
#define CNF_H

#include <vector>

#include "defs.h"

class CNF {
public:
	CNF(int nvars_o): nvars(nvars_o) { }

	void conjoin(CLAUSE c) { clauses.push_back(c); }
	int nbClauses() { return clauses.size(); }
	int nbVars() { return nvars; }

	CLAUSE operator[](int idx) { return clauses.at(idx); }

private:
	std::vector<CLAUSE> clauses;
	int nvars;
};

#endif
