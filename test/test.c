/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:15:25 by danalvar          #+#    #+#             */
/*   Updated: 2025/03/19 19:45:52 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	gnl_unit_test(char **s, int fd)
{
	if (*s)
	{
		write(1, *s, strlen(*s));
		free(*s);
		*s = get_next_line(fd);
	}
}

void	test_bonus()
{
	int		fd1, fd2, fd3;
	char	*s1, *s2, *s3;

	fd1 = open("e1.txt", O_RDONLY);
	fd2 = open("e2.txt", O_RDONLY);
	fd3 = open("e3.txt", O_RDONLY);
	
	s1 = get_next_line(fd1);
	s2 = get_next_line(fd2);
	s3 = get_next_line(fd3);
	while (s1 || s2 || s3)
	{
		gnl_unit_test(&s1, fd1);
		gnl_unit_test(&s2, fd2);
		gnl_unit_test(&s3, fd3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
}

int	main(void)
{
	int		fd;
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

	//Bonus
	write(1, "\nBONUS:\n", 8);
	test_bonus();
	return (0);
}
