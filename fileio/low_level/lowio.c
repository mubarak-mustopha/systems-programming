#include <fcntl.h>
#include <unistd.h>

int main(){
	char buf[1000];
	int fd = open("lowio.c", O_RDONLY);
	ssize_t rd = read(fd, buf, sizeof(buf));
	int err = close(fd);
	ssize_t wr = write(STDOUT_FILENO, buf, rd);
}
