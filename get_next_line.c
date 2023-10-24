/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:47:14 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/24 22:30:47 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*refill(int fd, char *buffer)
{
	char	*temp;
	int		byte_readed;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	byte_readed = 1;
	while (!ft_strchr(buffer, '\n') && byte_readed)
	{
		byte_readed = read(fd, temp, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[byte_readed] = 0;
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		res[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = refill(fd, buffer);
	line = get_line(buffer);
	buffer = cut_line(buffer, ft_strlen(line));
	return (line);
}

char	*cut_line(char *buffer, int len)
{
	char	*temp;
	int		i;

	if (buffer[len] == 0)
	{
		free(buffer);
		return (NULL);
	}
	temp = malloc((ft_strlen(buffer) - len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (buffer[len] && buffer[len] != '\n')
		temp[i++] = buffer[len++];
	temp[i] = 0;
	free(buffer);
	return (temp);
}
