#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>

#define MB (1024*1024)
#define BS 16
#define CHUNK (MB * BS)
#define QUIT_TIME 20

void quit_on_timeout(int sig){
	printf("\n\nTime expired. Quitting\n.");
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv){
	struct sysinfo si;
	int j, m;
	char *c;

	/* get total memory on the system */
	sysinfo(&si);
	m = si.totalram / MB;
	printf("Total System Memory in MB = %d MB\n", m);
	m = (9 * m) / 10;  /* drop 10 percent */
	printf("Using somewhat less: %d MB\n", m);

	if (argc == 2) {
		m = atoi(argv[1]);
		printf("Choosing instead mem = %d MB\n", m);
	}

	signal(SIGALRM, quit_on_timeout);
	printf("Will quit in QUIT_TIME seconds if no normal termination\n");
	alarm(QUIT_TIME);

	for (j = 0; j <= m; j += BS) {
		c = malloc(CHUNK);
		memset(c, j, CHUNK);
		printf("%8d", j);
		fflush(stdout);
	}
	printf("\n\n	Sleeping for 5 seconds\n");
	sleep(5);
	printf("\n\n	Quitting and releasing memory\n");
	exit(EXIT_SUCCESS);
}
