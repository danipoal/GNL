#include "test.h"

int	main(void)
{
	int	fd;

	fd = open("example.txt", O_RDONLY);
	char s[] = ft_get_next_line(fd);

	write(1, s, ft_strlen(s));
	close(fd);
	return (0);
}
