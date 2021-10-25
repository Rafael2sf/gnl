/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/25 17:54:56 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if (s)
	{
		tmp = (char *)(s);
		while (*tmp)
		{
			if (*tmp == (char)c)
				return (tmp);
			tmp++;
		}
		if (*tmp == c)
			return (tmp);
	}
	return (NULL);
}

char	*gnl_verify(int fd)
{
	char	*line;

	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	return (line);
}

char	*gnl_get_newline(int fd, char *storage)
{
	char	*tmp;
	
	if (storage)
	{
		tmp = ft_strchr((const char *)storage, '\n');
		// Not found
		if (!tmp)
			return (storage);
		// Found \n
		return (tmp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buf;

	buf = gnl_verify(fd);
	if (!buf)
		return (NULL);
	line = gnl_get_newline(fd, storage);
	return (strdup("END"));
}

int		main(void)
{
	char	*tmp;
	int	fd;

	fd = open("a.txt", O_RDONLY);
	tmp = get_next_line(0);
	printf("%s\n", tmp);
	free(tmp);
	return (0);
}
