/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:43:37 by hvardany          #+#    #+#             */
/*   Updated: 2022/04/14 20:18:16 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*fstrjoin(char *s1, char *s2, char *srtcharxxx);
char	*newbuf(char *src);
char	*get_next_line_utils(const char *s1);
char	*fstrdupfree(char *s);
char	*get_next_line(int fd);

#endif
