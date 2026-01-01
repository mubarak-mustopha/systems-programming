#include <stdio.h>

#define BUFFER_SIZE 1024

int main(){
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	char buffer[BUFFER_SIZE];

	size_t length;
	length = fread(buffer, sizeof(char), BUFFER_SIZE, input);
	while (length > 0) {
		fwrite(buffer, sizeof(char), length, output);
		length = fread(buffer, sizeof(char), BUFFER_SIZE, input);
	}
	fclose(input);
	fclose(output);
}
