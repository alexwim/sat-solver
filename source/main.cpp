#include <iostream>
#include <vector>
#include <string>

#include "dimacs.h"
#include "cdcl.h"
#include "defs.h"
#include "cnf.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
	DimacsParser dp(std::cin);
	CNF *cnf;
	
	try{
		cnf = dp.readCNF();
		std::cout << (cdcl(cnf) ? "SAT" : "UNSAT") << std::endl;
	} catch (std::string &msg) {
		std::cerr << msg << std::endl;
	}

	for (int i(0); i < cnf->nbClauses(); ++i) {
		for (int j(0); j < (*cnf)[i].size(); ++j) {
			std::cout << (*cnf)[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
