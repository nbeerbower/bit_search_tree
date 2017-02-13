#include <stdio.h>
#include <string.h>

#include "bit.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please provide a string.\n");
		return -1;
	}
	
	const char *string = argv[1];
	
	printf("%s\n", string);
	
	for (int i = 0; i < strlen(string); i++) {
		for (int j = 0; j < 8; j++) {
			printf("%i", bit_at(((byte_t *) string)[i], j));
		}
	}
	printf("\n");
	
	return 0;
}
