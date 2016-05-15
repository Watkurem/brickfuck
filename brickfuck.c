#include <stdio.h>

int main(int argc, char *argv[]){
	long long bf_tape[30000] = {0};
	long long *bf_ptr = bf_tape;

	if(argc <= 1){
		puts("Specify brainfuck source file.");
	}
	return 0;
}
