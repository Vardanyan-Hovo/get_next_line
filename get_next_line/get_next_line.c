/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:36:55 by hvardany          #+#    #+#             */
/*   Updated: 2022/04/14 19:46:04 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*fstrdupfree(char *s)
{
	char	*d;
	char	*k;
	int		i;

	if (!s || *s == '\0')
		return (NULL);
	k = s;
	while (*s++ != '\n')
		;
	if (!*s)
	{
		free(k);
		return (NULL);
	}
	d = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (*s != '\0')
		d[i++] = *s++;
	d[i] = '\0';
	free(k);
	return (d);
}

char	*norminet(char *s, int fd, char **k, int *bytes)
{
	int		i;
	char	src[BUFFER_SIZE + 1];

	i = *bytes;
	i = read(fd, src, BUFFER_SIZE);
	if (i < 0)
		return (NULL);
	else if (i == 0)
		return (s);
	src[i] = '\0';
	while (i && !ft_strchr(src, '\n'))
	{
		s = fstrjoin(s, src, 0);
		i = read(fd, src, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		src[i] = '\0';
	}
	if (i && ft_strchr(src, '\n'))
	{
		s = fstrjoin(s, src, ft_strchr(src, '\n'));
		*k = newbuf(src);
	}
	*bytes = i;
	return (s);
}

char	*get_next_line(int fd)
{
	char		*s;
	int			i;
	static char	*k;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s = 0;
	if (k && ft_strchr(k, '\n'))
	{
		s = get_next_line_utils(k);
		k = fstrdupfree(k);
	}
	else
	{
		i = 0;
		if (k)
		{
			s = k;
			k = 0;
		}
		s = norminet(s, fd, &k, &i);
	}
	if (!s)
		return (NULL);
	return (s);
}
