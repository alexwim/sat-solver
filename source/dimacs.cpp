#include <string>
#include <cstdlib>
#include <sstream>

#include "dimacs.h"
#include "defs.h"
#include "cnf.h"

CNF* DimacsParser::readCNF() {
	CNF *cnf;
	LITERAL lit;

	loadLine();

	do {// For each block
		// Comment
		if ('c' == buffer[idx]) {
			loadLine();
		}
		// Parameters
		else if ('p' == buffer[idx]) {
			eat('p');
			eatAll(' ');
			eat('c');
			eat('n');
			eat('f');
			eatAll(' ');
			nbVar = atoi(&buffer[idx]);
			cnf = new CNF(nbVar);
			eatUntil(' ');
			eatAll(' ');
			nbClauses = atoi(&buffer[idx]);
			loadLine();
		}
		// Clause
		else {
			eatAll(' ');
			while((lit = atoi(&buffer[idx])) != 0) {
				clause.push_back(lit);
				eatUntil(' ');
				eatAll(' ');
			}
			eat('0');
			cnf->conjoin(clause);
			clause.clear();
			nbClausesSeen++;

			eatAll(' ');
		}
	} while(nbClauses < 0 || nbClausesSeen < nbClauses);

	return cnf;
}

void DimacsParser::eat(char c) {
	if (c != buffer[idx]) {
		std::ostringstream err;
		err << "Parsing error at char " << idx << ": expected '" << c << "', got '" << buffer[idx] << "'";
		throw err.str();
	}
	++idx;
	loadLineIfNeeded();
}

void DimacsParser::eatAll(char c) {
	loadLineIfNeeded();
	while (c == buffer[idx]) {
		eat(c);
	}
}

void DimacsParser::eatUntil(char c) {
	loadLineIfNeeded();
	while (c != buffer[idx]) {
		eat(buffer[idx]);
	}
}

void DimacsParser::loadLineIfNeeded() {
	if (idx >= lineSize-1) {
		loadLine();
	}
}

void DimacsParser::loadLine() {
	is.getline(buffer.data(), buffer.size());
	lineSize = is.gcount();
	idx = 0;
}
