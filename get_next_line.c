/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:34:31 by danalvar          #+#    #+#             */
/*   Updated: 2025/02/14 18:10:38 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/**
 * Gets one line from the buffer recieved, and moves the buffer pointer to the
 * end of the line
 * @param Complete buffer of size given
 * @return Null is buffer is empty or the line
 */
char	*trim_endl(char **buffer)
{
	int	i;
	char const	*buf;

	if (!**buffer)
		return (NULL);
	buf = *buffer;
	i = 0;
	while (buf[i] != '\n' &&  buf[i] != '\0')
		i++;
	i++,			// Para recoger el /n o /0 en la linea y que no se qued estancado
	*buffer += i;	// Seteamos el antiguo buffer estatico al endline
	return (ft_substr(buf, 0, i));
}


/**
 * Function that reads a file until a \n or \0 is found.
 *
 * @param fd As an argument we give a file descriptor prev got with open()
 *
 * @return A buffer with the string of the x line of the file.
 */
char	*get_next_line(int fd)
{
	static char	*buffer;
	int		bytes_readed;
	char	*line;
	static char	*buffer_dir;


	if (!buffer)
	{
		buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer_dir = buffer;			// First time we save mem, remember the true dir of the buffer to free
			bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == 0)
			return (NULL);
	}
	line = trim_endl(&buffer);
	if(!line)
	{
		free(buffer_dir);
		return (NULL);
	}
	return (line);
}
//TODO When the buff ends, if the read get something, coninue looping