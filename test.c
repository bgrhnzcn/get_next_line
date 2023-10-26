/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:42 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/26 16:21:56 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int i = 0;
	int fd = open("test.txt" ,O_RDONLY);
	while (i < 1)
	{
		char *line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
}