/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:50:56 by ynguyen           #+#    #+#             */
/*   Updated: 2023/02/02 16:03:40 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*ft_buffer(char *save, int fd)
{
	int		check;
	char	*buffer;

	check = 3;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(save, '\n') == 0 && check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[check] = '\0';
		save = ft_stringjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

/*
char	*ft_buffer(char *save, int fd)
{
	int		i;
	char	*buf;

	i = 1;
	if (!save)
		save = ft_calloc(i + 1, 1);
	buf = (char *)malloc((sizeof(char)) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (i > 0 && ft_strchr(buf, '\n') == 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		buf[i] = '\0';
		save = ft_stringjoin(save, buf);
	}
	free(buf);
	return (save);
}
*/

char	*ft_finishline(char *save)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	new = malloc(i + 1);
	new[i] = '\0';
	while (i--)
		new[i] = save[i];
	return (new);
}

char	*ft_saverest(char *save)
{
	char			*temp;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	if (save[i] == '\n')
		i++;
	while (save[i + k] != '\0')
		k++;
	temp = malloc(k + 1);
	if (!temp)
		return (NULL);
	temp[k] = '\0';
	while (k--)
		temp[k] = save[i + k];
	free(save);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*swap;
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	swap = ft_buffer(swap, fd);
	if (swap == NULL)
		return (NULL);
	out = ft_finishline(swap);
	swap = ft_saverest(swap);
	return (out);
}

/*
int	main(void)
{
	int		fd;
	int		i;
	char	*buf;

	i = 1;
	fd = open("hello.txt", O_RDONLY);
	while (i < 10)
		printf("%i: %s\n", i++, get_next_line(fd));
	return (0);
}
*/