#include <string>
#include <cstdlib>

#include "dimacs.h"
#include "defs.h"

CNF DimacsParser::readCNF(std::istream& is) {
	CNF cnf();

	LITERAL lit;

	do {
		is.read(buffer.data(), buffer.size());
		for (idx = 0; idx < is.gcount(); ++idx) {
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
					std::cout << lit << ' ';
					eatUntil(' ');
					eatAll(' ');
				}
				eatLine();
				std::cout << std::endl;
			}
		}
	} while(1);

	return cnf;
}

void DimacsParser::eat(char c) {
	if (c != buffer[idx]) {
		std::string err;
		err += "Parsing error at " + idx;
		err += ": expected '" + c;
		err += "'";
		throw err;
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
	eat('\n');
}
