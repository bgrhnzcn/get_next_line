/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:42:45 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/24 22:25:56 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strchr(char *str, char c)
{
	if (str == NULL)
		return (NULL);
	while (*str)
		if (*str++ == c)
			return (--str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	size_t			total;
	unsigned char	i;
	unsigned char	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
	}
	total = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(total + 1);
	if (res == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = 0;
	free(s1);
	return (res);
}
