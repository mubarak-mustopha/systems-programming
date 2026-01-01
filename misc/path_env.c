#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char* PATH = strdup(getenv("PATH"));
	if (PATH == NULL){
		perror("strdup");
		return 1;
	}
	char *str, *tok_ptr, *save_ptr;
	for (str=PATH;; str=NULL){
		tok_ptr = strtok_r(str, ":", &save_ptr);
		if (tok_ptr == NULL)
			break;
		printf("\t%s\n", tok_ptr);
	}
	free(PATH);
	return 0;
}
