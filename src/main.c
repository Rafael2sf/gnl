/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:23:08 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/25 22:55:25 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{

	/* GNL main 	*/
	char	*tmp;
	int		fd;

	fd = open("main.c", O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		printf("%s", tmp);
		free(tmp);
	}
	close(fd);

/*	gnl_nextline main
		

	char 	*storage;
	char	*ptr;
	char	*line;

	line = NULL,
	storage = (char *)malloc(sizeof(char) * 10);
	ft_strlcpy(storage, "\nabc", 10);
	ptr = ft_strchr(storage, '\n');
	if (ptr)
		line = gnl_getline(&storage, (ptr - storage) + 1);
	printf("l: %s", line);
	printf("s: %s", storage);
*/


/*	gnl_read main 
	char	*storage = NULL;
	char	*buf = NULL;
	char	*line = NULL;
	int		fd;
	ssize_t	j;

	storage = ft_strdup(NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		exit(1);
	fd = open("test.txt", O_RDONLY);
	j = read(fd, buf, BUFFER_SIZE);
	line = gnl_read(&storage, &buf, j);
	printf("%s=", line);
	printf("%s", storage);

*/

/*
	GNL trim main

	char	*storage = ft_strdup(NULL);
	char	*buf = ft_strdup("\n\nabc");
	char	*ptr = ft_strchr(buf, '\n');
	char	*line = gnl_trim(&storage, &buf, (ptr - buf) + 1);
	printf("(%s)(%s)", line, storage);
*/	
	return (0);
}
