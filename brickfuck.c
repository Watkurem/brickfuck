#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "brickfuck.h"

extern int errno;


int main(int argc, char *argv[]){
	FILE *source;
	struct stat filstat;
	char *bf_code;

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
			fstat(fileno(source), &filstat);
			bf_code = strip_source(source, filstat.st_size);
			fclose(source);

			interpret_brainfuck(bf_code);
			free(bf_code);
		}
	}

	return 0;
}

char * strip_source(FILE *source, long length){
	char *buf = calloc(length, sizeof(char));
	char *buf_iter = buf;
	char c;

	if(length == 0){
		return NULL;
	}

	for(int i = 0; i < length; i++){
		c = getc(source);
		switch(c){
		case '>':
		case '<':
		case '+':
		case '-':
		case '.':
		case ',':
		case '[':
		case ']':
			*buf_iter++ = c;
		}
	}

	long long result_length = buf_iter - buf + 1;
	buf = realloc(buf, result_length + 1);
	buf[result_length] = '\0';

	return buf;
}

void interpret_brainfuck(char *source){
	if(!source){
		return;
	}

	long long bf_tape[30000] = {0};
	long long *bf_ptr = bf_tape;
	char *i = source;

	while(*i != '\0'){
		switch(*i){
		case '>':
			bf_ptr++;
			break;
		case '<':
			bf_ptr--;
			break;
		case '+':
			(*bf_ptr)++;
			break;
		case '-':
			(*bf_ptr)--;
			break;
		case '.':
			putchar(*bf_ptr);
			break;
		case ',':
			*bf_ptr = getchar();
			if(*bf_ptr == EOF){
				*bf_ptr = 0;
			}
			break;
		default:
			puts("You should not see this. If you see this, the geese got loose "
			     "(meaning, memory pointer is somewhere it's not supposed to be). "
			     "Consider reporting a bug.");
			break;
		}
		i++;
	}
}
