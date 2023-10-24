/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:47:38 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/24 22:13:43 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
char	*get_next_line(int fd);
char	*refill(int fd, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char 	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);
char	*get_line(char *buffer);
char	*cut_line(char *buffer, int len);
#endif