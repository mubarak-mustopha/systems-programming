#include <stdio.h>
#include <pthread.h>
#include <assert.h>

static volatile int counter = 0;

void *mythread(void *arg){
	printf("%s: begin\n", (char *) arg);
	int i;
	for (i = 0; i < 1e7; i++){
		counter = counter + 1;
	}
	printf("%s: end\n", (char *) arg);
	return NULL;
}

int main(int argc, char *argv[]){
	pthread_t t1, t2;
	printf("main: begin (counter: %d)\n", counter);

	int rc;
	rc = pthread_create(&t1, NULL, mythread, "A"); assert (rc == 0);
	rc = pthread_create(&t2, NULL, mythread, "B"); assert (rc == 0);

	// join waits for threads to finish
	rc = pthread_join(t1, NULL); assert (rc == 0);
	rc = pthread_join(t2, NULL); assert (rc == 0);	

	printf("main: done with both (counter: %d)\n", 
		counter);
	return 0;
}
