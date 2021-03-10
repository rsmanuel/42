#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
int	main(int argc, char **args)
{
	int fd;
	int ret;
	char *line;
	fd = open(args[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error when opening file\n");
		return 1;
	}
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		printf("%s\n", line);
		printf("gnl ret: %d\n", ret);
		if (ret == 0)
			break ;
		free(line);
	}
	get_next_line(fd, &line);
	printf("<%s>", line);
	free(line);
	close(fd);
	return 0;
}
