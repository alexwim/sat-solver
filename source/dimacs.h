#ifndef DIMACS_H
#define DIMACS_H

#include <iostream>
#include <vector>

#include "defs.h"

class DimacsParser {
public:
	DimacsParser(): buffer(BUFFER_SIZE,0) {}

	CNF readCNF(std::istream&);

private:
	// Helpers
	void eat(char);
	void eatAll(char);
	void eatUntil(char);
	void eatLine();

private:
	std::vector<char> buffer;
	int nbVar;
	int nbClauses, nbclausesSeen;
	int idx;

	static const int BUFFER_SIZE = 1024;
};

#endif
