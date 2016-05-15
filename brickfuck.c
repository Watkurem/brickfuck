#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "brickfuck.h"

extern int errno;


int main(int argc, char *argv[]){
	FILE *source;

	if(argc <= 1){
		puts("Specify brainfuck source file.");
	} else {
		source = fopen(argv[1], "r");

		if(!source){
			char err_info[strlen("brickfuck: ") + 1 + strlen(argv[1]) + 1];
			strcpy(err_info, "brickfuck: ");
			strcat(err_info, argv[1]);

			perror(err_info);
		} else {
			interpret_brainfuck(source);
			fclose(source);
		}
	}

	return 0;
}

void interpret_brainfuck(char *source){
	if(!source){
		return;
	}

	long long bf_tape[30000] = {0};
	long long *bf_ptr = bf_tape;
}
