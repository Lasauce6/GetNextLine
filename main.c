#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	char *line;
	int fd = open("test", O_RDONLY);

	line = get_next_line(0);
	if (line) {
		write(1, line, strlen(line));
		free(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		write(1, line, strlen(line));
		free(line);
	}
	line = get_next_line(6);
	line = get_next_line(0);
	if (line)
	{
		write(1, line, strlen(line));
		free(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		write(1, line, strlen(line));
		free(line);
	}
	line = get_next_line(-21);
	close (fd);
}
