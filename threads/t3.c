#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
} myarg_t;

typedef struct {
	int x;
	int y;
} myret_t;

void *mythread(void *arg){
	myret_t *rvals = (myret_t *) malloc(sizeof(myret_t)); assert ( rvals != NULL );
	rvals->x = 1;
	rvals->y = 2;
	return (void *) rvals;
}

int main(int argc, char *argv[]){
	pthread_t t1;
	myarg_t args = { 10, 25 };
	myret_t *rvals;
	
	assert ( pthread_create(&t1, NULL, mythread, &args) == 0 );
	// wait till thread t1 terminates
	assert ( pthread_join(t1, (void **) &rvals) == 0 );
	printf("returned: %d %d\n", rvals->x, rvals->y);
	
	free(rvals);
	return 0;
}
