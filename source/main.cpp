#include <iostream>
#include <vector>
#include <string>

#include "dimacs.h"
#include "defs.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
	DimacsParser dp;
	CNF cnf(dp.readCNF(std::cin));

	return 0;
}
