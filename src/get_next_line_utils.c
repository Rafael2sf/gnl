/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:32:06 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/25 22:02:31 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *)(s);
	while (cp && *cp)
	{
		cp++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (*(src + i))
		{
			if (i >= (dstsize - 1))
				break ;
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
		while (*(src + i))
			i++;
		return (i);
	}
	else
		return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	char	*s;
	char	*d;
	size_t	tmp;

	if (dst && src)
	{
		tmp = siz;
		d = (char *)(dst);
		while (tmp-- && *d)
			d++;
		tmp = siz - (d - dst);
		s = (char *)(src);
		if (tmp == 0)
			return ((d - dst) + ft_strlen(s));
		tmp = (d - dst);
		while (*s)
		{
			if ((siz - (d - dst)) > 1)
				*d++ = *s;
			s++;
		}
		*d = '\0';
		return (tmp + (s - src));
	}
	return (siz);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (NULL);
	while (i < (s1len + s2len + 1))
		ptr[i++] = 0;
	ft_memcpy(ptr, s1, s1len);
	ft_memcpy(ptr + s1len, s2, s2len);
	ptr[s1len + s2len] = '\0';
	return (ptr);	
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		if (len == 0)
			return (NULL);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s, len + 1);
		*(str + len) = '\0';
		return (str);
	}
	return (NULL);
}

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

void	*ft_memcpy(const void *dst, const void *src, size_t n)
{
	char	*dstptr;
	char	*srcptr;

	dstptr = (char *)(dst);
	srcptr = (char *)(src);
	if (dstptr && srcptr)
	{
		while (n--)
			*dstptr++ = *srcptr++;
	}
	return ((void *)dst);
}