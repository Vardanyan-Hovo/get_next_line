/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:51:49 by hvardany          #+#    #+#             */
/*   Updated: 2022/04/15 15:51:51 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*fstrjoin(char *s1, char *s2, char *srtcharxxx);
char	*newbuf(char *src);
char	*gnl(char *s1);
char	*fstrdupfree(char *s);
char	*get_next_line_bonus(int fd);

#endif
