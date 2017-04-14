#include <vector>

#include "cdcl.h"
#include "defs.h"

bool unitResolution(CNF cnf, std::vector<CLAUSE> learnedClauses, std::vector<LITERAL> decisionSequence) {
	return true;
}

LITERAL getNextLiteral() {
	return 0;
}

bool cdcl(CNF cnf) {
	std::vector<LITERAL> decisionSequence;
	std::vector<CLAUSE> learnedClauses;

	while(1) {
		if (!unitResolution(cnf, learnedClauses, decisionSequence)) {
			if (decisionSequence.empty()) return false;
			else {
				CLAUSE assertingClause;
				int assertionLevel;
				decisionSequence.erase(decisionSequence.begin()+assertionLevel,decisionSequence.end());
				learnedClauses.push_back(assertingClause);
			}
		} else {
			LITERAL nextLit(getNextLiteral());
			if (nextLit) {
				decisionSequence.push_back(nextLit);
			} else {
				return true;
			}
		}
	}

	return false;
}
