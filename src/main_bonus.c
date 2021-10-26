/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:23:08 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/26 12:08:59 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*tmp;
	int		fd;
	int		fd2;

	fd = open("../tests/f1.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	fd2 = open("../tests/f2.txt", O_RDONLY);
	if (fd2 == -1)
		return (1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		printf("%s", tmp);
		free(tmp);
		tmp = get_next_line(fd2);
		if (!tmp)
			break ;
		printf("%s", tmp);
		free(tmp);
	}
	close(fd);
	return (0);
}
