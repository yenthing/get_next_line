/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:51:30 by ynguyen           #+#    #+#             */
/*   Updated: 2023/02/02 16:03:30 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_stringjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1 || !s2)
			return (NULL);
		s1[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	while (s1[++i])
		temp[i] = s1[i];
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	free(s1);
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	if (c >= 128)
		c %= 128;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
