#ifndef DIMACS_H
#define DIMACS_H

#include <iostream>
#include <vector>

#include "defs.h"
#include "cnf.h"

class DimacsParser {
public:
	DimacsParser(std::istream &o): is(o), buffer(BUFFER_SIZE,0), nbVar(-1), nbClauses(-1), nbClausesSeen(0), idx(0), lineSize(0)
		{}

	CNF* readCNF();

private:
	// Helpers
	void eat(char);
	void eatAll(char);
	void eatUntil(char);

	// Load line only if we've reached the end of the current line
	void loadLineIfNeeded();
	// Forces a line load
	void loadLine();

private:
	std::istream &is;
	std::vector<char> buffer;
	int nbVar;
	int nbClauses, nbClausesSeen;
	int idx;
	int lineSize;

	CLAUSE clause;

	static const int BUFFER_SIZE = 1024;
};

#endif
