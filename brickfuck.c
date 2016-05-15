#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;


int main(int argc, char *argv[]){
	long long bf_tape[30000] = {0};
	long long *bf_ptr = bf_tape;
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
			fclose(source);
		}
	}
	return 0;
}
