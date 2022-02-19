#include "../headers/matrix.h"

#define THROW_EX(EXIT_CODE, ...) \
	fprintf(stderr, __VA_ARGS__);  \
	exit(EXIT_CODE)
