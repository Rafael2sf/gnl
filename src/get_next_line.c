/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/25 23:34:29 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

/**
 * !This function seems to be writing to invalid adresses
 * receives the storage containing a new line, copies the line to a buffer,
 * and the remaining to the storage, and assings the returned line to storage
 * @param s storage is guaranted to have a new line
 * @param i total bytes in storage
 * @param n size of line to be removed from storage 
*/
char	*gnl_update(char **s, ssize_t i, ssize_t n)
{
	char	*ptr;

	ptr = NULL;
	if ((i - n) > 0)
	{
		ptr = (char *)malloc(sizeof(i - n + 1));
		if (ptr)
		{
			ptr[i - n] = '\0';
			while ((--i - n) >= 0)
				ptr[i - n] = (*s)[i];
		}
	}
	free(*s);
	return (ptr);
}

/**
 * Allocates enought space for storage + line ended string in buffer,
 * copies the remaining on buffer to storage and returns the new line
 * @param s storage might be empity
 * @param b buffer containing a new line
 * @param len the size of the new line ended string in buffer 
*/
char	*gnl_trim(char **s, char **b, ssize_t len)
{	
	char	*line;
	char	*tmp;
	ssize_t	i;
	
	// !Make this one malloc instead of 2 (strlen storage)
	i = -1;
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	while (++i < len)
		line[i] = (*b)[i];
	line[i] = '\0';
	if (*s)
	{
		tmp = ft_strjoin(*s, line);
		free(line);
		free(*s);
		(*s) = NULL;
		line = tmp;
	}
	// !
	if ((*b)[i])
	{
		tmp = ft_strdup((*b) + len);
		free(*s);
		(*s) = tmp;
	}
	return (line);
}

/**
 * Alocattes n bytes, copis them from s and sends s to gnl_update to 'realloc'
 * @param s storage with newline ended string
 * @param n lenght of newline ended string
 */
char	*gnl_getline(char **s, ssize_t n)
{
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
	while ((*s)[i])
		i++;
	(*s) = gnl_update(s, i, n);
	return (tmp);
}

/**
 * !function too long
 * Checks the result of read and if there is a new line in buf, if so, merge
 * storage + line and returns it, saving the remaining bytes at storage,
 * else merge both at storage
 * @param s storage
 * @param b just read
 * @param i result of read
*/
char	*gnl_read(char **s, char **b, ssize_t i)
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
			if (*s)
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
 * Searchs for a newline in storage if possible, copies line and updates storage
 * else reads BUFFER_SIZE, if new line in buffer, copies line and updates storage,
 * else update storage and repeats previous step in a loop
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
	// !This call seems to be reading from invalid adress
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

