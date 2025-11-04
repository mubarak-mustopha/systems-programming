#include <stdio.h>
#include <pthread.h>
#include <assert.h>

typedef struct {
	int a;
	int b;
} myarg_t;

void *mythread(void *arg){
	myarg_t *args = (myarg_t *) arg;
	printf("%d %d\n", args->a, args->b);
	return NULL;
}

int main(int argc, char *argv[]){
	pthread_t t1;
	myarg_t args = { 10, 25 };
	
	assert ( pthread_create(&t1, NULL, mythread, &args) == 0 );
	// wait till thread t1 terminates
	assert ( pthread_join(t1, NULL) == 0 );

	return 0;
}
