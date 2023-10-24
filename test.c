/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:42 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/24 22:28:37 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int i = 0;
	int fd = open("/Users/buozcan/Documents/get_next_line/test.txt",O_RDONLY);
	while (i < 1)
	{
		char *line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	system("leaks --list");
}