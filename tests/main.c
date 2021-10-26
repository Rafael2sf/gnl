/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:23:08 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/26 14:35:53 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	in;
	int	out;
	char	*line;

	line = NULL;
	in = open("../tests/in.txt", O_RDONLY);
	out = open("../tests/out.txt", O_WRONLY);
	while (1)
	{
		line = get_next_line(in);
		if (!line)
			break;
		write(out, line, ft_strlen(line));
		free(line);
	}
	close(in);
	close(out);
}
