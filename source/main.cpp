#include <iostream>
#include <vector>
#include <string>

#include "dimacs.h"
#include "defs.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
	CNF cnf(dimacs::readCNF(std::cin));

	return 0;
}
