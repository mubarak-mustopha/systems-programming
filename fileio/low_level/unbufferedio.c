#include <unistd.h>

int main(){
	write(STDOUT_FILENO, "Beginning of line ", 18);
	sleep(10);
	write(STDOUT_FILENO, "and end of line \n", 16);
}
