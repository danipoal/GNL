#include "test.h"

int	main(void)
{
	int	fd;
	char	*s;

	fd = open("example.txt", O_RDONLY);
	s = get_next_line(fd);

	while (s)
	{
		write(1, s, strlen(s));
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (0);
}
