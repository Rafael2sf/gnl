/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/26 12:01:35 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**s
 * @param s storage might be empity
 * @param b buffer containing a new line
 * @param len the size of the new line-ended string in buffer 
*/
static char	*gnl_trim(char **s, char **b, ssize_t len)
{	
	char	*line;
	char	*tmp;
	ssize_t	i;

	i = ft_strlen(*s);
	line = (char *)malloc(sizeof(char) * len + i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *s, i);
	ft_memcpy(line + i, *b, len);
	line[i + len] = '\0';
	tmp = ft_strdup((*b) + len);
	if (*s)
		free(*s);
	(*s) = tmp;
	return (line);
}

/**
 */
char	*gnl_getline(char **s, ssize_t n)
{
	char	*ptr;
	char	*tmp;
	ssize_t	i;

	if (n < 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (n + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i != n)
		tmp[i] = (*s)[i];
	tmp[i] = '\0';
	ptr = ft_strdup(*s + i);
	free(*s);
	(*s) = ptr;
	return (tmp);
}

/**
 * @param s storage
 * @param b just read
 * @param i result of read
*/
static char	*gnl_read(char **s, char **b, ssize_t i)
{
	char	*ptr;
	char	*tmp;

	ptr = NULL;
	if (i == -1)
		return (NULL);
	if (i == 0)
	{
		if (*s)
		{
			ptr = ft_strdup(*s);
			free(*s);
			(*s) = NULL;
		}
		return (ptr);
	}
	(*b)[i] = '\0';
	tmp = ft_strchr(*b, '\n');
	if (tmp)
		ptr = gnl_trim(s, b, (tmp - *b) + 1);
	else
	{
		tmp = ft_strjoin(*s, *b);
		if (*s)
			free(*s);
		(*s) = tmp;
	}
	return (ptr);
}

/**
 * @param fd file descriptor to read from
 * @param return next line in fd
 */
char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;
	char		*buf;
	ssize_t		i;

	i = 1;
	line = NULL;
	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_strchr(storage[fd], '\n');
	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		while (line == NULL && i > 0)
		{
			i = read(fd, buf, BUFFER_SIZE);
			line = gnl_read(&storage[fd], &buf, i);
		}
		free(buf);
		return (line);
	}
	line = gnl_getline(&storage[fd], (buf - storage[fd]) + 1);
	return (line);
}