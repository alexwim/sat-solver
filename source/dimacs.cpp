#include <string>
#include <cstdlib>
#include <sstream>

#include "dimacs.h"
#include "defs.h"

CNF DimacsParser::readCNF(std::istream& is) {
	CNF cnf;
	LITERAL lit;

	do {// For each block
		is.read(buffer.data(), buffer.size());
		for (idx = 0; idx < is.gcount(); ) {
			// Comment
			if ('c' == buffer[idx]) {
				eat('c');
				eatLine();
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
				eatUntil(' ');
				eatAll(' ');
				nbClauses = atoi(&buffer[idx]);
				eatLine();
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
				cnf.push_back(clause);
				clause.clear();
				nbClausesSeen++;

				eatAll(' ');
				eatAll('\n');
			}
		}
	} while(nbClausesSeen < nbClauses);

	return cnf;
}

void DimacsParser::eat(char c) {
	if (c != buffer[idx]) {
		std::ostringstream err;
		err << "Parsing error at char " << idx << ": expected '" << c << "', got '" << buffer[idx] << "'";
		throw err.str();
	}
	++idx;
}

void DimacsParser::eatAll(char c) {
	while (c == buffer[idx]) {
		eat(c);
	}
}

void DimacsParser::eatUntil(char c) {
	while (c != buffer[idx]) {
		eat(buffer[idx]);
	}
}

void DimacsParser::eatLine() {
	eatUntil('\n');
	eatAll('\n');
}
