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



/*
 * s1 is buffer
 * s2 is tmp
*/
char	*buffer_join(char *s1, char *s2)
{
	char	*new_buffer;

	if (!s1)
		s1 = ft_strdup("");
	new_buffer = ft_strjoin(s1, s2);	//TODO Aqui si n se hace en la funcion exterior tmbn free
	return (new_buffer);
}

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
 * Function that reads a file until a \n or \0 is found or Buff ends
 *
 * @param fd As an argument we give a file descriptor prev got with open()
 *
 * @return A buffer with the string of the x line of the file.
 */
char	**ft_read(int fd, char **buffer)
{
	char	*tmp_buff;
	char	*buff_dir;
	char	*ss;
	size_t	bytes_readed;

	tmp_buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buff)
		return (NULL);
	bytes_readed = 1;
	
	// Aqui hay que ir leyendo todo el rato hasta que bytes readed < 0 o se encuentre '\n'
	while (bytes_readed > 0 && !ft_strchr(*buffer, '\n'))
	{
		bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
		tmp_buff[BUFFER_SIZE] = '\0';
		buff_dir = *buffer;
		*buffer = buffer_join(*buffer, tmp_buff);	//TODO Aqui creo que se deberia hacer un free del buffer original
		//free(buff_dir);
	}
	free(tmp_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	
	ft_read(fd, &buffer);
	line = trim_endl(&buffer);
	if (!line)
		return (NULL);
	return (line);
}