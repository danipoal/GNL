#include "test.h"

int	main(void)
{
	int	fd;
	char	*s;

	fd = open("example.txt", O_RDONLY);
	s = get_next_line(fd);

	write(1, s, ft_strlen(s));
	close(fd);
	return (0);
}
