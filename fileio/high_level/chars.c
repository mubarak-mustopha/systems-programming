#include <stdio.h>

int main(){
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	int c;

	c = fgetc(input);
	while(c != EOF){
		fputc(c, output);
		c = fgetc(input);
	}
	fclose(input);
	fclose(output);
}
