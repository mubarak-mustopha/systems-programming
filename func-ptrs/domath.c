#include <stdio.h>

int add(int x, int y);
int subract(int x, int y);
int domath(int mathop(int, int),int x, int y);
typedef int mathop(int, int);

int add(int x, int y){
	return x + y;
}

int subtract(int x, int y){
	return x - y;
}

int domath(mathop* op, int x, int y){
	return op(x, y);
}

int main(){
	int (*domathPtr)(mathop*, int, int) = domath; 

	int a = domathPtr(add, 10, 12);
	int b = domathPtr(subtract, 22, 16);
	int c = domathPtr(add, 8, 23);
	printf("Do Math Results:\n%d\n%d\n%d\n", a, b, c);
}
