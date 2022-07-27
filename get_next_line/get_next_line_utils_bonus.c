/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:51:36 by hvardany          #+#    #+#             */
/*   Updated: 2022/04/15 15:51:39 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
	{
		return (0);
	}
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*sr;
	char	cc;

	cc = (char) c;
	sr = (char *) s;
	while (*sr != '\0')
	{
		if (*sr++ == cc)
		{
			return (--sr);
		}
	}
	if (*sr == cc || cc == 0)
		return (sr);
	return (0);
}

char	*fstrjoin(char *s1, char *s2, char *srtcharxxx)
{
	char	*sm;
	size_t	i;

	i = ft_strlen(s1);
	if (srtcharxxx)
		i += (size_t)((srtcharxxx - s2) + 1);
	else
		i += ft_strlen(s2);
	sm = (char *)malloc(sizeof(char) * (i + 1));
	if (!sm)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		sm[i] = s1[i];
		i++;
	}
	while (s2 && *s2 != '\0' && *s2 != '\n')
		sm[i++] = *s2++;
	if (*s2 == '\n')
		sm[i++] = *s2++;
	sm[i] = '\0';
	free(s1);
	return (sm);
}

char	*newbuf(char *src)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	while (*src != '\0' && *src != '\n')
		src++;
	src++;
	while (src[i] && src[i] != '\0')
		i++;
	if (i > 0)
	{
		k = (char *)malloc((i + 1) * sizeof(char));
		while (*src != '\0')
		{
			k[j] = *src++;
			j++;
		}
		k[j] = '\0';
		return (k);
	}
	return (NULL);
}

char	*gnl(char *s1)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	if (!s1 || *s1 == '\0')
		return (NULL);
	s = (char *) s1;
	while (*s != '\n' && *s++)
		i++;
	if (*s == '\n')
	i++;
	d = malloc(i + 1);
	if (!d)
		return (NULL);
	s = (char *) s1;
	i = 0;
	while (*s != '\n')
		d[i++] = *s++;
	if (*s == '\n')
		d[i++] = '\n';
	d[i] = '\0';
	return (d);
}
