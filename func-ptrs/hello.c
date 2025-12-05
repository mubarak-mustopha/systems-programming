#include <stdio.h>

void sayHello();

void sayHello(){
	printf("Hello world!\n");
}

int main(){
	void (*sayHelloPtr)() = sayHello;
	(*sayHelloPtr)();
	sayHelloPtr();
}
