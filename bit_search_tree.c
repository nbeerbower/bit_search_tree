#include <stdio.h>
#include <string.h>

#include "bit_search_tree.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please provide a string.\n");
		return -1;
	}
	
	const char *string = argv[1];
	
	printf("%s\n", string);
	
	int i;
	for (i = 0; i < (strlen(string) * BITS_IN_BYTE); i++) {
		printf("%i", ((bit_t *) string)[i].x ? 1 : 0);
	}
	printf("\n");
	
	return 0;
}
