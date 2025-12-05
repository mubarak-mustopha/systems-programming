#include <stdio.h>

int subtract(int x, int y);

int subtract(int x, int y){
	return x - y;
}

int main(){
	int (*sapPtr)(int, int) = subtract;

	int y = sapPtr(10, 2);
	printf("Muby says the answer is %d\n", y);
	
	int z = (*sapPtr)(12, 4);
	printf("Muby says the answer is %d\n", z);
}
