#include <assert.h>
#include <stdio.h>
#include <pthread.h>


void* mythread(void* myarg){
	long int arg = (long int) myarg;
	printf("Inside mythread: %ld\n", arg);
	return (void *) (arg + 1); 
}

int main(int argc, char* argv[]){
	long int rvalue;
	pthread_t p;

	int rc = pthread_create(&p, NULL, mythread, (void *) 100);assert(rc==0);
	pthread_join(p, (void **) &rvalue);
	printf("returned: %ld\n", rvalue);
	return 0;
}
