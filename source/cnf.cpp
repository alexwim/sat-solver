#include "cnf.h"
#include "defs.h"

void CNF::conjoin(CLAUSE c) {
	clauses.push_back(c);
}

void CNF::setNbVars(int nvars_o) {
	nvars = nvars_o;
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
