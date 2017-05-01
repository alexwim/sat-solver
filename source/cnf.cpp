#include <cstdlib>

#include "cnf.h"
#include "defs.h"

void CNF::conjoin(CLAUSE c) {
	clauses.push_back(c);

	if (c.size() > 2) {
		watcher1[abs(c[0])].push_back(clauses.size()-1);
		watcher2[abs(c[1])].push_back(clauses.size()-1);
		//Unit resolution should handle unit clauses 
	}
}

void CNF::setNbVars(int nvars_o) {
	nvars = nvars_o;
	watcher1.resize(nvars);
	watcher2.resize(nvars);
}

int CNF::nbClauses() {
	return clauses.size();
}

int CNF::nbVars() {
	return nvars;
}

CLAUSE CNF::operator[](int idx) {
	return clauses[idx];
}
