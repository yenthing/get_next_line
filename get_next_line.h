/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:51:44 by ynguyen           #+#    #+#             */
/*   Updated: 2023/02/02 16:01:10 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

char	*ft_buffer(char *save, int fd);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_stringjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_finishline(char *save);

#endif