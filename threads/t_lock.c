# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

#define NTHREADS 20

int common = 162;
pthread_mutex_t common_lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_fun(void *threadid)
{
	long tid = (long) threadid;
	pthread_mutex_lock(&common_lock);
	int my_common = common++;
	pthread_mutex_unlock(&common_lock);
	printf("Thread %lx stack: %lx common: %lx (%d)\n", tid,
		(unsigned long) &tid, (unsigned long) &common, my_common);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	long t;
	int nthreads = NTHREADS;
	if (argc > 1){
		nthreads = atoi(argv[1]);
	}
	pthread_t *threads = (pthread_t *) malloc(nthreads*sizeof(pthread_t));
	printf("Main stack %lx common: %lx (%d)\n", 
		(unsigned long) &t, (unsigned long) &common, common);
	for(t=0; t<nthreads; t++){
		int rc = pthread_create(&threads[t], NULL, thread_fun, (void *) t);
		if (rc){
			printf("Return code from pthread_create() is %d", rc);
			exit(-1);
		}
	}

	for(t=0;t<nthreads;t++){
		pthread_join(threads[t], NULL);
	}
}	
