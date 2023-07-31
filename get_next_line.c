/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:55:03 by ddutta            #+#    #+#             */
/*   Updated: 2023/07/31 20:33:24 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	*fullbuffer;
	char lbuffer[BUFFER_SIZE + 1];
	char *line;
	ssize_t		size;

	lbuffer[0] = '\0';
	while (ft_strchr(lbuffer, '\n') == NULL)
	{
		size = read(fd, lbuffer, BUFFER_SIZE);
		// <insert> logic for size = 0 & -1
		lbuffer[size] = '\0';
		fullbuffer = ft_strjoin(fullbuffer, lbuffer);
	}

	// We're guaranteed to either have at least a one line in the buffer or end of file.
	//extract
	//	copy first line from fullbuffer
	//	remove first line from fullbuffer
	
	// return copied first line
}
