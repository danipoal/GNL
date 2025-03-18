/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:34:31 by danalvar          #+#    #+#             */
/*   Updated: 2025/03/18 15:07:15 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_buffjoin(char **buffer, char *tmp_buffer)
{
	char	*tmp;

	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, tmp_buffer);
	if (tmp)
		free(tmp);
}

static void	ft_next_line(char **buffer)
{
	char	*tmp;
	int		i;

	tmp = *buffer;
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	*buffer = ft_substr(*buffer, i, ft_strlen(*buffer) - i);
	free(tmp);
}

static char	*ft_get_line(char **buffer)
{
	int	i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	return (ft_substr(*buffer, 0, i));
}

static void	ft_read(int fd, char **buffer)
{
	char	*tmp_buffer;
	int		read_bytes;

	tmp_buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return ;
	*tmp_buffer = '\0';
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(tmp_buffer, '\n'))
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(tmp_buffer);
			return ;
		}
		tmp_buffer[read_bytes] = '\0';
		ft_buffjoin(buffer, tmp_buffer);
	}
	free(tmp_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	ft_read(fd, &buffer[fd]);
	if (!buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	line = ft_get_line(&buffer[fd]);
	if (!line)
		return (NULL);
	ft_next_line(&buffer[fd]);
	return (line);
}
